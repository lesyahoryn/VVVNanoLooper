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
    ana.tx.createBranch<int>  ("allHad_Njets"                 );
    ana.tx.createBranch<int>  ("allHad_Nleps"                 );

    // Define selections
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    // Create histograms used in this category.
    // Please follow the convention of h_<category>_<varname> structure.
    // N.B. Using nbins of size 180 or 360 can provide flexibility as it can be rebinned easily, as 180, 360 are highly composite numbers.
    ana.cutflow.getCut("CommonCut");
    ana.cutflow.addCutToLastActiveCut("allHad", [&]() { return 1;}, [&]() { return 1; } );

    // Now book cutflow histogram (could be commented out if user does not want.)
    // N.B. Cutflow histogramming can be CPU consuming.
//    ana.cutflow.bookCutflows();

    // Book histograms to cuts that user wants for this category.
 ///   ana.cutflow.bookHistogramsForCut(hists_allHad, "Cut_allHad_Preselection");
    RooUtil::Histograms hists_allHad;
    hists_allHad.addHistogram("Njets"        ,  10,   0,    10, [&]() { return      ana.tx.getBranch<int>  ("allHad_Njets"                   )   ; } );
    hists_allHad.addHistogram("Nleps"        ,  10,   0,    10, [&]() { return      ana.tx.getBranch<int>  ("allHad_Nleps"                   )   ; } );
    
    ana.cutflow.bookHistogramsForCut(hists_allHad, "allHad");
}
