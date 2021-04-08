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
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_tau21",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_tau32",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_msoftdrop",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_pt",     empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_M",     empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_eta",    empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_phi",    empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_ID",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_Jet_pt",        empty);
    ana.tx.setBranch<vector<float>>  ("allHad_Jet_eta",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_Jet_phi",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_Jet_ID",       empty);
    
    ana.tx.setBranch<vector<int>>    ("allHad_FatJet_WP",     empty_i);
    ana.tx.setBranch<vector<float>>  ("allHad_gen_vvvdecay_pdgid",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_gen_vvvdecay_pt",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_gen_vvv_pt",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_gen_vvv_eta",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_gen_pdgId",       empty);
    
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_tight_tau21",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_tight_tau32",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_tight_msoftdrop",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_tight_Wtag",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_tight_Ztag",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_tight_Ttag",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_tight_Zbbtag",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_tight_pt",     empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_tight_M",     empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_tight_eta",    empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_tight_phi",    empty);
    
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_Zbbtag",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_Ztag",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_Ttag",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_Wtag",  empty);

    vector<LorentzVector> selected_p4;
    vector<LorentzVector> selected_p4_tight;


    
    int n_loose = 0;
    int n_medium = 0;
    int n_tight = 0;

    for (unsigned int i=0; i < ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size(); i++){
        LorentzVector tmp = ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[i];
        int fjid = ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[i];
        if (fjid == -999 || tmp.Pt() < 200 || abs(tmp.Eta()) > 2.4) continue;
        if (ana.tx.getBranchLazy<vector<int>>("Common_fatjet_id")[i] != 6) continue;
        

        //std::cout << fjid << std::endl;  
        
        if(fjid >= 3){
            n_tight ++;
            selected_p4_tight.push_back(tmp);
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_tight_tau21", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_tau21")[i]);
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_tight_tau32", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_tau32")[i]);
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_tight_msoftdrop", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[i]);
            ana.tx.pushbackToBranch<float>    ("allHad_FatJet_tight_Wtag",    ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_W")[i]);
            ana.tx.pushbackToBranch<float>    ("allHad_FatJet_tight_Ztag",    ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_Z")[i]);
            ana.tx.pushbackToBranch<float>    ("allHad_FatJet_tight_Ttag",    ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_T")[i]);
            ana.tx.pushbackToBranch<float>    ("allHad_FatJet_tight_Zbbtag",    ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_bb")[i]);
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_tight_pt",    tmp.Pt());
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_tight_M",    tmp.M());
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_tight_eta",   tmp.Eta());
            ana.tx.pushbackToBranch<float>  ("allHad_FatJet_tight_phi",   tmp.Phi());


        }
        
        
        //only select medium fatjets 
        if(fjid >= 2) {
            selected_p4.push_back(tmp);

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
        }
    }
    
    int nb_loose = 0;
    int nb_tight = 0;
    int nb_medium = 0;
    
    for (unsigned int i=0; i < ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs").size(); i++){
        if(ana.tx.getBranchLazy<vector<int>>("Common_jet_overlapfatjet")[i]) continue;
        if (ana.tx.getBranchLazy<vector<int>>("Common_jet_id")[i] != 6) continue;
        
        LorentzVector tmp = ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[i];
        if (abs(tmp.Eta()) > 2.4) continue;
         
        ana.tx.pushbackToBranch<float>  ("allHad_Jet_pt",  tmp.Pt());
        ana.tx.pushbackToBranch<float>  ("allHad_Jet_eta", tmp.Eta()); 
        ana.tx.pushbackToBranch<float>  ("allHad_Jet_phi", tmp.Phi());
        ana.tx.pushbackToBranch<float>  ("allHad_Jet_ID", ana.tx.getBranchLazy<vector<int>>("Common_jet_id")[i]);

        if( ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBmedium")[i] ) nb_medium++;
        if( ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBtight")[i] ) nb_tight++;
        if( ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBloose")[i] ) nb_loose++;

        selected_p4.push_back(tmp);
        selected_p4_tight.push_back(tmp);
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
    vvv_reco += ana.tx.getBranchLazy<LorentzVector>("Common_met_p4");
        
    
    ana.tx.setBranch<float>  ("allHad_HT",   HT);
    ana.tx.setBranch<float>  ("allHad_ST",   ST);
    ana.tx.setBranch<float>  ("allHad_mVVV_reco",   vvv_reco.M());
    
    float HT_tight = 0;
    float ST_tight = 0;
    LorentzVector vvv_reco_tight; 
    for(unsigned int i=0; i<selected_p4_tight.size(); i++){
        HT_tight += selected_p4_tight[i].Pt();
        LorentzVector tmp = RooUtil::Calc::getLV(selected_p4_tight[i].Pt(), selected_p4_tight[i].Eta(), selected_p4_tight[i].Phi(), selected_p4_tight[i].M());
        vvv_reco_tight += tmp;
    }
    ST_tight = HT_tight + ana.tx.getBranchLazy<LorentzVector>("Common_met_p4").Pt();
    vvv_reco_tight += ana.tx.getBranchLazy<LorentzVector>("Common_met_p4");
        
    
    ana.tx.setBranch<float>  ("allHad_HT_tight",   HT_tight);
    ana.tx.setBranch<float>  ("allHad_ST_tight",   ST_tight);
    ana.tx.setBranch<float>  ("allHad_mVVV_reco_tight",   vvv_reco_tight.M());











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
