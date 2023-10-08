#ifndef TC_DETECTOR_CONSTRUCTION_HH 1
#define TC_DETECTOR_CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4LogicalVolume.hh"

namespace TC {
	class DetectorConstruction : public G4VUserDetectorConstruction {
	public:
		DetectorConstruction() = default;
		~DetectorConstruction() = default;

		G4VPhysicalVolume* Construct();
	};
}
#endif // !TC_DETECTOR_CONSTRUCTION_HH 1
