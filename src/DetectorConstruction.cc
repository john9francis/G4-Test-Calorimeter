#include "DetectorConstruction.hh"
#include "SensitiveDetector.hh"

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
        G4double worldSize = 20 * cm;
        G4Material* vacuum = nist->FindOrBuildMaterial("G4_Galactic");

        auto solidWorld = new G4Box("World",
            worldSize,
            worldSize,
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
        G4double detZ = 1. * nm;

        G4Material* detectorMat = vacuum;

        G4ThreeVector detPos = G4ThreeVector(0, 0, 5 * cm);

        auto solidDetector = new G4Box("SolidDetector",
            detXY,
            detXY,
            detZ
        );

        auto logicDetector = new G4LogicalVolume(solidDetector,
            detectorMat,
            "LogicDetector"
        );


        auto physDetector = new G4PVPlacement(nullptr,
            detPos,
            logicDetector,
            "PhysDetector",
            logicWorld,
            false,
            0);


        return physWorld;
    }


    void DetectorConstruction::ConstructSDandField() {

        // Add our sensitive detector to the detector of our choice

        // Name our SD and our hitsCollection
        G4String SDname = "SD";
        G4String HCname = "SDHitsCollection";

        // Create our SD
        auto SD = new SensitiveDetector(SDname, HCname);

        // Add it to the SDManager Singleton
        G4SDManager::GetSDMpointer()->AddNewDetector(SD);

        // Assign SD to the volume we want
        SetSensitiveDetector("LogicDetector", SD);
    }
}