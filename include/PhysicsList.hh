#ifndef TC_PHYSICS_LIST_HH 1
#define TC_PHYSICS_LIST_HH

#include "G4VUserPhysicsList.hh"

namespace TC {
	class PhysicsList : G4VUserPhysicsList {
		PhysicsList();
		~PhysicsList() = default;

		void ConstructParticle();
		void ConstructProcess();

	};
}

#endif // !TC_PHYSICS_LIST_HH 1
