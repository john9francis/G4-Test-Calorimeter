#include "PhysicsList.hh"

#include "G4EmStandardPhysics.hh"

namespace TC {
	PhysicsList::PhysicsList() {
		RegisterPhysics(new G4EmStandardPhysics());
	}

	void PhysicsList::ConstructParticle() {

	}

	void PhysicsList::ConstructProcess() {

	}
}