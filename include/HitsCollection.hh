// includes Hit and HitsCollection objects



#ifndef TC_HIT_HH
#define TC_HIT_HH

#include "G4VHit.hh"
#include "G4ThreeVector.hh"

#include "G4ios.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

namespace TC {
	class TCHit : public G4VHit {
	public:
		TCHit();
		~TCHit() override = default;

		void Print() override;

		void SetEnergy(G4double e);
		void SetPos(G4ThreeVector p);

	private:
		G4double hEnergy;
		G4ThreeVector hPosition;
	};
}

#endif // !TC_HIT_HH

#ifndef TC_HITS_COLLECTION_HH
#define TC_HITS_COLLECTION_HH

#include "G4THitsCollection.hh"

namespace TC {
	class HitsCollection : public G4THitsCollection<TCHit> {
	public:
		HitsCollection(
			const G4String& name, 
			const G4String& collectionName);
	};
}
#endif // !TC_HITS_COLLECTION_HH
