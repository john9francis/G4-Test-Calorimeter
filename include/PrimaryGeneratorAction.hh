#ifndef TC_PRIMARY_GEN_HH 1
#define TC_PRIMARY_GEN_HH

#include "G4VUserPrimaryGeneratorAction.hh"

namespace TC {
	class PrimaryGeneratorAction : G4VUserPrimaryGeneratorAction {
		PrimaryGeneratorAction();
		~PrimaryGeneratorAction() = default;

		void GeneratePrimaries();
	};
}
#endif // !TC_PRIMARY_GEN_HH 1
