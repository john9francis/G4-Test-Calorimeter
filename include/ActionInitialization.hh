#ifndef TC_ACTION_INIT_HH 1
#define TC_ACTION_INIT_HH

#include "G4VUserActionInitialization.hh"

namespace TC {
	class TCActionInitialization : G4VUserActionInitialization {
		TCActionInitialization();
		~ TCActionInitialization() = default;

		void Build();
		void BuildForMaster();
	};
}

#endif // !TC_ACTION_INIT_HH 1
