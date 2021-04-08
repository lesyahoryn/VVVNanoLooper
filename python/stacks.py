import os
import ROOT

execfile("tdrstyle.py")
setTDRStyle()

ROOT.gROOT.SetBatch()

outdir = "stacks/"

def stack_hists(c, sumw_hist, hists, labels, xname, yname,  savename, logy=False, drawopt="hist", normalize=False):
    legopt = "l"
    if drawopt == "p":
        legopt = "p"

    ROOT.gPad.SetLogy(logy)
    
    ## scale hists
    for h in hists: 
        
        if not normalize: h.Scale(get_weight(h.GetName(), sumw_hist))
        else: 
            if h.Integral() !=0: h.Scale(1/h.Integral())
        
    hists[0].SetMaximum(getMax(hists)*1.2)
    hists[0].GetXaxis().SetTitle(xname)
    hists[0].GetYaxis().SetTitle(yname)
    
    leg = ROOT.TLegend(0.55,0.72,0.85,0.92)
    leg.SetTextSize(0.04)
    leg.SetTextFont(42)
    leg.SetFillStyle(0)
    leg.AddEntry(hists[0], labels[0], legopt)
    
    hists[0].Draw(drawopt)

    for h in xrange(1,len(hists)):
        hists[h].SetLineColor(colors[h-1])
        hists[h].SetMarkerColor(colors[h-1])
        hists[h].Draw(drawopt+"same")
        leg.AddEntry(hists[h], labels[h], legopt)

    leg.Draw("same")
    c.SaveAs(savename)
        
def get_weight(hname, sumw_hist):
    lumi = 137. #ifb
    xs = 0.2086 *1000# for WWW, make this smarter in the future
    eftbin = 5 # default, for FT0_5
    if "SM" in hname: eftbin = 0
    if "FT0_m10" in hname: eftbin = 1
    if "FT0_m5" in hname: eftbin = 2
    if "FT0_10" in hname: eftbin = 6
    
    return xs*lumi
    

def stack_effs(c, hists, labels, xname,  savename, logy=False):

    ROOT.gPad.SetLogy(logy)

    hists[0].SetMarkerSize(1)
    hists[0].Draw("pa")
    ROOT.gPad.Update()
    hists[0].GetPaintedGraph().GetYaxis().SetRangeUser(0,1.5) 
    hists[0].SetTitle(";%s;efficiency"%xname)
    
    leg = ROOT.TLegend(0.25,0.72,0.85,0.92)
    leg.SetTextSize(0.03)
    leg.SetTextFont(42)
    leg.SetFillStyle(0)
    leg.AddEntry(hists[0], labels[0], "p")
    

    for h in xrange(1,len(hists)):
        hists[h].SetLineColor(colors[h-1])
        hists[h].SetMarkerColor(colors[h-1])
        hists[h].SetMarkerSize(1)
        hists[h].Draw("psame")
        leg.AddEntry(hists[h], labels[h], "p")

    leg.Draw("same")
    ROOT.gPad.Update()
    c.Update()
    c.SaveAs(savename)
        




c = ROOT.TCanvas()

f = ROOT.TFile("../WWW.root")
sumw_hist = f.Get("Root__h_Common_LHEWeight_mg_reweighting_times_genWeight")

#for var in ["mVVV", "HT", "ST", "MET", "mVVV_reco"]:
#    stack_effs(c,[ROOT.TEfficiency(f.Get("allHad_passHLT_PFHT1050__%s"%var),f.Get("allHad__%s"%var)),  ROOT.TEfficiency(f.Get("allHad_passHLT_AK8PFJet500__%s"%var),f.Get("allHad__%s"%var)), ROOT.TEfficiency(f.Get("allHad_passHLT_AK8PFHT800_TrimMass50__%s"%var),f.Get("allHad__%s"%var)),  ROOT.TEfficiency(f.Get("allHad_passHLT_AK8PFJet400_TrimMass30__%s"%var),f.Get("allHad__%s"%var)),  ROOT.TEfficiency(f.Get("allHad_ORTrigger__%s"%var),f.Get("allHad__%s"%var))], ["HLT_PFHT1050", "HLT_AK8PFJet500", "HLT_AK8PFHT800_TrimMass50", "HLT_AK8PFJet400_TrimMass30", "OR"], var, outdir+"/trigger_eff_%s.pdf"%var)

#for var in ["mVVV", "HT", "ST", "MET", "mVVV_reco"]:
#    stack_effs(c,[ROOT.TEfficiency(f.Get("allHad_passHLT_PFHT1050__%s"%var),f.Get("allHad__%s"%var)),  ROOT.TEfficiency(f.Get("allHad_passHLT_AK8PFJet500__%s"%var),f.Get("allHad__%s"%var)), ROOT.TEfficiency(f.Get("allHad_passHLT_AK8PFHT800_TrimMass50__%s"%var),f.Get("allHad__%s"%var)),  ROOT.TEfficiency(f.Get("allHad_passHLT_AK8PFJet400_TrimMass30__%s"%var),f.Get("allHad__%s"%var)),  ROOT.TEfficiency(f.Get("allHad_ORTrigger__%s"%var),f.Get("allHad__%s"%var))], ["HLT_PFHT1050", "HLT_AK8PFJet500", "HLT_AK8PFHT800_TrimMass50", "HLT_AK8PFJet400_TrimMass30", "OR"], var, outdir+"/trigger_eff_%s.pdf"%var)



