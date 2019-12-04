#ifndef DELTAR_H_
#define DELTAR_H_

class DeltaR{

public:
    
    TLorentzVector firstElectron;
    TLorentzVector secondElectron;
    TLorentzVector firstMuon;
    TLorentzVector secondMuon;
    TLorentzVector firstPhoton;
    TLorentzVector secondPhoton;
    TLorentzVector firstJet;
    TLorentzVector secondJet;
    
/*    double getDeltaRfirstElectronsecondElectron;
    double getDeltaRfirstMuonsecondMuon;
    double getDeltaRfirstJetsecondJet;
    double getDeltaRfirstPhotonsecondPhoton;
    double getDeltaRfirstElectronfirstPhoton;
    double getDeltaRfirstElectronsecondPhoton;
    double getDeltaRsecondElectronfirstPhoton;
    double getDeltaRsecondElectronsecondPhoton;
    
    double getDeltaRfirstMuonfirstPhoton;
    double getDeltaRfirstMuonsecondPhoton;
    double getDeltaRsecondMuonfirstPhoton;
    double getDeltaRsecondMuonsecondPhoton;
    
    double getDeltaRfirstJetfirstPhoton;
    double getDeltaRfirstJetsecondPhoton;
    double getDeltaRsecondJetfirstPhoton;
    double getDeltaRsecondJetsecondPhoton;*/

     
    double getDeltaRfirstElectronsecondElectron(TLorentzVector firstElectron, TLorentzVector secondElectron)
    {
  	 double dPhi;
  	 double dR;
    
         dPhi = firstElectron.Phi() - secondElectron.Phi();
         while (dPhi < -TMath::Pi()) dPhi += 2*TMath::Pi();
         while (dPhi >  TMath::Pi()) dPhi -= 2*TMath::Pi(); 
         
         dR = sqrt(dPhi*dPhi+(firstElectron.Eta() - secondElectron.Eta())*(firstElectron.Eta() - firstElectron.Eta()));
         
  	 return dR;         
    }
    
    double getDeltaRfirstMuonsecondMuon(TLorentzVector firstMuon, TLorentzVector secondMuon)
    {
  	 double dPhi;
  	 double dR;
    
         dPhi = firstMuon.Phi() - secondMuon.Phi();
         while (dPhi < -TMath::Pi()) dPhi += 2*TMath::Pi();
         while (dPhi >  TMath::Pi()) dPhi -= 2*TMath::Pi(); 
         
         dR = sqrt(dPhi*dPhi+(firstMuon.Eta() - secondMuon.Eta())*(firstMuon.Eta() - secondMuon.Eta()));
         
  	 return dR;         
    }
    
    double getDeltaRfirstJetsecondJet(TLorentzVector firstJet, TLorentzVector secondJet)
    {
        double dPhi;
        double dR;
        
        dPhi = firstJet.Phi() - secondJet.Phi();
        while (dPhi < -TMath::Pi()) dPhi += 2*TMath::Pi();
        while (dPhi >  TMath::Pi()) dPhi -= 2*TMath::Pi();
        
        dR = sqrt(dPhi*dPhi+(firstJet.Eta() - secondJet.Eta())*(firstJet.Eta() - secondJet.Eta()));
        
        return dR;
    }
    
    double getDeltaRfirstPhotonsecondPhoton(TLorentzVector firstPhoton, TLorentzVector secondPhoton)
    {
        double dPhi;
        double dR;
        
        dPhi = firstPhoton.Phi() - secondPhoton.Phi();
        while (dPhi < -TMath::Pi()) dPhi += 2*TMath::Pi();
        while (dPhi >  TMath::Pi()) dPhi -= 2*TMath::Pi();
        
        dR = sqrt(dPhi*dPhi+(firstPhoton.Eta() - secondPhoton.Eta())*(firstPhoton.Eta() - secondPhoton.Eta()));
        
        return dR;
    }
    
    double getDeltaRfirstElectronfirstPhoton(TLorentzVector firstElectron, TLorentzVector firstPhoton)
    {
        double dPhi;
        double dR;
        
        dPhi = firstElectron.Phi() - firstPhoton.Phi();
        while (dPhi < -TMath::Pi()) dPhi += 2*TMath::Pi();
        while (dPhi >  TMath::Pi()) dPhi -= 2*TMath::Pi();
        
        dR = sqrt(dPhi*dPhi+(firstElectron.Eta() - firstPhoton.Eta())*(firstElectron.Eta() - firstPhoton.Eta()));
        
        return dR;
    }

    double getDeltaRfirstElectronsecondPhoton(TLorentzVector firstElectron, TLorentzVector secondPhoton)
    {
        double dPhi;
        double dR;
        
        dPhi = firstElectron.Phi() - secondPhoton.Phi();
        while (dPhi < -TMath::Pi()) dPhi += 2*TMath::Pi();
        while (dPhi >  TMath::Pi()) dPhi -= 2*TMath::Pi();
        
        dR = sqrt(dPhi*dPhi+(firstElectron.Eta() - secondPhoton.Eta())*(firstElectron.Eta() - secondPhoton.Eta()));
        
        return dR;
    }
    
    double getDeltaRsecondElectronfirstPhoton(TLorentzVector secondElectron, TLorentzVector firstPhoton)
    {
        double dPhi;
        double dR;
        
        dPhi = secondElectron.Phi() - firstPhoton.Phi();
        while (dPhi < -TMath::Pi()) dPhi += 2*TMath::Pi();
        while (dPhi >  TMath::Pi()) dPhi -= 2*TMath::Pi();
        
        dR = sqrt(dPhi*dPhi+(secondElectron.Eta() - firstPhoton.Eta())*(secondElectron.Eta() - firstPhoton.Eta()));
        
        return dR;
    }

