#include "G4UImanager.hh"
#include "G4UIExecutive.hh"
#include "G4RunManager.hh"

#include "G4VisManager.hh"
#include "G4VisExecutive.hh"

#include "DetectorConstruction.hh"

using namespace TC;

int main(int argc, char** argv)
{
	// Start (or don't) a UI
	G4UIExecutive* ui = nullptr;
	if (argc == 1) {
		ui = new G4UIExecutive(argc, argv);
	}

	// get pointer to UI manager
	G4UImanager* UImanager = G4UImanager::GetUIpointer();

	// Set required initialization classes
	G4RunManager* runManager = new G4RunManager();
	runManager->SetUserInitialization(new DetectorConstruction());

	// set vismanager
	G4VisManager* visManager = new G4VisExecutive;
	visManager->Initialize();

	// Run macro or start UI
	if (!ui) {
		// batch mode
		G4String command = "/control/execute ";
		G4String fileName = argv[1];
		UImanager->ApplyCommand(command + fileName);
	}
	else {
		// use UI
		ui->SessionStart();
		delete ui;
	}

	delete runManager;
	delete visManager;
	return 0;
}