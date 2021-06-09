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
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_tau1");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_tau2");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_tau3");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_tau21");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_tau32");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_msoftdrop");
    ana.tx.createBranch<vector<int>>    ("allHad_FatJet_WP");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_pt");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_M");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_eta");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_phi");
    ana.tx.createBranch<vector<LorentzVector>>  ("allHad_FatJet_p4");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_ID");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_Zbbtag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_Ztag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_Ttag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_Wtag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_subjet0_pt");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_subjet0_eta");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_subjet0_phi");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_subjet0_mass");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_subjet0_btag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_subjet1_pt");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_subjet1_eta");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_subjet1_phi");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_subjet1_mass");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_subjet1_btag");
    
    ana.tx.createBranch<vector<float>>  ("allHad_Jet_pt");
    ana.tx.createBranch<vector<float>>  ("allHad_Jet_eta");
    ana.tx.createBranch<vector<float>>  ("allHad_Jet_phi");
    ana.tx.createBranch<vector<float>>  ("allHad_Jet_ID");
    ana.tx.createBranch<vector<float>>  ("allHad_Jet_puid");
    ana.tx.createBranch<vector<float>>  ("allHad_gen_vvvdecay_pdgid"); // for now these need to be floats bc addVecHistogram doesn't take ints
    ana.tx.createBranch<vector<float>>  ("allHad_gen_vvvdecay_pt"); 
    ana.tx.createBranch<vector<float>>  ("allHad_gen_vvv_pt"); 
    ana.tx.createBranch<vector<float>>  ("allHad_gen_vvv_eta"); 
    ana.tx.createBranch<vector<float>>  ("allHad_gen_pdgId");
    
    
    // Single var branches
    ana.tx.createBranch<float>  ("allHad_MET");
    ana.tx.createBranch<float>  ("allHad_genHT");
    ana.tx.createBranch<float>  ("allHad_mVVV");
    ana.tx.createBranch<float>  ("allHad_HT");
    ana.tx.createBranch<float>  ("allHad_ST");
    ana.tx.createBranch<float>  ("allHad_mVVV_reco");
    ana.tx.createBranch<float>  ("allHad_ptVVV_reco");
    ana.tx.createBranch<float>  ("allHad_mVVV_reco_nomet");
    ana.tx.createBranch<float>  ("allHad_ptVVV_reco_nomet");
    
    ana.tx.createBranch<float>  ("allHad_fj_mVVV");
    ana.tx.createBranch<float>  ("allHad_fj_HT");
    ana.tx.createBranch<float>  ("allHad_fj_ST");
    ana.tx.createBranch<float>  ("allHad_fj_mVVV_reco");
    ana.tx.createBranch<float>  ("allHad_fj_ptVVV_reco");
    ana.tx.createBranch<float>  ("allHad_fj_mVVV_reco_nomet");
    ana.tx.createBranch<float>  ("allHad_fj_ptVVV_reco_nomet");
    
    
    ana.tx.createBranch<int>  ("allHad_nGenLeps");
    ana.tx.createBranch<int>  ("allHad_nb_loose");
    ana.tx.createBranch<int>  ("allHad_nb_medium");
    ana.tx.createBranch<int>  ("allHad_nb_tight");
    ana.tx.createBranch<int>  ("allHad_FatJet_subjet_btag_loose");
    ana.tx.createBranch<int>  ("allHad_FatJet_subjet_btag_medium");

    // Define selections
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    // Create histograms used in this category.
    // Please follow the convention of h_<category>_<varname> structure.
    // N.B. Using nbins of size 180 or 360 can provide flexibility as it can be rebinned easily, as 180, 360 are highly composite numbers.
    
    // Super basic selection for now -- 0 leptons and some jets
   
     
    const int eft_reweighting_idx = ana.eft_reweighting_idx;
    std::cout << "eft index " << eft_reweighting_idx << std::endl;
    
     
    ana.cutflow.getCut("CommonCut");
    ana.cutflow.addCutToLastActiveCut("allHad", [&]() { 

        if( ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid").size() > 0) return false; 
        if( (ana.tx.getBranchLazy<vector<float>>("allHad_Jet_pt").size() + ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_pt").size()) < 1) return false; 
             
        return true;
        
        }, [&, eft_reweighting_idx]() { return  eft_reweighting_idx < 0 ? ana.tx.getBranchLazy<float>("Common_genWeight") :ana.tx.getBranchLazy<float>("Common_genWeight") * ana.tx.getBranchLazy<vector<float>>("Common_LHEWeight_mg_reweighting")[eft_reweighting_idx]; } );
    
/*    ana.cutflow.getCut("allHad");
    ana.cutflow.addCutToLastActiveCut("allHad_scouting", [&](){
        if (ana.tx.getBranchLazy<float>("allHad_HT") < 1100 && ana.tx.getBranchLazy<float>("allHad_HT") > 600)  return true;
        return false;
    }, [&]() { return 1; } );
  */  
    
    
    ana.cutflow.getCut("allHad");
    ana.cutflow.addCutToLastActiveCut("allHad_ORTrigger", [&]() {
        if( ! (ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet400_TrimMass30") || ana.tx.getBranchLazy<bool>("Common_HLT_PFHT1050") || ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet500") || ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet400_TrimMass30"))) return false;
        if (ana.tx.getBranchLazy<float>("allHad_HT") < 1100) return false;
        if (ana.tx.getBranchLazy<int>("allHad_nb_medium") > 0) return false;
        return true;
    }, [&]() { return 1; } );
     
    ana.cutflow.getCut("allHad_ORTrigger");
    ana.cutflow.addCutToLastActiveCut("allHad_ORTrigger_2fj", [&]() {
        if(ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_pt").size() == 2) return true;
        return false;
    }, [&]() { return 1; } );
    
    ana.cutflow.getCut("allHad_ORTrigger");
    ana.cutflow.addCutToLastActiveCut("allHad_ORTrigger_3fj", [&]() {
        if(ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_pt").size() == 3) return true;
        return false;
    }, [&]() { return 1; } );

    //SR 1 -- 2fj, low mVVV, low pTVVV
    ana.cutflow.getCut("allHad_ORTrigger_2fj");
    ana.cutflow.addCutToLastActiveCut("allHad_SR1", [&]() {
        if(ana.tx.getBranchLazy<float>("allHad_fj_mVVV_reco") < 2500 && ana.tx.getBranchLazy<float>("allHad_fj_ptVVV_reco") < 800) return true;
        return false;
    }, [&]() { return 1;} );
    
    //SR 2 -- 2fj, high mVVV, low pTVVV
    ana.cutflow.getCut("allHad_ORTrigger_2fj");
    ana.cutflow.addCutToLastActiveCut("allHad_SR2", [&]() {
        if(ana.tx.getBranchLazy<float>("allHad_fj_mVVV_reco") > 2500 && ana.tx.getBranchLazy<float>("allHad_fj_ptVVV_reco") < 800) return true;
        return false;
    }, [&]() { return 1;} );
    
    //SR 3 -- 2fj, low mVVV, high pTVVV
    ana.cutflow.getCut("allHad_ORTrigger_2fj");
    ana.cutflow.addCutToLastActiveCut("allHad_SR3", [&]() {
        if(ana.tx.getBranchLazy<float>("allHad_fj_mVVV_reco") < 2500 && ana.tx.getBranchLazy<float>("allHad_fj_ptVVV_reco") > 800) return true;
        return false;
    }, [&]() { return 1;});
    
    //SR 4 -- 2fj, high mVVV, high pTVVV
    ana.cutflow.getCut("allHad_ORTrigger_2fj");
    ana.cutflow.addCutToLastActiveCut("allHad_SR4", [&]() {
        if(ana.tx.getBranchLazy<float>("allHad_fj_mVVV_reco") > 2500 && ana.tx.getBranchLazy<float>("allHad_fj_ptVVV_reco") > 800) return true;
        return false;
    }, [&]() { return 1;});
    
    
    //SR 5 -- 3fj, low mVVV, low pTVVV
    ana.cutflow.getCut("allHad_ORTrigger_3fj");
    ana.cutflow.addCutToLastActiveCut("allHad_SR5", [&]() {
        if(ana.tx.getBranchLazy<float>("allHad_fj_mVVV_reco") < 2500 && ana.tx.getBranchLazy<float>("allHad_fj_ptVVV_reco") < 800) return true;
        return false;
    }, [&]() { return 1;});
    
    //SR 6 -- 3fj, high mVVV, low pTVVV
    ana.cutflow.getCut("allHad_ORTrigger_3fj");
    ana.cutflow.addCutToLastActiveCut("allHad_SR6", [&]() {
        if(ana.tx.getBranchLazy<float>("allHad_fj_mVVV_reco") > 2500 && ana.tx.getBranchLazy<float>("allHad_fj_ptVVV_reco") < 800) return true;
        return false;
    }, [&]() { return 1;});
    
    //SR 7 -- 3fj, low mVVV, high pTVVV
    ana.cutflow.getCut("allHad_ORTrigger_3fj");
    ana.cutflow.addCutToLastActiveCut("allHad_SR7", [&]() {
        if(ana.tx.getBranchLazy<float>("allHad_fj_mVVV_reco") < 2500 && ana.tx.getBranchLazy<float>("allHad_fj_ptVVV_reco") > 800) return true;
        return false;
    }, [&]() { return 1;});
    
    //SR 8 -- 3fj, high mVVV, high pTVVV
    ana.cutflow.getCut("allHad_ORTrigger_3fj");
    ana.cutflow.addCutToLastActiveCut("allHad_SR8", [&]() {
        if(ana.tx.getBranchLazy<float>("allHad_fj_mVVV_reco") > 2500 && ana.tx.getBranchLazy<float>("allHad_fj_ptVVV_reco") > 800) return true;
        return false;
    }, [&]() { return 1;});



    


    /* 
    ana.cutflow.getCut("allHad");
    ana.cutflow.addCutToLastActiveCut("SM",[&](){ return 1;}, [&]() {return ana.tx.getBranchLazy<vector<float>>("Common_LHEWeight_mg_reweighting")[0]; } );
    
    ana.cutflow.getCut("allHad");
    ana.cutflow.addCutToLastActiveCut("EFT_FT0_10",[&](){ return 1;}, [&]() {return ana.tx.getBranchLazy<vector<float>>("Common_LHEWeight_mg_reweighting")[6]; } );
    
    ana.cutflow.getCut("allHad");
    ana.cutflow.addCutToLastActiveCut("EFT_FT0_m10",[&](){ return 1;}, [&]() {return ana.tx.getBranchLazy<vector<float>>("Common_LHEWeight_mg_reweighting")[1]; } );
    
    ana.cutflow.getCut("allHad");
    ana.cutflow.addCutToLastActiveCut("EFT_FT0_m5",[&](){ return 1;}, [&]() {return ana.tx.getBranchLazy<vector<float>>("Common_LHEWeight_mg_reweighting")[2]; } );
    */
    RooUtil::Histograms hists_allHad;

    //single value histograms
    hists_allHad.addHistogram("NJets"            ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<vector<float>>("allHad_Jet_pt").size()    ; } );
    hists_allHad.addHistogram("NLeps"            ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid").size()   ; } );
    hists_allHad.addHistogram("NGenLeptons"       ,  10,   0,   10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_nGenLeps")   ; } );
    hists_allHad.addHistogram("NFatJets"         ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_pt").size() ; } );
    hists_allHad.addHistogram("NW"               ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("Common_n_W") ; } );
    //hists_allHad.addHistogram("gen_vvvdecay_n"               ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_idx").size() ; } );
    hists_allHad.addHistogram("n_b_loose"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_nb_loose") ; } );
    hists_allHad.addHistogram("n_b_medium"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_nb_medium") ; } );
    hists_allHad.addHistogram("n_b_tight"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_nb_tight") ; } );
    hists_allHad.addHistogram("MET"              ,  40,   0,    1000, [&]() { return    ana.tx.getBranch<float>  ("allHad_MET"); } );
    ///hists_allHad.addHistogram("mVVV"               ,  60,   0,    5000, [&]() { return    ana.tx.getBranch<float>  ("allHad_mVVV"); } );
    hists_allHad.addHistogram("genHT"            ,  40,   0,    5000, [&]() { return    ana.tx.getBranch<float>  ("allHad_genHT"); } );
    hists_allHad.addHistogram("HT"               ,  40,   0,    5000, [&]() { return    ana.tx.getBranch<float>  ("allHad_HT"); } );
    hists_allHad.addHistogram("ST"               ,  40,   0,    5000, [&]() { return    ana.tx.getBranch<float>  ("allHad_ST"); } );
    hists_allHad.addHistogram("mVVV_reco"               ,  60,   0,    5000, [&]() { return    ana.tx.getBranch<float>  ("allHad_mVVV_reco"); } );
    hists_allHad.addHistogram("ptVVV_reco"               ,  60,   0,    5000, [&]() { return    ana.tx.getBranch<float>  ("allHad_ptVVV_reco"); } );
    hists_allHad.addHistogram("mVVV_reco_nomet"               ,  60,   0,    5000, [&]() { return    ana.tx.getBranch<float>  ("allHad_mVVV_reco_nomet"); } );
    hists_allHad.addHistogram("ptVVV_reco_nomet"               ,  60,   0,    5000, [&]() { return    ana.tx.getBranch<float>  ("allHad_ptVVV_reco_nomet"); } );
    
    hists_allHad.addHistogram("HT_fj"               ,  40,   0,    5000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_HT"); } );
    hists_allHad.addHistogram("ST_fj"               ,  40,   0,    5000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_ST"); } );
    hists_allHad.addHistogram("mVVV_reco_fj"               ,  60,   0,    5000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_mVVV_reco"); } );
    hists_allHad.addHistogram("ptVVV_reco_fj"               ,  60,   0,    5000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_ptVVV_reco"); } );
    hists_allHad.addHistogram("mVVV_reco_nomet_fj"               ,  60,   0,    5000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_mVVV_reco_nomet"); } );
    hists_allHad.addHistogram("ptVVV_reco_nomet_fj"               ,  60,   0,    5000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_ptVVV_reco_nomet"); } );
    
    //hists_allHad.addHistogram("gen_vvv_pt0"       ,  20,   0,    2000,  [&]() { return (ana.tx.getBranch<vector<float>>("allHad_gen_vvv_pt").size() > 0) ?     ana.tx.getBranch<vector<float>>  ("allHad_gen_vvv_pt")[0] : -999; } );
    //hists_allHad.addHistogram("gen_vvv_eta0"       ,  20,  0,    3,  [&]() { return   (ana.tx.getBranch<vector<float>>("allHad_gen_vvv_eta").size() > 0) ?   ana.tx.getBranch<vector<float>>  ("allHad_gen_vvv_eta")[0] : -999; } );
    
    hists_allHad.add2DHistogram("mVVV", 60,   0,    3000, "MET", 40,   0,    2000, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV");}, [&]() { return ana.tx.getBranch<float>  ("allHad_MET"); } );
    hists_allHad.add2DHistogram("HT", 60,   0,    3000, "MET", 40,   0,    2000, [&]() { return ana.tx.getBranch<float>  ("allHad_HT");}, [&]() { return ana.tx.getBranch<float>  ("allHad_MET"); } );
    hists_allHad.add2DHistogram("mVVV_reco", 60,   0,    3000, "MET", 40,   0,    2000, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_MET"); } );
    hists_allHad.add2DHistogram("mVVV", 60,   0,    3000, "HT", 60,   0,    3000, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV");}, [&]() { return ana.tx.getBranch<float>  ("allHad_HT"); } );
    hists_allHad.add2DHistogram("mVVV_reco", 60,   0,    3000, "HT", 60,   0,    3000, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_HT"); } );
    hists_allHad.add2DHistogram("ptVVV_reco", 60,   0,    3000, "HT", 60,   0,    3000, [&]() { return ana.tx.getBranch<float>  ("allHad_ptVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_HT"); } );
    hists_allHad.add2DHistogram("mVVV", 60,   0,    3000, "ST", 60,   0,    3000, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV");}, [&]() { return ana.tx.getBranch<float>  ("allHad_ST"); } );
    hists_allHad.add2DHistogram("mVVV_reco", 60,   0,    3000, "ST", 60,   0,    3000, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_ST"); } );
    hists_allHad.add2DHistogram("mVVV", 60,   0,    3000, "mVVV_reco", 60,   0,    3000, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV");}, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV_reco"); } );
    hists_allHad.add2DHistogram("ptVVV_reco", 60,   0,    3000, "mVVV_reco", 50,   0,    3000, [&]() { return ana.tx.getBranch<float>  ("allHad_ptVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV_reco"); } );
    hists_allHad.add2DHistogram("genHT", 60,   0,    3000, "HT", 40,   0,    3000, [&]() { return ana.tx.getBranch<float>  ("allHad_genHT");}, [&]() { return ana.tx.getBranch<float>  ("allHad_HT"); } );
    hists_allHad.add2DHistogram("Njets", 6,   0,    6, "NFatjets", 6,   0,    6, [&]() { return ana.tx.getBranchLazy<vector<float>>("allHad_Jet_pt").size();}, [&]() { return ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_pt").size(); } );
    hists_allHad.add2DHistogram("ptVVV_reco_fj", 60,   0,    5000, "mVVV_reco_fj", 50,   0,    5000, [&]() { return ana.tx.getBranch<float>  ("allHad_fj_ptVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj_mVVV_reco"); } );

    
    hists_allHad.addHistogram("FatJet_pt_0"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_pt")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_pt_1"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_pt")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_pt_2"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_pt")[2] : -999 ; } );
    
    
    hists_allHad.addHistogram("FatJet_eta_0"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_eta").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_eta")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_eta_1"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_eta").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_eta")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_eta_2"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_eta").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_eta")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_M_0"          ,  40,   0,    1000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_M").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_M")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_M_1"          ,  40,   0,    1000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_M").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_M")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_M_2"          ,  40,   0,    1000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_M").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_M")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_tau21_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau21").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau21")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau21_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau21").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau21")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau21_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau21").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau21")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_tau1_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau1").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau1")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau1_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau1").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau1")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau1_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau1").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau1")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_tau2_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau2").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau2")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau2_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau2").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau2")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau2_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau2").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau2")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_tau3_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau3").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau3")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau3_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau3").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau3")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau3_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau3").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau3")[2] : -999 ; } );
    
    
    hists_allHad.addHistogram("FatJet_tau32_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau32").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau32")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau32_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau32").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau32")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau32_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau32").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau32")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_Wtag_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_Wtag").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Wtag")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_Wtag_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_Wtag").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Wtag")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_Wtag_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_Wtag").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Wtag")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_Ztag_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_Ztag").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Ztag")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_Ztag_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_Ztag").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Ztag")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_Ztag_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_Ztag").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Ztag")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_Ttag_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_Ttag").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Ttag")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_Ttag_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_Ttag").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Ttag")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_Ttag_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_Ttag").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Ttag")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_msoftdrop_0"          ,  40,   50,    150, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_msoftdrop").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_msoftdrop")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_msoftdrop_1"          ,  40,   50,    150, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_msoftdrop").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_msoftdrop")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_msoftdrop_2"          ,  40,   50,    150, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_msoftdrop").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_msoftdrop")[2] : -999 ; } );
    
    hists_allHad.addHistogram("Jet_pt_0"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_pt").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_Jet_pt")[0] : -999 ; } );
    hists_allHad.addHistogram("Jet_pt_1"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_pt").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_Jet_pt")[1] : -999 ; } );
    hists_allHad.addHistogram("Jet_pt_2"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_pt").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_Jet_pt")[2] : -999 ; } );
    hists_allHad.addHistogram("Jet_pt_3"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_pt").size() > 3) ? ana.tx.getBranch<vector<float>>("allHad_Jet_pt")[3] : -999; } );
    
    hists_allHad.addHistogram("Jet_eta_0"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_eta").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_Jet_eta")[0] : -999 ; } );
    hists_allHad.addHistogram("Jet_eta_1"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_eta").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_Jet_eta")[1] : -999 ; } );
    hists_allHad.addHistogram("Jet_eta_2"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_eta").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_Jet_eta")[2] : -999 ; } );
    hists_allHad.addHistogram("Jet_eta_3"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_eta").size() > 3) ? ana.tx.getBranch<vector<float>>("allHad_Jet_eta")[3] : -999; } );
    
    
    //histograms from vector branches
   /* 
    hists_allHad.addVecHistogram("gen_vvvdecay_pdgid"       ,  20,   0,    20,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_gen_vvvdecay_pdgid"); } );
    hists_allHad.addVecHistogram("gen_vvvdecay_pt"       ,  20,   0,    2000,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_gen_vvvdecay_pt"); } );
    hists_allHad.addVecHistogram("gen_vvv_pt"       ,  20,   0,    2000,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_gen_vvv_pt"); } );
    hists_allHad.addVecHistogram("gen_pdgid"       ,  20,   0,    20,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_gen_pdgId"); } );
    hists_allHad.addVecHistogram("FatJet_tau21"       ,  30,   0,    1,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_tau21"); } );
    hists_allHad.addVecHistogram("FatJet_tau32"       ,  30,   0,    1,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_tau32"); } );
    hists_allHad.addVecHistogram("FatJet_msoftdrop"       ,  40,   50,    150,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_msoftdrop"); } );
    hists_allHad.addVecHistogram("FatJet_pt"     ,  40,   0,    2000, [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_pt"); } );
    hists_allHad.addVecHistogram("FatJet_eta"    ,  20,   -5,   5, [&]() { return         ana.tx.getBranch<vector<float>>  ("allHad_FatJet_eta"); } );
    hists_allHad.addVecHistogram("FatJet_phi"    ,  20,   -4,   4, [&]() { return         ana.tx.getBranch<vector<float>>  ("allHad_FatJet_phi"); } );
    hists_allHad.addVecHistogram("FatJet_M"    ,  40,   0,   1000, [&]() { return         ana.tx.getBranch<vector<float>>  ("allHad_FatJet_M"); } );
    hists_allHad.addVecHistogram("FatJet_ID"    ,  10,   0,   10, [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_FatJet_ID"); } );
    hists_allHad.addVecHistogram("Jet_pt"     ,  40,   0,    2000, [&]() { return         ana.tx.getBranch<vector<float>>  ("allHad_Jet_pt"); } );
    hists_allHad.addVecHistogram("Jet_eta"    ,  20,   -5,   5, [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_Jet_eta"); } );
    hists_allHad.addVecHistogram("Jet_phi"    ,  20,   -4,   4, [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_Jet_phi"); } );
   */
   
    ana.cutflow.bookCutflows(); 
    
    ana.cutflow.bookHistogramsForCutAndBelow(hists_allHad, "allHad");
}
