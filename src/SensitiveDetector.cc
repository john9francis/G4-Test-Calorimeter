#include "SensitiveDetector.hh"
#include "G4UnitsTable.hh"

namespace TC {
	SensitiveDetector::SensitiveDetector(const G4String& name,
										 const G4String& hitsCollectionName)
		: G4VSensitiveDetector(name) {
		// Set the name of this sd
		collectionName.insert(hitsCollectionName);
		G4cout << "SD Construct" << G4endl; // this works!
	}

	void SensitiveDetector::Initialize(G4HCofThisEvent* hce) {
		// Create hits collection

		fHitsCollection = new HitsCollection(SensitiveDetectorName, collectionName[0]);

		// Add hitsCollection to this event
		G4int hcID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);

		hce->AddHitsCollection(hcID, fHitsCollection);

		G4cout << "SD Init" << G4endl;


	}

	G4bool SensitiveDetector::ProcessHits(G4Step* aStep, G4TouchableHistory*) {
		G4double energy = aStep->GetTotalEnergyDeposit();
		G4ThreeVector position = aStep->GetPreStepPoint()->GetPosition();

		TCHit* hit = new TCHit();

		hit->SetEnergy(energy);
		hit->SetPos(position);

		fHitsCollection->insert(hit);

		G4cout << "SD Process" << G4endl;


		return true;
	}

	void SensitiveDetector::EndOfEvent(G4HCofThisEvent*) {
		// print all the hits

		G4int nofHits = fHitsCollection->entries();

		G4cout << "SD End" << G4endl;


		for (G4int i = 0; i < nofHits; i++) (*fHitsCollection)[i]->Print();
	}
}