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
    
    float HT =  ana.tx.getBranchLazy<LorentzVector>("Common_met_p4").Pt();
    
    
    //vector vars
    vector<float> empty;
    empty.clear();
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_tau12",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_pt",     empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_eta",    empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_phi",    empty);
    ana.tx.setBranch<vector<float>>  ("allHad_Jet_pt",        empty);
    ana.tx.setBranch<vector<float>>  ("allHad_Jet_eta",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_Jet_phi",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_gen_vvvdecay_pdgid",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_gen_pdgId",       empty);
    
    int n_veryloose = 0;
    int n_loose = 0;
    int n_medium = 0;
    int n_tight = 0;

    for (unsigned int i=0; i < ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size(); i++){
        LorentzVector tmp = ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[i];
        int fjid = ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[i];
        if (fjid == -999) continue;

        //std::cout << fjid << std::endl;  
        
        if(fjid >= 0) n_veryloose ++;
        if(fjid >= 1) n_loose ++;
        if(fjid >= 2) n_medium ++;
        if(fjid >= 3) n_tight ++;
       

        ana.tx.pushbackToBranch<float>  ("allHad_FatJet_tau12", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_tau21")[i]);
        ana.tx.pushbackToBranch<float>  ("allHad_FatJet_pt",    tmp.Pt());
        ana.tx.pushbackToBranch<float>  ("allHad_FatJet_eta",   tmp.Eta());
        ana.tx.pushbackToBranch<float>  ("allHad_FatJet_phi",   tmp.Phi());
    }
    
    ana.tx.setBranch<int>  ("allHad_FatJet_n_vloose",  n_veryloose);
    ana.tx.setBranch<int>  ("allHad_FatJet_n_loose",  n_loose);
    ana.tx.setBranch<int>  ("allHad_FatJet_n_medium",  n_medium);
    ana.tx.setBranch<int>  ("allHad_FatJet_n_tight",  n_tight);

    
    for (unsigned int i=0; i < ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs").size(); i++){
        if(ana.tx.getBranchLazy<vector<int>>("Common_jet_overlapfatjet")[i]) continue;
        
        LorentzVector tmp = ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[i];
         
        ana.tx.pushbackToBranch<float>  ("allHad_Jet_pt",  tmp.Pt());
        ana.tx.pushbackToBranch<float>  ("allHad_Jet_eta", tmp.Eta()); 
        ana.tx.pushbackToBranch<float>  ("allHad_Jet_phi", tmp.Phi());
        HT += tmp.Pt();
    }
    
    LorentzVector vvv; 
    for (unsigned int i=0; i < ana.tx.getBranchLazy<vector<int>>("Common_gen_idx").size(); i++){
        if (abs(ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid")[i]) == 24 || abs(ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid")[i] == 23)){
            LorentzVector tmp = RooUtil::Calc::getLV(ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[i].Pt(), ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[i].Eta(), ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[i].Phi(), ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[i].M());
            vvv += tmp;
       }   
    }
    ana.tx.setBranch<float>  ("allHad_mVVV",  vvv.M());

    
    for (unsigned int i=0; i < ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_pdgid").size(); i++){
        ana.tx.pushbackToBranch<float>    ("allHad_gen_vvvdecay_pdgid", abs(ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_pdgid")[i]));
    }
    
    for (unsigned int i=0; i < ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid").size(); i++){
        ana.tx.pushbackToBranch<float>    ("allHad_gen_pdgId", abs(ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid")[i]));
    }
    
    ana.tx.setBranch<float>  ("allHad_HT",   HT);
    
    float HT_met =  HT + ana.tx.getBranchLazy<LorentzVector>("Common_met_p4").Pt();
    
    ana.tx.setBranch<float>  ("allHad_HT_met",   HT_met);

    // Semi-complete list of NanoAOD for 102X can be found here: https://cms-nanoaod-integration.web.cern.ch/integration/master-102X/mc102X_doc.html
    // Also consult here: https://github.com/cmstas/NanoTools/blob/d641a6d6c1aa9ecc8094a1af73d5e1bd7d6502ab/NanoCORE/Nano.h#L4875 (if new variables are added they may show up in master)

}
