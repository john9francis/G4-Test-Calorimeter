#ifndef TC_SENSITIVE_DETECTOR_HH
#define TC_SENSITIVE_DETECTOR_HH

#include "G4SDManager.hh"
#include "G4Step.hh"

namespace TC {
	class SensitiveDetector : public G4VSensitiveDetector {
	public:
		SensitiveDetector(const G4String& name);
		~SensitiveDetector();

		G4bool ProcessHits(G4Step*, G4TouchableHistory*);
		
	};

}
#endif // !TC_SENSITIVE_DETECTOR_HH
