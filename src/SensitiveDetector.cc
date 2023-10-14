#include "SensitiveDetector.hh"
#include "G4UnitsTable.hh"

namespace TC {
	SensitiveDetector::SensitiveDetector(const G4String& name)
		: G4VSensitiveDetector(name) { }

	SensitiveDetector::~SensitiveDetector() { }

	G4bool SensitiveDetector::ProcessHits(G4Step* aStep, G4TouchableHistory*) {
		G4double energy = aStep->GetTotalEnergyDeposit();
		G4ThreeVector position = aStep->GetPreStepPoint()->GetPosition();

		G4cout 
			<< "Energy: " 
			<< G4BestUnit(energy, "Energy") 
			<< " at position: " 
			<< G4BestUnit(position, "Length") 
			<< G4endl;
	}
}