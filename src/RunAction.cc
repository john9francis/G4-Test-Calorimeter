
#include "RunAction.hh"
#include "G4UnitsTable.hh"


namespace TC {

	RunAction::RunAction() {
		//fHepRepFile = new G4HepRepFile;
	}

	RunAction::~RunAction() {
		//delete fHepRepFile;

	}

	void RunAction::BeginOfRunAction(const G4Run* aRun) {
		G4cout << "Run begun" << G4endl;
	}

	void RunAction::EndOfRunAction(const G4Run* aRun) {
		G4cout << "Run ended" << G4endl;
	}
}