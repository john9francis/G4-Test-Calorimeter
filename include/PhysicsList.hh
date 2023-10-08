#ifndef TC_PHYSICS_LIST_HH 1
#define TC_PHYSICS_LIST_HH

#include "G4VModularPhysicsList.hh"

namespace TC {
	class PhysicsList : public G4VModularPhysicsList {
	public:
		PhysicsList();
		~PhysicsList() = default;

		void ConstructParticle();
		void ConstructProcess();

	};
}

#endif // !TC_PHYSICS_LIST_HH 1
