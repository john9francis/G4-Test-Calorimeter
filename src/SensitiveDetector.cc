#include "SensitiveDetector.hh"
#include "G4UnitsTable.hh"

namespace TC {
	SensitiveDetector::SensitiveDetector(const G4String& name,
										 const G4String& hitsCollectionName)
		: G4VSensitiveDetector(name) {

		// Add this SD's name to the hitsCollection
		// Note: this member variable comes from the base class
		// It can be helpful if we have several SD's.
		collectionName.insert(hitsCollectionName);
	}

	void SensitiveDetector::Initialize(G4HCofThisEvent* hce) {

		// Create hits collection
		fHitsCollection = new HitsCollection(SensitiveDetectorName, collectionName[0]);

		// Get hitsCollection id from the SDManager
		G4int hcID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);

		// add hitsCollection to the hc of this event
		hce->AddHitsCollection(hcID, fHitsCollection);


	}

	G4bool SensitiveDetector::ProcessHits(G4Step* aStep, G4TouchableHistory*) {
		
		// Only log energy if it's the first step in volume
		// Note: Returning true or false is only for our own purposes,
		// Geant4 doesn't really care what we return here. We just need to break execution.
		if (!aStep->IsFirstStepInVolume()) { return false; }

		// get the energy and position from the pre-step point
		// Note: the "step" is the time between 2 points. most of the information 
		// we are interested in is found at the point, not the step. 
		G4double energy = aStep->GetPreStepPoint()->GetTotalEnergy();
		G4ThreeVector position = aStep->GetPreStepPoint()->GetPosition();

		// create our Hit object and give it the information
		TCHit* hit = new TCHit();

		hit->SetEnergy(energy);
		hit->SetPos(position);

		// add our hit to the hitsCollection
		fHitsCollection->insert(hit);


		return true;
	}

	void SensitiveDetector::EndOfEvent(G4HCofThisEvent*) {

		// Get the number of hits in the hitsCollection
		G4int nofHits = fHitsCollection->entries();

		// loop through the hitsCollection and call each hit's print function
		for (G4int i = 0; i < nofHits; i++) (*fHitsCollection)[i]->Print();
	}
}