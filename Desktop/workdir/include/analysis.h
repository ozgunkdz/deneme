#ifndef ANALYSIS_H_
#define ANALYSIS_H_


#ifdef __CLING__

R__LOAD_LIBRARY(libDelphes)
#include "classes/DelphesClasses.h"
#include "external/ExRootAnalysis/ExRootTreeReader.h"
#include "external/ExRootAnalysis/ExRootResult.h"


#endif

#include "deltaR.h"

class Analysis{

public:
     
    char dataLocation1[10000];
    char dataLocation2[10000];
    char dataLocation3[10000];
    double crossSection;
    double luminosity;
    
    char dataName[1000];
    char treeName[1000];
    

	/////////////// Set Data Location 1 ///////////////		    
    void setDataLocation1 (char *location1)
    {
		strcpy(dataLocation1, location1);
		cout << "----------------------------------------------------------------------" << endl;
		cout << " Location 1 were set : " << dataLocation1 << endl; 
	}
	/////////////// Set Data Location 2 ///////////////		
	void setDataLocation2 (char *location2)
    {
		strcpy(dataLocation2, location2);
		cout << "----------------------------------------------------------------------" << endl;
		cout << " Location 2 were set : " << dataLocation2 << endl;  
	}
	/////////////// Set Data Location 3 ///////////////	
	void setDataLocation3 (char *location3)
    {
		strcpy(dataLocation3, location3);
		cout << "----------------------------------------------------------------------" << endl;
		cout << " Location 3 were set : " << dataLocation3 << endl; 
	}
	/////////////// Set Cross Section ///////////////	
	void setCrossSection (double crossSec)
    {
		crossSection = crossSec;
		cout << "----------------------------------------------------------------------" << endl;
		cout << " CrossSection (pb) were set : " << crossSection << endl; 
	}
	/////////////// Set Luminosity ///////////////			
	void setLuminosity (double lum)
    {
		luminosity = lum;
		cout << "----------------------------------------------------------------------" << endl;
		cout << " Luminosity were set : " << luminosity << endl; 
	}	
	/////////////// Set Tree Name ///////////////
	void setTreeName (char *tree)
    {
		strcpy(treeName, tree);
		cout << "----------------------------------------------------------------------" << endl;
		cout << " Tree Name : " << treeName << endl; 
	}	
	/////////////// Set Data Name ///////////////
	void setFileName (char *fileName)
    {
		strcpy(dataName, fileName);
		cout << "----------------------------------------------------------------------" << endl;
		cout << " Data will be written in " << dataName << endl; 
	}			

