#ifndef TC_SENSITIVE_DETECTOR_HH
#define TC_SENSITIVE_DETECTOR_HH

#include "HitsCollection.hh"

#include "G4SDManager.hh"
#include "G4Step.hh"

namespace TC {
	class SensitiveDetector : public G4VSensitiveDetector {
	public:
		SensitiveDetector(const G4String& name, 
						  const G4String& hitsCollectionName);
		~SensitiveDetector() override = default;

		void Initialize(G4HCofThisEvent*) override;
		G4bool ProcessHits(G4Step*, G4TouchableHistory*) override;
		void EndOfEvent(G4HCofThisEvent*) override;

	private:
		HitsCollection* fHitsCollection = nullptr;


	};

}
#endif // !TC_SENSITIVE_DETECTOR_HH
