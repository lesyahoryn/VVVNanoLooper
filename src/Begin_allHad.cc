#include "Begin_allHad.h"

void Begin_allHad()
{
    //==============================================
    // Begin_allHad:
    // This function gets called prior to the event looping.
    // This is where one declares variables, histograms, event selections for the category allHad.
    //==============================================

    // Create variables used in this category.
    // Please follow the convention of <category>_<varname> structure.
    ana.tx.createBranch<int>("allHad_intVar1");
    ana.tx.createBranch<float>("allHad_floatVar1");
    ana.tx.createBranch<LorentzVector>("allHad_LVVar1");

    // Define selections
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    ana.cutflow.getCut("CommonCut");
    ana.cutflow.addCutToLastActiveCut("Cut_allHad_Preselection", [&]() { return ana.tx.getBranch<LorentzVector>("allHad_LVVar1").pt() > 25.;}, [&]() { return ana.tx.getBranch<float>("allHad_floatVar1"); } );

    // Create histograms used in this category.
    // Please follow the convention of h_<category>_<varname> structure.
    // N.B. Using nbins of size 180 or 360 can provide flexibility as it can be rebinned easily, as 180, 360 are highly composite numbers.
    RooUtil::Histograms hists_allHad;
    hists_allHad.addHistogram("h_allHad_intVar1", 10, 0, 10, [&]() { return ana.tx.getBranch<int>("allHad_intVar1"); } );
    hists_allHad.addHistogram("h_allHad_floatVar1", 180, 0, 500, [&]() { return ana.tx.getBranch<float>("allHad_floatVar1"); } );
    hists_allHad.addHistogram("h_allHad_LVVar1_Pt", 180, 0, 150, [&]() { return ana.tx.getBranch<LorentzVector>("allHad_LVVar1").pt(); } );

    // Now book cutflow histogram (could be commented out if user does not want.)
    // N.B. Cutflow histogramming can be CPU consuming.
    ana.cutflow.bookCutflows();

    // Book histograms to cuts that user wants for this category.
    ana.cutflow.bookHistogramsForCut(hists_allHad, "Cut_allHad_Preselection");
}
