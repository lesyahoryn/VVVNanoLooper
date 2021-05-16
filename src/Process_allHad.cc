#include "Process_allHad.h"

void Process_allHad()
{
    //==============================================
    // Process_allHad:
    // This function gets called during the event looping.
    // This is where one sets the variables used for the category allHad.
    //==============================================

    // Set variables used in this category.
    // If histograms are booked with these variables the histograms will be filled automatically.
    // Please follow the convention of <category>_<varname> structure.
    //ana.tx.setBranch<int>("allHad_intVar1", -999);
    //ana.tx.setBranch<float>("allHad_floatVar1", -999);
    
    //event level vars
    ana.tx.setBranch<float>  ("allHad_MET",  ana.tx.getBranchLazy<LorentzVector>("Common_met_p4").Pt());
    ana.tx.setBranch<float>  ("allHad_genHT",   ana.tx.getBranchLazy<float>("Common_genHT"));
    
    
    //vector vars
    vector<float> empty;
    vector<int> empty_i;
    empty.clear();
    empty_i.clear();
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_tau1",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_tau2",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_tau3",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_tau21",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_tau32",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_msoftdrop",  empty);

    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_subjet0_pt",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_subjet0_eta",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_subjet0_phi",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_subjet0_mass",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_subjet0_btag",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_subjet1_pt",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_subjet1_eta",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_subjet1_phi",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_subjet1_mass",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_subjet1_btag",  empty);
    
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_pt",     empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_M",     empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_eta",    empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_phi",    empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_ID",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_Jet_pt",        empty);
    ana.tx.setBranch<vector<float>>  ("allHad_Jet_eta",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_Jet_phi",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_Jet_ID",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_Jet_puid",       empty);
    
    ana.tx.setBranch<vector<int>>    ("allHad_FatJet_WP",     empty_i);
    ana.tx.setBranch<vector<float>>  ("allHad_gen_vvvdecay_pdgid",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_gen_vvvdecay_pt",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_gen_vvv_pt",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_gen_vvv_eta",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_gen_pdgId",       empty);
    
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_Zbbtag",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_Ztag",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_Ttag",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_Wtag",  empty);

    vector<LorentzVector> selected_p4;

    float HT_fj = 0;
    float ST_fj = 0;
    LorentzVector vvv_reco_fj; 
        
    
    int n_loose_subjet = 0;
    int n_medium_subjet = 0;

    bool first_jet = true;
    for (unsigned int i=0; i < ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size(); i++){
        LorentzVector tmp = ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[i];
        int fjid = ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[i];
        if (tmp.Pt() < 200 || abs(tmp.Eta()) > 2.4) continue;
        if (ana.tx.getBranchLazy<vector<int>>("Common_fatjet_id")[i] != 6) continue;
        
             
         
        //only select medium fatjets 
        if(fjid >= 2) {
            //fatjet pt 0 > 500 GeV for trigger turn on
            if(first_jet){
                 first_jet = false;
                 if(tmp.Pt() < 500) continue;
            }
            selected_p4.push_back(tmp);
            HT_fj += tmp.Pt();
            vvv_reco_fj += tmp;

            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_tau1", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_tau1")[i]);
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_tau2", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_tau2")[i]);
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_tau3", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_tau3")[i]);
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_tau21", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_tau21")[i]);
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_tau32", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_tau32")[i]);
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_msoftdrop", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[i]);
            ana.tx.pushbackToBranch<int>    ("allHad_FatJet_WP",    fjid);
            ana.tx.pushbackToBranch<float>    ("allHad_FatJet_Wtag",    ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_W")[i]);
            ana.tx.pushbackToBranch<float>    ("allHad_FatJet_Ztag",    ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_Z")[i]);
            ana.tx.pushbackToBranch<float>    ("allHad_FatJet_Ttag",    ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_T")[i]);
            ana.tx.pushbackToBranch<float>    ("allHad_FatJet_Zbbtag",    ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_bb")[i]);
            ana.tx.pushbackToBranch<float>    ("allHad_FatJet_ID",    ana.tx.getBranchLazy<vector<int>>("Common_fatjet_id")[i]);
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_pt",    tmp.Pt());
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_M",    tmp.M());
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_eta",   tmp.Eta());
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_phi",   tmp.Phi());
            
            
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_subjet0_pt", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_subjet0_pt")[i]);
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_subjet0_eta", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_subjet0_eta")[i]);
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_subjet0_phi", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_subjet0_phi")[i]);
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_subjet0_mass", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_subjet0_mass")[i]);
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_subjet0_btag", ana.tx.getBranchLazy<vector<int>>("Common_fatjet_subjet0_btag")[i]);
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_subjet1_pt", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_subjet1_pt")[i]);
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_subjet1_eta", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_subjet1_eta")[i]);
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_subjet1_phi", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_subjet1_phi")[i]);
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_subjet1_mass", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_subjet1_mass")[i]);
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_subjet1_btag", ana.tx.getBranchLazy<vector<int>>("Common_fatjet_subjet1_btag")[i]);

            if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_subjet0_btag")[i] >= 1) n_loose_subjet++;
            if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_subjet0_btag")[i] >= 2) n_medium_subjet++;

            if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_subjet1_btag")[i] >= 1) n_loose_subjet++;
            if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_subjet1_btag")[i] >= 2) n_medium_subjet++;

        }
    }
    ST_fj = HT_fj + ana.tx.getBranchLazy<LorentzVector>("Common_met_p4").Pt();

    ana.tx.setBranch<float>  ("allHad_fj_mVVV_reco_nomet",   vvv_reco_fj.M());
    ana.tx.setBranch<float>  ("allHad_fj_ptVVV_reco_nomet",  vvv_reco_fj.Pt());
    
    vvv_reco_fj += ana.tx.getBranchLazy<LorentzVector>("Common_met_p4");
    
    ana.tx.setBranch<float>  ("allHad_fj_HT",   HT_fj);
    ana.tx.setBranch<float>  ("allHad_fj_ST",   ST_fj);
    ana.tx.setBranch<float>  ("allHad_fj_mVVV_reco",   vvv_reco_fj.M());
    ana.tx.setBranch<float>  ("allHad_fj_ptVVV_reco",  vvv_reco_fj.Pt());

    
    
    
    
    ana.tx.setBranch<int>("allHad_FatJet_subjet_btag_loose", n_loose_subjet);
    ana.tx.setBranch<int>("allHad_FatJet_subjet_btag_medium", n_medium_subjet);
    
    int nb_loose = 0;
    int nb_tight = 0;
    int nb_medium = 0;
    
    for (unsigned int i=0; i < ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs").size(); i++){
        if (ana.tx.getBranchLazy<vector<int>>("Common_jet_id")[i] != 6) continue;
        
        LorentzVector tmp = ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[i];
        if (abs(tmp.Eta()) > 2.4) continue;
        
        //do jet/fatjet overlap removal after b-veto 
        if( ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBmedium")[i] ) nb_medium++;
        if( ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBtight")[i] ) nb_tight++;
        if( ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBloose")[i] ) nb_loose++;
        
        if(ana.tx.getBranchLazy<vector<int>>("Common_jet_overlapfatjet")[i]) continue;
         
        ana.tx.pushbackToBranch<float>  ("allHad_Jet_pt",  tmp.Pt());
        ana.tx.pushbackToBranch<float>  ("allHad_Jet_eta", tmp.Eta()); 
        ana.tx.pushbackToBranch<float>  ("allHad_Jet_phi", tmp.Phi());
        ana.tx.pushbackToBranch<float>  ("allHad_Jet_ID", ana.tx.getBranchLazy<vector<int>>("Common_jet_id")[i]);
        ana.tx.pushbackToBranch<float>  ("allHad_Jet_puid", ana.tx.getBranchLazy<vector<int>>("Common_jet_puid")[i]);

        if( ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBmedium")[i] ) nb_medium++;
        if( ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBtight")[i] ) nb_tight++;
        if( ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBloose")[i] ) nb_loose++;

        selected_p4.push_back(tmp);
    }
    
        
    ana.tx.setBranch<int>  ("allHad_nb_loose",   nb_loose);
    ana.tx.setBranch<int>  ("allHad_nb_medium",  nb_medium);
    ana.tx.setBranch<int>  ("allHad_nb_tight",   nb_tight);
     
    float HT = 0;
    float ST = 0;
    LorentzVector vvv_reco; 
    for(unsigned int i=0; i<selected_p4.size(); i++){
        HT += selected_p4[i].Pt();
        LorentzVector tmp = RooUtil::Calc::getLV(selected_p4[i].Pt(), selected_p4[i].Eta(), selected_p4[i].Phi(), selected_p4[i].M());
        vvv_reco += tmp;
    }
    ST = HT + ana.tx.getBranchLazy<LorentzVector>("Common_met_p4").Pt();
    
    ana.tx.setBranch<float>  ("allHad_mVVV_reco_nomet",   vvv_reco.M());
    ana.tx.setBranch<float>  ("allHad_ptVVV_reco_nomet",   vvv_reco.Pt());
    vvv_reco += ana.tx.getBranchLazy<LorentzVector>("Common_met_p4");
        
    
    ana.tx.setBranch<float>  ("allHad_HT",   HT);
    ana.tx.setBranch<float>  ("allHad_ST",   ST);
    ana.tx.setBranch<float>  ("allHad_mVVV_reco",   vvv_reco.M());
    ana.tx.setBranch<float>  ("allHad_ptVVV_reco",  vvv_reco.Pt());


        


    //truth level stuff
    
    ana.tx.setBranch<float>  ("allHad_mVVV",  -999);
    ana.tx.setBranch<int>  ("allHad_nGenLeps",  -999);
    if(ana.tx.getBranch<bool>("Common_isSignal")){
        LorentzVector vvv; 
        for (unsigned int i=0; i < ana.tx.getBranchLazy<vector<int>>("Common_gen_idx").size(); i++){
            if (abs(ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid")[i]) == 24 || abs(ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid")[i] == 23)){
                LorentzVector tmp = RooUtil::Calc::getLV(ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[i].Pt(), ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[i].Eta(), ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[i].Phi(), ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[i].M());
                vvv += tmp;
                
                ana.tx.pushbackToBranch<float>    ("allHad_gen_vvv_pt", abs(ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[i].Pt()));
                ana.tx.pushbackToBranch<float>    ("allHad_gen_vvv_eta", abs(ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[i].Eta()));
           }   
        }
        
        int nleps = 0;
        //ana.tx.setBranch<int>  ("allHad_nGenLeptons",  10);
        for (unsigned int i=0; i < ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_pdgid").size(); i++){
            //std::cout << (ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_pdgid")[i]) << std::endl;
            if( abs(ana.tx.getBranch<vector<int>>("Common_gen_vvvdecay_pdgid")[i]) == 11 ||  
                abs(ana.tx.getBranch<vector<int>>("Common_gen_vvvdecay_pdgid")[i]) == 13 || 
                abs(ana.tx.getBranch<vector<int>>("Common_gen_vvvdecay_pdgid")[i]) == 15   ){ nleps+=1;}

            ana.tx.pushbackToBranch<float>    ("allHad_gen_vvvdecay_pdgid", abs(ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_pdgid")[i]));
            ana.tx.pushbackToBranch<float>    ("allHad_gen_vvvdecay_pt", abs(ana.tx.getBranch<vector<LorentzVector>>("Common_gen_vvvdecay_p4s")[i].Pt()));
        }
        
        for (unsigned int i=0; i < ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid").size(); i++){
            ana.tx.pushbackToBranch<float>    ("allHad_gen_pdgId", abs(ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid")[i]));
        }
        
        ana.tx.setBranch<float>  ("allHad_mVVV",  vvv.M());
        ana.tx.setBranch<int>  ("allHad_nGenLeps", nleps);
    }

    // Semi-complete list of NanoAOD for 102X can be found here: https://cms-nanoaod-integration.web.cern.ch/integration/master-102X/mc102X_doc.html
    // Also consult here: https://github.com/cmstas/NanoTools/blob/d641a6d6c1aa9ecc8094a1af73d5e1bd7d6502ab/NanoCORE/Nano.h#L4875 (if new variables are added they may show up in master)

}
