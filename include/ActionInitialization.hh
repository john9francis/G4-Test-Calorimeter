#ifndef TC_ACTION_INIT_HH
#define TC_ACTION_INIT_HH

#include "G4VUserActionInitialization.hh"

namespace TC {
	class ActionInitialization : public G4VUserActionInitialization {
	public:
		ActionInitialization() = default;
		~ActionInitialization() override = default;

	private:
		void Build() const override;
		void BuildForMaster() const override;
	};
}

#endif // !TC_ACTION_INIT_HH