#stack_hists(c, sumw_hist, [f.Get("allHad__n_b_loose"), f.Get("allHad__n_b_medium"), f.Get("allHad__n_b_tight")], ["loose","medium","tight"], "number of b-tags", "number of events", outdir+"/btags.pdf", drawopt="p")

#stack_hists(c, sumw_hist, [f.Get("allHad__FatJet_n_loose"), f.Get("allHad__FatJet_n_medium"), f.Get("allHad__FatJet_n_tight")], ["loose","medium","tight"], "number of fatjets passing tag", "number of events", outdir+"/fatjet_tags.pdf", drawopt="p")

#stack_hists(c, sumw_hist, [f.Get("allHad__FatJet_tau21"), f.Get("allHad__FatJet_tau32")], ["#tau_{21}", "#tau_{32}"], "subjettiness", "number of jets", outdir+"/fatjet_tau21tau32.pdf")

#stack_hists(c, sumw_hist, [f.Get("allHad__Jet_pt_0"), f.Get("allHad__Jet_pt_1"), f.Get("allHad__Jet_pt_2"), f.Get("allHad__Jet_pt_3"), f.Get("allHad__Jet_pt_4")], ["Jet 0", "Jet 1", "Jet 2", "Jet 3", "Jet 4"], "p_{T} [GeV]", "number of events", outdir+"/jet_pt.pdf")

#stack_hists(c, sumw_hist, [f.Get("allHad__Jet_eta_0"), f.Get("allHad__Jet_eta_1"), f.Get("allHad__Jet_eta_2"), f.Get("allHad__Jet_eta_3"), f.Get("allHad__Jet_eta_4")], ["Jet 0", "Jet 1", "Jet 2", "Jet 3", "Jet 4"], "eta", "number of events", outdir+"/jet_eta.pdf")

#stack_hists(c, sumw_hist, [f.Get("allHad__FatJet_pt_0"), f.Get("allHad__FatJet_pt_1"), f.Get("allHad__FatJet_pt_2"), f.Get("allHad__FatJet_pt_3")], ["FatJet 0", "FatJet 1", "FatJet 2", "FatJet 3"], "p_{T} [GeV]", "number of events", outdir+"/fatjet_pt.pdf")

#stack_hists(c, sumw_hist, [f.Get("allHad__FatJet_eta_0"), f.Get("allHad__FatJet_eta_1"), f.Get("allHad__FatJet_eta_2"), f.Get("allHad__FatJet_eta_3")], ["FatJet 0", "FatJet 1", "FatJet 2", "FatJet 3"], "eta", "number of events", outdir+"/fatjet_eta.pdf")

#stack_hists(c, sumw_hist, [f.Get("allHad__FatJet_M_0"), f.Get("allHad__FatJet_M_1"), f.Get("allHad__FatJet_M_2"), f.Get("allHad__FatJet_M_3")], ["FatJet 0", "FatJet 1", "FatJet 2", "FatJet 3"], "mass", "number of events", outdir+"/fatjet_M.pdf")

#for var in ["msoftdrop","Ttag","Zbbtag","Ztag","Wtag", "tau21"]:
#    stack_hists(c, sumw_hist, [f.Get("allHad__FatJet_loose_%s"%var), f.Get("allHad__FatJet_medium_%s"%var), f.Get("allHad__FatJet_tight_%s"%var)], ["loose","medium","tight"], var, "number of events", outdir+"/fatjet_tags_%s.pdf"%var)


#for var in ["mVVV", "HT", "ST", "MET", "FatJet_n_medium", "FatJet_pt_0", "FatJet_M_0", "gen_vvv_pt0", "mVVV_reco", "gen_vvv_eta0", "Jet_ID"]:
#    stack_hists(c, sumw_hist, [f.Get("SM__%s"%var), f.Get("allHad__%s"%var), f.Get("EFT_FT0_10__%s"%var),  f.Get("EFT_FT0_m5__%s"%var),  f.Get("EFT_FT0_m10__%s"%var)], ["SM", "EFT_FT0_5", "EFT_FT0_10", "EFT_FT0_m5", "EFT_FT0_m10"], var, "number of events", outdir+"/EFT_comp_%s.pdf"%var)

#for var in ["mVVV", "HT", "ST", "MET", "FatJet_n_medium", "FatJet_pt_0", "FatJet_M_0"]:
#    stack_hists(c, sumw_hist, [f.Get("allHad_mVVVg0__%s"%var), f.Get("allHad_mVVVg1000__%s"%var), f.Get("allHad_mVVVg2000__%s"%var), f.Get("allHad_mVVVg3000__%s"%var),  f.Get("allHad_mVVVg4000__%s"%var)], [ "0 < mVVV < 1000", "1000 < mVVV < 2000", "2000 < mVVV < 3000", "3000 < mVVV < 4000", "mVVV > 4000"], var, "number of events", outdir+"/mVVVcut_comp_%s.pdf"%var)

for var in ["mVVV", "HT", "ST", "MET", "FatJet_n_medium", "FatJet_pt_0", "FatJet_M_0", "NJets"]:
    stack_hists(c, sumw_hist, [f.Get("allHad_lowmVVV__%s"%var), f.Get("allHad_highmVVV__%s"%var)], [ " mVVV < 1000", " mVVV > 2000"], var, "number of events", outdir+"/mVVVHT_comp_%s.pdf"%var)

