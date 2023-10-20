#include "PhysicsList.hh"

#include "G4EmStandardPhysics.hh"

namespace TC {
	PhysicsList::PhysicsList() {

		// Register the physics we need
		RegisterPhysics(new G4EmStandardPhysics());
	}

	void PhysicsList::ConstructParticle() {
		G4VModularPhysicsList::ConstructParticle();
	}

	void PhysicsList::ConstructProcess() {
		G4VModularPhysicsList::ConstructProcess();
	}
}