#include "G4UImanager.hh"
#include "G4UIExecutive.hh"
#include "G4UIterminal.hh"
#include "G4RunManager.hh"
#include "G4RunManagerFactory.hh"

#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4SDManager.hh"

#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "ActionInitialization.hh"

using namespace TC;

int main(int argc, char** argv)
{
	// Start (or don't) a UI
	G4UIExecutive* ui = nullptr;
	G4UIterminal* uiT = nullptr;

	if (argc == 1) {
		ui = new G4UIExecutive(argc, argv);
	}
	else {
		uiT = new G4UIterminal;
	}

	// get pointer to UI manager
	G4UImanager* UImanager = G4UImanager::GetUIpointer();

	// Set required initialization classes
	auto* runManager = G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default);
	runManager->SetUserInitialization(new PhysicsList());
	runManager->SetUserInitialization(new DetectorConstruction());
	runManager->SetUserInitialization(new ActionInitialization());

	// set verbose for SDManager singleton
	G4SDManager::GetSDMpointer()->SetVerboseLevel(1);

	// set vismanager
	G4VisManager* visManager = new G4VisExecutive;
	visManager->Initialize();

	/*
	// Run macro or start UI
	if (!ui) {
		// batch mode
		G4String command = "/control/execute ";
		G4String fileName = argv[1];
		UImanager->ApplyCommand(command + fileName);
	}
	else {
		// run visualization
		UImanager->ApplyCommand("/control/execute vis.mac");
		 
		// use UI
		ui->SessionStart();
		delete ui;
	}

	*/
	if (ui) {

		// Run visualization
		UImanager->ApplyCommand("/control/execute vis.mac");

		// use UI
		ui->SessionStart();
		delete ui;

	}
	else if (uiT) {

		// interactive terminal mode

		// initialize G4 kernal:
		runManager->Initialize();
		
		// Start the session
		uiT->SessionStart();
		delete uiT;
	}
	else {
		//Error
		G4cout << "Error: No UI Definied" << G4endl;
	}

	delete runManager;
	delete visManager;
	return 0;
}