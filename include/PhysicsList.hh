#ifndef TC_PHYSICS_LIST_HH
#define TC_PHYSICS_LIST_HH

#include "G4VModularPhysicsList.hh"

namespace TC {
	class PhysicsList : public G4VModularPhysicsList {
	public:
		PhysicsList();
		~PhysicsList() = default;

		virtual void ConstructParticle() override;
		virtual void ConstructProcess() override;

	};
}

#endif // !TC_PHYSICS_LIST_HH