    void runAnalysis()
    {	
		double firstPhotonPT, firstPhotonEta, secondPhotonPT, secondPhotonEta, firstElectronPT, firstElectronEta, secondElectronPT, secondElectronEta, firstMuonPT, firstMuonEta, secondMuonPT, secondMuonEta, firstJetPT, firstJetEta, secondJetPT, secondJetEta, missingET, scalarHT = 0.0;
		double Hmass_aa, Hmass_ee, Hmass_mumu = 0.0;
		double dRe1ande2, dRe1anda1, dRe1anda2, dRe2anda1, dRe2anda2, dRmu1andmu2, dRmu1anda1, dRmu1anda2, dRmu2anda1, dRmu2anda2, dRa1anda2, dRj1andj2, dRj1anda1, dRj1anda2, dRj2anda1, dRj2anda2 = 0.0;
		int nPhoton, nMuon, nElectron, nJet = 0;	
	    int Charge;
	    double weight;
	   
		TFile *fDataFile = new TFile(dataName, "UPDATE");
		TTree *t1 = new TTree(treeName,"Pre-SelectedData");
		t1->Branch("weight", &weight);
		t1->Branch("nPhoton", &nPhoton);			
		t1->Branch("nMuon", &nMuon);
		t1->Branch("nElectron", &nElectron);	
		t1->Branch("nJet", &nJet);
        t1->Branch("firstPhotonPT", &firstPhotonPT);
		t1->Branch("firstPhotonEta", &firstPhotonEta);
		t1->Branch("secondPhotonPT", &secondPhotonPT);
		t1->Branch("secondPhotonEta", &secondPhotonEta);
        t1->Branch("firstElectronPT", &firstElectronPT);
        t1->Branch("firstElectronEta", &firstElectronEta);
        t1->Branch("secondElectronPT", &secondElectronPT);
        t1->Branch("secondElectronEta", &secondElectronEta);
        t1->Branch("firstMuonPT", &firstMuonPT);
        t1->Branch("firstMuonEta", &firstMuonEta);
        t1->Branch("secondMuonPT", &secondMuonPT);
        t1->Branch("secondMuonEta", &secondMuonEta);
        t1->Branch("firstJetPT", &firstJetPT);
        t1->Branch("firstJetEta", &firstJetEta);
        t1->Branch("secondJetPT", &secondJetPT);
        t1->Branch("secondJetEta", &secondJetEta);
        t1->Branch("missingET", &missingET);
		t1->Branch("scalarHT", &scalarHT);
		t1->Branch("Hmass_aa", &Hmass_aa);
        t1->Branch("Hmass_ee", &Hmass_ee);
        t1->Branch("Hmass_mumu", &Hmass_mumu);
        t1->Branch("dRe1ande2", &dRe1ande2);
        t1->Branch("dRe1anda1", &dRe1anda1);
        t1->Branch("dRe1anda2", &dRe1anda2);
        t1->Branch("dRe2anda1", &dRe2anda1);
        t1->Branch("dRe2anda2", &dRe2anda2);
        t1->Branch("dRmu1andmu2", &dRmu1andmu2);
        t1->Branch("dRmu1anda1", &dRmu1anda1);
        t1->Branch("dRmu1anda2", &dRmu1anda2);
        t1->Branch("dRmu2anda1", &dRmu2anda1);
        t1->Branch("dRmu2andmu1", &dRmu1anda2);
        t1->Branch("dRmu2andmu1", &dRmu1anda2);





		TChain chain("Delphes"); 
	
		if(strlen(dataLocation1) != 0)
		{
		  cout << " Accessed Location 1 : " << dataLocation1 << endl;
		  cout << "----------------------------------------------------------------------" << endl;
		  chain.Add(dataLocation1);   
		}
		if(strlen(dataLocation2) != 0)
		{
		  cout << " Accessed Location 2 : " << dataLocation2 << endl;
		  cout << "----------------------------------------------------------------------" << endl;
		  chain.Add(dataLocation2);   
		}
		if(strlen(dataLocation3) != 0)
		{
		  cout << " Accessed Location 3 : " << dataLocation3 << endl;
		  cout << "----------------------------------------------------------------------" << endl;
		  chain.Add(dataLocation3);   
		}	
	
		ExRootTreeReader *treeReader = new ExRootTreeReader(&chain);
		Long64_t numberOfEntries = treeReader->GetEntries();
  
		TClonesArray *branchJet         = treeReader->UseBranch("VLCjetR10N2");
		TClonesArray *branchElectron    = treeReader->UseBranch("Electron");
		TClonesArray *branchMuon        = treeReader->UseBranch("Muon");  
		TClonesArray *branchPhoton      = treeReader->UseBranch("Photon");
		TClonesArray *branchMissingET   = treeReader->UseBranch("MissingET");
		TClonesArray *branchScalarHT    = treeReader->UseBranch("ScalarHT");
  
		weight = crossSection * (Double_t)(luminosity/numberOfEntries);  	
		cout << " Obtained at " << luminosity << " luminosity, so possible weight is : " << weight << endl;
		cout << "----------------------------------------------------------------------" << endl;
		
		int muonNumber = 0;
		int electronNumber = 0;
		int photonNumber = 0;  
		int jetNumber = 0; 
		int missingETNumber = 0; 
		
		
		int muonNumberCounter = 0;
		int electronNumberCounter = 0;
		int photonNumberCounter = 0;
		int jetNumberCounter = 0;
		int missingETCounter = 0; 
		int eventCounter = 0;  	
		

		
		Photon *firstPhoton;
		Photon *secondPhoton;

        Electron *firstElectron;
        Electron *secondElectron;

        Muon *firstMuon;
        Muon *secondMuon;
        
        Jet *firstJet;
        Jet *secondJet;

		DeltaR *deltaRFinder = new DeltaR();
		
		for(int entry = 0; entry < numberOfEntries; entry++)
		{
		   treeReader->ReadEntry(entry);

		   if(entry % 100000 == 0)
           {
               cout << " # of event : " << entry << " is completed" << endl;
           }
		   Photon *firstPhoton = (Photon*) branchPhoton->At(0);
		   Photon *secondPhoton = (Photon*) branchPhoton->At(1);
		   Electron *firstElectron = (Electron*) branchElectron->At(0);
           Electron *secondElectron = (Electron*) branchElectron->At(1);
		   Muon *firstMuon = (Muon*) branchMuon->At(0);
           Muon *secondMuon = (Muon*) branchMuon->At(1);
           Jet *firstJet = (Jet*) branchJet->At(0);
           Jet *secondJet = (Jet*) branchJet->At(1);

		   muonNumberCounter = 0;
		   electronNumberCounter = 0;
		   photonNumberCounter = 0;
		   jetNumberCounter = 0;
		   missingETCounter = 0; 
			
		   muonNumberCounter = branchMuon->GetEntries();
		   muonNumber += muonNumberCounter;
			 
		   electronNumberCounter = branchElectron->GetEntries();
		   electronNumber += electronNumberCounter;  
	   
		   photonNumberCounter = branchPhoton->GetEntries();
		   photonNumber += photonNumberCounter;  
		
		   jetNumberCounter = branchJet->GetEntries();
		   jetNumber += jetNumberCounter;
		   
		   missingETCounter = branchMissingET->GetEntries();
		   missingETNumber += missingETCounter;  
		
		   MissingET *mET = (MissingET*) branchMissingET->At(0);
	       ScalarHT *sHT = (ScalarHT *) branchScalarHT->At(0);  
	
               
           nPhoton = photonNumberCounter;
           nElectron = electronNumberCounter;
           nMuon = muonNumberCounter;
           nJet = jetNumberCounter;
        
	  		 TLorentzVector firstPhotonFour, secondPhotonFour, firstElectronFour, secondElectronFour, firstMuonFour, secondMuonFour, firstJetFour, secondJetFour, HmassFour;
			    


            if ((nElectron >= 2) && (nPhoton > 0) && (firstElectron->Charge != secondElectron->Charge) && (nMuon == 0 & nJet == 0))
            {

                firstElectronFour.SetPtEtaPhiM(firstElectron->PT,firstElectron->Eta,firstElectron->Phi,0.000510998902);
                secondElectronFour.SetPtEtaPhiM(secondElectron->PT,secondElectron->Eta,secondElectron->Phi,0.000510998902);
                
                firstPhotonFour.SetPtEtaPhiM(firstPhoton->PT,firstPhoton->Eta,firstPhoton->Phi,0);
                secondPhotonFour.SetPtEtaPhiM(secondPhoton->PT,secondPhoton->Eta,secondPhoton->Phi,0);
                
                dRa1anda2 = deltaRFinder->getDeltaRfirstPhotonsecondPhoton(firstPhotonFour, secondPhotonFour);

                
                dRe1ande2 = deltaRFinder->getDeltaRfirstJetsecondJet(firstElectronFour, secondElectronFour);
                dRe1anda1 = deltaRFinder->getDeltaRfirstElectronfirstPhoton(firstElectronFour, firstPhotonFour);
                dRe1anda2 = deltaRFinder->getDeltaRfirstElectronsecondPhoton(firstElectronFour, secondPhotonFour);
                dRe2anda1 = deltaRFinder->getDeltaRsecondElectronfirstPhoton(secondElectronFour, firstPhotonFour);
                dRe2anda2 = deltaRFinder->getDeltaRsecondElectronsecondPhoton(secondElectronFour, secondPhotonFour);
                
                
                firstElectronPT = firstElectron->PT;
                firstElectronEta = firstElectron->Eta;
                secondElectronPT = secondElectron->PT;
                secondElectronEta = secondElectron->Eta;
                /*
                Hmass_ee = (firstElectron->P4()+secondElectron->P4()).M();
                Hmass_aa = (firstPhoton->P4()+secondPhoton->P4()).M();
                */
                Hmass_ee = (firstElectronFour + secondElectronFour).M();
                Hmass_aa = (firstPhoton->P4()+secondPhoton->P4()).M();


                nPhoton = photonNumberCounter;
                nElectron = electronNumberCounter;
                nMuon = muonNumberCounter;
                nJet = jetNumberCounter;
                
                missingET = mET-> MET;
                scalarHT = sHT->HT;
                
            }
            
            if ((nMuon >= 2) && (nPhoton > 0) && (firstMuon->Charge != secondMuon->Charge) && (nJet == 0 & nElectron == 0))
            {
                
                firstMuonFour.SetPtEtaPhiM(firstMuon->PT,firstMuon->Eta,firstMuon->Phi,0.105658389);
                secondMuonFour.SetPtEtaPhiM(secondMuon->PT,secondMuon->Eta,secondMuon->Phi,0.105658389);
                
                firstPhotonFour.SetPtEtaPhiM(firstPhoton->PT,firstPhoton->Eta,firstPhoton->Phi,0);
                secondPhotonFour.SetPtEtaPhiM(secondPhoton->PT,secondPhoton->Eta,secondPhoton->Phi,0);
                
                dRmu1andmu2 = deltaRFinder->getDeltaRfirstMuonsecondMuon(firstMuonFour, secondMuonFour);
                dRmu1anda1 = deltaRFinder->getDeltaRfirstMuonfirstPhoton(firstMuonFour, firstPhotonFour);
                dRmu1anda2 = deltaRFinder->getDeltaRfirstMuonsecondPhoton(firstMuonFour, secondPhotonFour);
                dRmu2anda1 = deltaRFinder->getDeltaRsecondMuonfirstPhoton(secondMuonFour, firstPhotonFour);
                dRmu2anda2 = deltaRFinder->getDeltaRsecondMuonsecondPhoton(secondMuonFour, secondPhotonFour);
                
                
                firstMuonPT = firstMuon->PT;
                firstMuonEta = firstMuon->Eta;
                secondMuonPT = secondMuon->PT;
                secondMuonEta = secondMuon->Eta;
                /*
                Hmass_aa = (firstPhoton->P4()+secondPhoton->P4()).M();
                Hmass_mumu = (firstMuon->P4()+secondMuon->P4()).M();
                */
                Hmass_mumu = (firstMuonFour + secondMuonFour).M();
                Hmass_aa = (firstPhoton->P4()+secondPhoton->P4()).M();

                
                nPhoton = photonNumberCounter;
                nElectron = electronNumberCounter;
                nMuon = muonNumberCounter;
                nJet = jetNumberCounter;
                
                missingET = mET-> MET;
                scalarHT = sHT->HT;
            }
            
            if ((nJet > 1) && (nPhoton > 0))
            {
                
                firstJetFour.SetPtEtaPhiM(firstJet->PT,firstJet->Eta,firstJet->Phi,firstJet->Mass);
                secondJetFour.SetPtEtaPhiM(secondJet->PT,secondJet->Eta,secondJet->Phi,secondJet->Mass);
                
                firstPhotonFour.SetPtEtaPhiM(firstPhoton->PT,firstPhoton->Eta,firstPhoton->Phi,0);
                secondPhotonFour.SetPtEtaPhiM(secondPhoton->PT,secondPhoton->Eta,secondPhoton->Phi,0);
                
                dRj1andj2 = deltaRFinder->getDeltaRfirstJetsecondJet(firstJetFour, secondJetFour);
                dRj1anda1 = deltaRFinder->getDeltaRfirstJetfirstPhoton(firstJetFour, firstPhotonFour);
                dRj1anda2 = deltaRFinder->getDeltaRfirstJetsecondPhoton(firstJetFour, secondPhotonFour);
                dRj2anda1 = deltaRFinder->getDeltaRsecondJetfirstPhoton(secondJetFour, firstPhotonFour);
                dRj2anda2 = deltaRFinder->getDeltaRsecondJetsecondPhoton(secondJetFour, secondPhotonFour);

                firstPhotonPT = firstPhoton->PT;
                firstPhotonEta = firstPhoton->Eta;
                secondPhotonPT = secondPhoton->PT;
                secondPhotonEta = secondPhoton->Eta;
                firstJetPT = firstJet->PT;
                firstJetEta = firstJet->Eta;
                secondJetPT = secondJet->PT;
                secondJetEta = secondJet->Eta;
                
                nPhoton = photonNumberCounter;
                nElectron = electronNumberCounter;
                nMuon = muonNumberCounter;
                nJet = jetNumberCounter;
                
                missingET = mET-> MET;
                scalarHT = sHT->HT;
                
            }
            
               t1->Fill();
			  
		}
	  cout << " Muon : " << muonNumber << " Electron : " << electronNumber << " Photon : " << photonNumber << " Jet : " << jetNumber << " Missing ET" << missingETNumber << endl; 
	  eventCounter = muonNumber = electronNumber = photonNumber = jetNumber = missingETNumber = 0;
	  t1->Write();
	  fDataFile->cd();
	  fDataFile->Write();
	  fDataFile->Close(); 		
    }

};
#endif
