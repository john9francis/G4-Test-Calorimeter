#include "DetectorConstruction.hh"

#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4NistManager.hh"
#include "G4LogicalVolume.hh"

namespace TC {
    G4VPhysicalVolume* DetectorConstruction::Construct() {
        // Get nist material manager
        G4NistManager* nist = G4NistManager::Instance();


        // Start with constructing the world:
        G4double worldSize = 1 * m;
        G4Material* vacuum = nist->FindOrBuildMaterial("G4_Galactic");

        auto solidWorld = new G4Box("World",
            worldSize / 2,
            worldSize / 2,
            worldSize);

        auto logicWorld = new G4LogicalVolume(solidWorld,
            vacuum,
            "World");

        auto physWorld = new G4PVPlacement(nullptr,
            G4ThreeVector(),
            logicWorld,
            "World",
            nullptr,
            false,
            0);


        // create our detector
        G4double detXY = 10. * cm;
        G4double detZ = 5. * cm;
        G4Material* lead = nist->FindOrBuildMaterial("G4_Pb");
        G4ThreeVector detPos = G4ThreeVector(0, 0, 5 * cm);

        auto solidDetector = new G4Box("Detector",
            detXY,
            detXY,
            detZ
        );

        auto logicDetector = new G4LogicalVolume(solidDetector,
            lead,
            "Detector"
        );

        auto physDetector = new G4PVPlacement(nullptr,
            detPos,
            logicDetector,
            "Detector",
            logicWorld,
            false,
            0);


        return physWorld;
    }
}