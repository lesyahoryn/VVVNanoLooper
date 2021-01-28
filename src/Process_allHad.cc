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
    empty.clear();
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_tau12",  empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_pt",     empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_eta",    empty);
    ana.tx.setBranch<vector<float>>  ("allHad_FatJet_phi",    empty);
    ana.tx.setBranch<vector<float>>  ("allHad_Jet_pt",        empty);
    ana.tx.setBranch<vector<float>>  ("allHad_Jet_eta",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_Jet_phi",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_gen_vvvdecay_pdgid",       empty);
    
    for (int i=0; i < ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size(); i++){
        LorentzVector tmp = ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[i];
        
        ana.tx.pushbackToBranch<float>  ("allHad_FatJet_tau12", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_tau21")[i]);
        ana.tx.pushbackToBranch<float>  ("allHad_FatJet_pt",    tmp.Pt());
        ana.tx.pushbackToBranch<float>  ("allHad_FatJet_eta",   tmp.Eta());
        ana.tx.pushbackToBranch<float>  ("allHad_FatJet_phi",   tmp.Phi());
        
    }
    
    for (int i=0; i < ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs").size(); i++){
        LorentzVector tmp = ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[i];
         
        ana.tx.pushbackToBranch<float>  ("allHad_Jet_pt",  tmp.Pt());
        ana.tx.pushbackToBranch<float>  ("allHad_Jet_eta", tmp.Eta()); 
        ana.tx.pushbackToBranch<float>  ("allHad_Jet_phi", tmp.Phi());
    }
    
    for (int i=0; i < ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_pdgid").size(); i++){
        ana.tx.pushbackToBranch<float>    ("allHad_gen_vvvdecay_pdgid", abs(ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_pdgid")[i]));
    }

    // Example of reading from Nano
    // std::vector<LorentzVector> electron_p4s = nt.Electron_p4(); // nt is a global variable that accesses NanoAOD
    // std::vector<float> electron_mvaTTH = nt.Electron_mvaTTH(); // electron ttH MVA scores from NanoAOD
    // Semi-complete list of NanoAOD for 102X can be found here: https://cms-nanoaod-integration.web.cern.ch/integration/master-102X/mc102X_doc.html
    // Also consult here: https://github.com/cmstas/NanoTools/blob/d641a6d6c1aa9ecc8094a1af73d5e1bd7d6502ab/NanoCORE/Nano.h#L4875 (if new variables are added they may show up in master)

    LorentzVector LV_allHad_LVVar1 = RooUtil::Calc::getLV(34.5, 1.2, 3.123, 0.105); // RooUtil::Calc::getLV() creates 4 vector

    //ana.tx.setBranch<LorentzVector>("allHad_LVVar1", LV_allHad_LVVar1);
}
