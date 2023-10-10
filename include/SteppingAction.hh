#ifndef TC_STEPPING_ACTION_HH
#define TC_STEPPING_ACTION_HH

#include "G4UserSteppingAction.hh"

namespace TC {
	class SteppingAction : G4UserSteppingAction {
	public:
		SteppingAction();
		~SteppingAction();

		void UserSteppingAction(const G4Step*) override;
	};
}
#endif // !TC_STEPPING_ACTION_HH
