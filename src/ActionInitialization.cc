#include "ActionInitialization.hh"

#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"

namespace TC {
	void ActionInitialization::Build() const {
		SetUserAction(new PrimaryGeneratorAction);
		SetUserAction(new RunAction);
	}

	void ActionInitialization::BuildForMaster() const {
		SetUserAction(new RunAction);
	}
}