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
    // These are all filled in Process_allHad.cc
    
    //vector branches
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_tau12");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_pt");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_eta");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_phi");
    ana.tx.createBranch<vector<float>>  ("allHad_Jet_pt");
    ana.tx.createBranch<vector<float>>  ("allHad_Jet_eta");
    ana.tx.createBranch<vector<float>>  ("allHad_Jet_phi");
    ana.tx.createBranch<vector<float>>    ("allHad_gen_vvvdecay_pdgid");
    
    // Single var branches
    ana.tx.createBranch<float>  ("allHad_MET");
    ana.tx.createBranch<float>  ("allHad_genHT");

    // Define selections
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    // Create histograms used in this category.
    // Please follow the convention of h_<category>_<varname> structure.
    // N.B. Using nbins of size 180 or 360 can provide flexibility as it can be rebinned easily, as 180, 360 are highly composite numbers.
    
    // Super basic selection for now -- 0 leptons and some jets
    ana.cutflow.getCut("CommonCut");
    ana.cutflow.addCutToLastActiveCut("allHad", [&]() { 
       if(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid").size() > 0) return false;
       if(ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs").size() < 1) return false;
       return true;
        }, [&]() { return 1; } );
    
    /*
    ana.cutflow.addCutToLastActiveCut("allHad_1fj", [&](){
        if( ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() > 0) return true;
        return false;
    }, [&]() {return 1;} );
    */
    // Now book cutflow histogram (could be commented out if user does not want.)
    // N.B. Cutflow histogramming can be CPU consuming.
//    ana.cutflow.bookCutflows();

    // Book histograms to cuts that user wants for this category.
 ///   ana.cutflow.bookHistogramsForCut(hists_allHad, "Cut_allHad_Preselection");
    RooUtil::Histograms hists_allHad;

    //single value histograms
    hists_allHad.addHistogram("NJets"            ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs").size()    ; } );
    hists_allHad.addHistogram("NLeps"            ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid").size()   ; } );
    hists_allHad.addHistogram("NFatJets"         ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() ; } );
    hists_allHad.addHistogram("NW"               ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("Common_n_W") ; } );
    hists_allHad.addHistogram("gen_vvvdecay_n"               ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_idx").size() ; } );
    hists_allHad.addHistogram("n_b_loose"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("Common_nb_loose") ; } );
    hists_allHad.addHistogram("n_b_medium"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("Common_nb_medium") ; } );
    hists_allHad.addHistogram("n_b_tight"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("Common_nb_tight") ; } );
    hists_allHad.addHistogram("MET"              ,  40,   0,    2000, [&]() { return    ana.tx.getBranch<float>  ("allHad_MET"); } );
    hists_allHad.addHistogram("genHT"            ,  40,   0,    2000, [&]() { return    ana.tx.getBranch<float>  ("allHad_genHT"); } );
    //hists_allHad.addHistogram("leadJetPt"         ,  40,   0,    2000, [&]() { return    ana.tx.getBranch<float>  ("allHad_Jet_pt")[0]; } );
    
    //histograms from vector branches
    
    hists_allHad.addVecHistogram("gen_vvvdecay_pdgid"       ,  20,   0,    20,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_gen_vvvdecay_pdgid"); } );
    hists_allHad.addVecHistogram("FatJet_tau12"       ,  20,   0,    1,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_tau12"); } );
    hists_allHad.addVecHistogram("FatJet_pt"     ,  40,   0,    2000, [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_pt"); } );
    hists_allHad.addVecHistogram("FatJet_eta"    ,  20,   -5,   5, [&]() { return         ana.tx.getBranch<vector<float>>  ("allHad_FatJet_eta"); } );
    hists_allHad.addVecHistogram("FatJet_phi"    ,  20,   -4,   4, [&]() { return         ana.tx.getBranch<vector<float>>  ("allHad_FatJet_phi"); } );
    hists_allHad.addVecHistogram("Jet_pt"     ,  40,   0,    2000, [&]() { return         ana.tx.getBranch<vector<float>>  ("allHad_Jet_pt"); } );
    hists_allHad.addVecHistogram("Jet_eta"    ,  20,   -5,   5, [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_Jet_eta"); } );
    hists_allHad.addVecHistogram("Jet_phi"    ,  20,   -4,   4, [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_Jet_phi"); } );
   
    ana.cutflow.bookCutflows(); 
    
    ana.cutflow.bookHistogramsForCut(hists_allHad, "allHad");
}
