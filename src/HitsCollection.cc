
#include "HitsCollection.hh"

namespace TC {
	TCHit::TCHit() {
		
		// Set the energy and position to zero
		hEnergy = 0.;
		hPosition = G4ThreeVector();
	}

	void TCHit::Print() {
		G4cout
			<< "Energy: "
			<< G4BestUnit(hEnergy, "Energy")
			<< " "
			<< "Position: "
			<< G4BestUnit(hPosition.getX(), "Length")
			<< G4BestUnit(hPosition.getY(), "Length")
			<< G4BestUnit(hPosition.getZ(), "Length")
			<< G4endl;
	}

	// Methods to set the energy and position
	void TCHit::SetEnergy(G4double e) { hEnergy = e; }
	void TCHit::SetPos(G4ThreeVector p) { hPosition = p; }


	// Very simple HitsCollection, just a list to hold all our hits
	HitsCollection::HitsCollection(
		const G4String& name,
		const G4String& collectionName)
		: G4THitsCollection<TCHit>(name, collectionName) {}


}