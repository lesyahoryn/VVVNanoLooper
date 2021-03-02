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
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_tau21");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_tau32");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_loose_tau21");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_medium_tau21");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_tight_tau21");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_msoftdrop");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_loose_msoftdrop");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_medium_msoftdrop");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_tight_msoftdrop");
    ana.tx.createBranch<vector<int>>    ("allHad_FatJet_WP");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_pt");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_M");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_eta");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_phi");
    ana.tx.createBranch<vector<LorentzVector>>  ("allHad_FatJet_p4");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_loose_Wtag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_medium_Wtag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_tight_Wtag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_loose_Ztag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_medium_Ztag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_tight_Ztag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_loose_Ttag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_medium_Ttag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_tight_Ttag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_loose_Zbbtag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_medium_Zbbtag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_tight_Zbbtag");
    
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_Zbbtag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_Ztag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_Ttag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_Wtag");
    
    ana.tx.createBranch<vector<float>>  ("allHad_Jet_pt");
    ana.tx.createBranch<vector<float>>  ("allHad_Jet_eta");
    ana.tx.createBranch<vector<float>>  ("allHad_Jet_phi");
    ana.tx.createBranch<vector<float>>  ("allHad_gen_vvvdecay_pdgid"); // for now these need to be floats bc addVecHistogram doesn't take ints
    ana.tx.createBranch<vector<float>>  ("allHad_gen_vvvdecay_pt"); 
    ana.tx.createBranch<vector<float>>  ("allHad_gen_vvv_pt"); 
    ana.tx.createBranch<vector<float>>  ("allHad_gen_pdgId");
    
    
    // Single var branches
    ana.tx.createBranch<float>  ("allHad_MET");
    ana.tx.createBranch<float>  ("allHad_genHT");
    ana.tx.createBranch<float>  ("allHad_HT");
    ana.tx.createBranch<float>  ("allHad_ST");
    ana.tx.createBranch<float>  ("allHad_mVVV");
    ana.tx.createBranch<float>  ("allHad_mVVV_reco");
    ana.tx.createBranch<int>  ("allHad_FatJet_n_loose");
    ana.tx.createBranch<int>  ("allHad_FatJet_n_medium");
    ana.tx.createBranch<int>  ("allHad_FatJet_n_tight");

    // Define selections
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    // Create histograms used in this category.
    // Please follow the convention of h_<category>_<varname> structure.
    // N.B. Using nbins of size 180 or 360 can provide flexibility as it can be rebinned easily, as 180, 360 are highly composite numbers.
    
    // Super basic selection for now -- 0 leptons and some jets
    ana.cutflow.getCut("CommonCut");
    ana.cutflow.addCutToLastActiveCut("allHad", [&]() { 
        for (int i=0; i < ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_pdgid").size(); i++){
            int pdgId = ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_pdgid")[i]; 
            if( abs(pdgId) == 11 || abs(pdgId) == 13 || abs(pdgId) == 15)
                return false;
        }

        if( (ana.tx.getBranchLazy<vector<float>>("allHad_Jet_pt").size() + ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_pt").size()) < 1) return false; 
             
        return true;
        
        }, [&]() { return 1; } );
    
    RooUtil::Histograms hists_allHad;

    //single value histograms
    hists_allHad.addHistogram("NJets"            ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<vector<float>>("allHad_Jet_pt").size()    ; } );
    hists_allHad.addHistogram("NLeps"            ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid").size()   ; } );
    hists_allHad.addHistogram("NFatJets"         ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_pt").size() ; } );
    hists_allHad.addHistogram("NW"               ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("Common_n_W") ; } );
    hists_allHad.addHistogram("gen_vvvdecay_n"               ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_idx").size() ; } );
    hists_allHad.addHistogram("n_b_loose"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("Common_nb_loose") ; } );
    hists_allHad.addHistogram("n_b_medium"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("Common_nb_medium") ; } );
    hists_allHad.addHistogram("n_b_tight"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("Common_nb_tight") ; } );
    hists_allHad.addHistogram("MET"              ,  40,   0,    2000, [&]() { return    ana.tx.getBranch<float>  ("allHad_MET"); } );
    hists_allHad.addHistogram("genHT"            ,  40,   0,    2000, [&]() { return    ana.tx.getBranch<float>  ("allHad_genHT"); } );
    hists_allHad.addHistogram("HT"               ,  40,   0,    2000, [&]() { return    ana.tx.getBranch<float>  ("allHad_HT"); } );
    hists_allHad.addHistogram("ST"               ,  40,   0,    2000, [&]() { return    ana.tx.getBranch<float>  ("allHad_ST"); } );
    hists_allHad.addHistogram("mVVV"               ,  60,   0,    5000, [&]() { return    ana.tx.getBranch<float>  ("allHad_mVVV"); } );
    hists_allHad.addHistogram("mVVV_reco"               ,  60,   0,    5000, [&]() { return    ana.tx.getBranch<float>  ("allHad_mVVV_reco"); } );
    
    hists_allHad.add2DHistogram("mVVV", 60,   0,    3000, "MET", 40,   0,    2000, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV");}, [&]() { return ana.tx.getBranch<float>  ("allHad_MET"); } );
    hists_allHad.add2DHistogram("mVVV_reco", 60,   0,    3000, "MET", 40,   0,    2000, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_MET"); } );
    hists_allHad.add2DHistogram("mVVV", 60,   0,    3000, "HT", 60,   0,    3000, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV");}, [&]() { return ana.tx.getBranch<float>  ("allHad_HT"); } );
    hists_allHad.add2DHistogram("mVVV_reco", 60,   0,    3000, "HT", 60,   0,    3000, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_HT"); } );
    hists_allHad.add2DHistogram("mVVV", 60,   0,    3000, "ST", 60,   0,    3000, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV");}, [&]() { return ana.tx.getBranch<float>  ("allHad_ST"); } );
    hists_allHad.add2DHistogram("mVVV_reco", 60,   0,    3000, "ST", 60,   0,    3000, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_ST"); } );
    hists_allHad.add2DHistogram("mVVV", 60,   0,    3000, "mVVV_reco", 60,   0,    3000, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV");}, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV_reco"); } );
    hists_allHad.add2DHistogram("genHT", 60,   0,    3000, "HT", 40,   0,    3000, [&]() { return ana.tx.getBranch<float>  ("allHad_genHT");}, [&]() { return ana.tx.getBranch<float>  ("allHad_HT"); } );
    hists_allHad.add2DHistogram("Njets", 6,   0,    6, "NFatjets", 6,   0,    6, [&]() { return ana.tx.getBranchLazy<vector<float>>("allHad_Jet_pt").size();}, [&]() { return ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_pt").size(); } );
    
    hists_allHad.addHistogram("MET_mVVVg1000"              ,  40,   0,    2000, [&]() { return    (ana.tx.getBranch<float>  ("allHad_mVVV") > 1000) ? ana.tx.getBranch<float>  ("allHad_MET") : -999; } );
    hists_allHad.addHistogram("MET_mVVVg2000"              ,  40,   0,    2000, [&]() { return    (ana.tx.getBranch<float>  ("allHad_mVVV") > 2000) ? ana.tx.getBranch<float>  ("allHad_MET") : -999; } );
    hists_allHad.addHistogram("MET_mVVVg3000"              ,  40,   0,    2000, [&]() { return    (ana.tx.getBranch<float>  ("allHad_mVVV") > 3000) ? ana.tx.getBranch<float>  ("allHad_MET") : -999; } );
    hists_allHad.addHistogram("MET_mVVVg4000"              ,  40,   0,    2000, [&]() { return    (ana.tx.getBranch<float>  ("allHad_mVVV") > 4000) ? ana.tx.getBranch<float>  ("allHad_MET") : -999; } );
    
    hists_allHad.addHistogram("HT_mVVVg1000"              ,  40,   0,    2000, [&]() { return    (ana.tx.getBranch<float>  ("allHad_mVVV") > 1000) ? ana.tx.getBranch<float>  ("allHad_HT") : -999; } );
    hists_allHad.addHistogram("HT_mVVVg2000"              ,  40,   0,    2000, [&]() { return    (ana.tx.getBranch<float>  ("allHad_mVVV") > 2000) ? ana.tx.getBranch<float>  ("allHad_HT") : -999; } );
    hists_allHad.addHistogram("HT_mVVVg3000"              ,  40,   0,    2000, [&]() { return    (ana.tx.getBranch<float>  ("allHad_mVVV") > 3000) ? ana.tx.getBranch<float>  ("allHad_HT") : -999; } );
    hists_allHad.addHistogram("HT_mVVVg4000"              ,  40,   0,    2000, [&]() { return    (ana.tx.getBranch<float>  ("allHad_mVVV") > 4000) ? ana.tx.getBranch<float>  ("allHad_HT") : -999; } );


    hists_allHad.addHistogram("FatJet_n_loose"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_FatJet_n_loose") ; } );
    hists_allHad.addHistogram("FatJet_n_medium"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_FatJet_n_medium") ; } );
    hists_allHad.addHistogram("FatJet_n_tight"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_FatJet_n_tight") ; } );
    
    hists_allHad.addHistogram("FatJet_pt_0"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_pt")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_pt_1"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_pt")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_pt_2"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_pt")[2] : -999 ; } );
    hists_allHad.addHistogram("FatJet_pt_3"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 3) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_pt")[3] : -999; } );
    
    hists_allHad.addHistogram("FatJet_M_0"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_M").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_M")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_M_1"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_M").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_M")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_M_2"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_M").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_M")[2] : -999 ; } );
    hists_allHad.addHistogram("FatJet_M_3"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_M").size() > 3) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_M")[3] : -999; } );
    
    hists_allHad.addHistogram("Jet_pt_0"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_pt").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_Jet_pt")[0] : -999 ; } );
    hists_allHad.addHistogram("Jet_pt_1"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_pt").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_Jet_pt")[1] : -999 ; } );
    hists_allHad.addHistogram("Jet_pt_2"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_pt").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_Jet_pt")[2] : -999 ; } );
    hists_allHad.addHistogram("Jet_pt_3"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_pt").size() > 3) ? ana.tx.getBranch<vector<float>>("allHad_Jet_pt")[3] : -999; } );
    hists_allHad.addHistogram("Jet_pt_4"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_pt").size() > 4) ? ana.tx.getBranch<vector<float>>("allHad_Jet_pt")[4] : -999; } );
    hists_allHad.addHistogram("Jet_pt_5"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_pt").size() > 5) ? ana.tx.getBranch<vector<float>>("allHad_Jet_pt")[5] : -999; } );
    
     
    hists_allHad.addVecHistogram("FatJet_loose_tau21"       ,  30,   0,    1,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_loose_tau21"); } );
    hists_allHad.addVecHistogram("FatJet_medium_tau21"       ,  30,   0,    1,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_medium_tau21"); } );
    hists_allHad.addVecHistogram("FatJet_tight_tau21"       ,  30,   0,    1,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_tight_tau21"); } );
    
    hists_allHad.addVecHistogram("FatJet_loose_msoftdrop"       ,  30,   0,   200,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_loose_msoftdrop"); } );
    hists_allHad.addVecHistogram("FatJet_medium_msoftdrop"       ,  30,   0,    200,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_medium_msoftdrop"); } );
    hists_allHad.addVecHistogram("FatJet_tight_msoftdrop"       ,  30,   0,    200,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_tight_msoftdrop"); } );
    
    hists_allHad.addVecHistogram("FatJet_loose_Wtag"       ,  30,   0,    1,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_loose_Wtag"); } );
    hists_allHad.addVecHistogram("FatJet_medium_Wtag"       ,  30,   0,    1,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_medium_Wtag"); } );
    hists_allHad.addVecHistogram("FatJet_tight_Wtag"       ,  30,   0,    1,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_tight_Wtag"); } );
    
    hists_allHad.addVecHistogram("FatJet_loose_Ztag"       ,  30,   0,    1,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_loose_Ztag"); } );
    hists_allHad.addVecHistogram("FatJet_medium_Ztag"       ,  30,   0,    1,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_medium_Ztag"); } );
    hists_allHad.addVecHistogram("FatJet_tight_Ztag"       ,  30,   0,    1,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_tight_Ztag"); } );
    
    hists_allHad.addVecHistogram("FatJet_loose_Zbbtag"       ,  30,   0,    1,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_loose_Zbbtag"); } );
    hists_allHad.addVecHistogram("FatJet_medium_Zbbtag"       ,  30,   0,    1,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_medium_Zbbtag"); } );
    hists_allHad.addVecHistogram("FatJet_tight_Zbbtag"       ,  30,   0,    1,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_tight_Zbbtag"); } );
    
    hists_allHad.addVecHistogram("FatJet_loose_Ttag"       ,  30,   0,    1,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_loose_Ttag"); } );
    hists_allHad.addVecHistogram("FatJet_medium_Ttag"       ,  30,   0,    1,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_medium_Ttag"); } );
    hists_allHad.addVecHistogram("FatJet_tight_Ttag"       ,  30,   0,    1,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_tight_Ttag"); } );
    
    //histograms from vector branches
    
    hists_allHad.addVecHistogram("gen_vvvdecay_pdgid"       ,  20,   0,    20,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_gen_vvvdecay_pdgid"); } );
    hists_allHad.addVecHistogram("gen_vvvdecay_pt"       ,  20,   0,    2000,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_gen_vvvdecay_pt"); } );
    hists_allHad.addVecHistogram("gen_vvv_pt"       ,  20,   0,    2000,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_gen_vvv_pt"); } );
    hists_allHad.addVecHistogram("gen_pdgid"       ,  20,   0,    20,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_gen_pdgId"); } );
    hists_allHad.addVecHistogram("FatJet_tau21"       ,  30,   0,    1,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_tau21"); } );
    hists_allHad.addVecHistogram("FatJet_tau32"       ,  30,   0,    1,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_tau32"); } );
    hists_allHad.addVecHistogram("FatJet_msoftdrop"       ,  30,   0,    200,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_msoftdrop"); } );
    hists_allHad.addVecHistogram("FatJet_pt"     ,  40,   0,    2000, [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_pt"); } );
    hists_allHad.addVecHistogram("FatJet_eta"    ,  20,   -5,   5, [&]() { return         ana.tx.getBranch<vector<float>>  ("allHad_FatJet_eta"); } );
    hists_allHad.addVecHistogram("FatJet_phi"    ,  20,   -4,   4, [&]() { return         ana.tx.getBranch<vector<float>>  ("allHad_FatJet_phi"); } );
    hists_allHad.addVecHistogram("FatJet_M"    ,  40,   0,   1000, [&]() { return         ana.tx.getBranch<vector<float>>  ("allHad_FatJet_M"); } );
    hists_allHad.addVecHistogram("Jet_pt"     ,  40,   0,    2000, [&]() { return         ana.tx.getBranch<vector<float>>  ("allHad_Jet_pt"); } );
    hists_allHad.addVecHistogram("Jet_eta"    ,  20,   -5,   5, [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_Jet_eta"); } );
    hists_allHad.addVecHistogram("Jet_phi"    ,  20,   -4,   4, [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_Jet_phi"); } );
   
    ana.cutflow.bookCutflows(); 
    
    ana.cutflow.bookHistogramsForCut(hists_allHad, "allHad");
    //ana.cutflow.bookHistogramsForCut(hists_allHad, "allHad_smallHT");
    //ana.cutflow.bookHistogramsForCut(hists_allHad, "allHad_0l");
}