    double getDeltaRsecondElectronsecondPhoton(TLorentzVector secondElectron, TLorentzVector secondPhoton)
    {
        double dPhi;
        double dR;
        
        dPhi = secondElectron.Phi() - secondPhoton.Phi();
        while (dPhi < -TMath::Pi()) dPhi += 2*TMath::Pi();
        while (dPhi >  TMath::Pi()) dPhi -= 2*TMath::Pi();
        
        dR = sqrt(dPhi*dPhi+(secondElectron.Eta() - secondPhoton.Eta())*(secondElectron.Eta() - secondPhoton.Eta()));
        
        return dR;
    }

    double getDeltaRfirstMuonfirstPhoton(TLorentzVector firstMuon, TLorentzVector firstPhoton)
    {
        double dPhi;
        double dR;
        
        dPhi = firstMuon.Phi() - firstPhoton.Phi();
        while (dPhi < -TMath::Pi()) dPhi += 2*TMath::Pi();
        while (dPhi >  TMath::Pi()) dPhi -= 2*TMath::Pi();
        
        dR = sqrt(dPhi*dPhi+(firstMuon.Eta() - firstPhoton.Eta())*(firstMuon.Eta() - firstPhoton.Eta()));
        
        return dR;
    }
    
    double getDeltaRfirstMuonsecondPhoton(TLorentzVector firstMuon, TLorentzVector secondPhoton)
    {
        double dPhi;
        double dR;
        
        dPhi = firstMuon.Phi() - secondPhoton.Phi();
        while (dPhi < -TMath::Pi()) dPhi += 2*TMath::Pi();
        while (dPhi >  TMath::Pi()) dPhi -= 2*TMath::Pi();
        
        dR = sqrt(dPhi*dPhi+(firstMuon.Eta() - secondPhoton.Eta())*(firstMuon.Eta() - secondPhoton.Eta()));
        
        return dR;
    }
    
    double getDeltaRsecondMuonfirstPhoton(TLorentzVector secondMuon, TLorentzVector firstPhoton)
    {
        double dPhi;
        double dR;
        
        dPhi = secondMuon.Phi() - firstPhoton.Phi();
        while (dPhi < -TMath::Pi()) dPhi += 2*TMath::Pi();
        while (dPhi >  TMath::Pi()) dPhi -= 2*TMath::Pi();
        
        dR = sqrt(dPhi*dPhi+(secondMuon.Eta() - firstPhoton.Eta())*(secondMuon.Eta() - firstPhoton.Eta()));
        
        return dR;
    }
    
    double getDeltaRsecondMuonsecondPhoton(TLorentzVector secondMuon, TLorentzVector secondPhoton)
    {
        double dPhi;
        double dR;
        
        dPhi = secondMuon.Phi() - secondPhoton.Phi();
        while (dPhi < -TMath::Pi()) dPhi += 2*TMath::Pi();
        while (dPhi >  TMath::Pi()) dPhi -= 2*TMath::Pi();
        
        dR = sqrt(dPhi*dPhi+(secondMuon.Eta() - secondPhoton.Eta())*(secondMuon.Eta() - secondPhoton.Eta()));
        
        return dR;
    }
    
    double getDeltaRfirstJetfirstPhoton(TLorentzVector firstJet, TLorentzVector firstPhoton)
    {
        double dPhi;
        double dR;
        
        dPhi = firstJet.Phi() - firstPhoton.Phi();
        while (dPhi < -TMath::Pi()) dPhi += 2*TMath::Pi();
        while (dPhi >  TMath::Pi()) dPhi -= 2*TMath::Pi();
        
        dR = sqrt(dPhi*dPhi+(firstJet.Eta() - firstPhoton.Eta())*(firstJet.Eta() - firstPhoton.Eta()));
        
        return dR;
    }

    double getDeltaRfirstJetsecondPhoton(TLorentzVector firstJet, TLorentzVector secondPhoton)
    {
        double dPhi;
        double dR;
        
        dPhi = firstJet.Phi() - secondPhoton.Phi();
        while (dPhi < -TMath::Pi()) dPhi += 2*TMath::Pi();
        while (dPhi >  TMath::Pi()) dPhi -= 2*TMath::Pi();
        
        dR = sqrt(dPhi*dPhi+(firstJet.Eta() - secondPhoton.Eta())*(firstJet.Eta() - secondPhoton.Eta()));
        
        return dR;
    }
    
    double getDeltaRsecondJetfirstPhoton(TLorentzVector secondJet, TLorentzVector firstPhoton)
    {
        double dPhi;
        double dR;
        
        dPhi = secondJet.Phi() - secondPhoton.Phi();
        while (dPhi < -TMath::Pi()) dPhi += 2*TMath::Pi();
        while (dPhi >  TMath::Pi()) dPhi -= 2*TMath::Pi();
        
        dR = sqrt(dPhi*dPhi+(secondJet.Eta() - firstPhoton.Eta())*(secondJet.Eta() - firstPhoton.Eta()));
        
        return dR;
    }
    
    double getDeltaRsecondJetsecondPhoton(TLorentzVector secondJet, TLorentzVector secondPhoton)
    {
        double dPhi;
        double dR;
        
        dPhi = secondJet.Phi() - secondPhoton.Phi();
        while (dPhi < -TMath::Pi()) dPhi += 2*TMath::Pi();
        while (dPhi >  TMath::Pi()) dPhi -= 2*TMath::Pi();
        
        dR = sqrt(dPhi*dPhi+(secondJet.Eta() - secondPhoton.Eta())*(secondJet.Eta() - secondPhoton.Eta()));
        
        return dR;
    }
    
};
#endif
