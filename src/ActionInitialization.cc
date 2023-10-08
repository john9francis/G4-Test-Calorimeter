#include "ActionInitialization.hh"

#include "PrimaryGeneratorAction.hh"

namespace TC {
	void ActionInitialization::Build() const {
		SetUserAction(new PrimaryGeneratorAction());
	}

	void ActionInitialization::BuildForMaster() const {

	}
}