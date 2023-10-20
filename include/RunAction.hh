#ifndef TC_RUN_ACTION_HH
#define TC_RUN_ACTION_HH

#include "G4UserRunAction.hh"

#include "G4HepRepFile.hh"


namespace TC {
	class RunAction : public G4UserRunAction {
	public:
		RunAction();
		~RunAction();

		void BeginOfRunAction(const G4Run*) override;
		void EndOfRunAction(const G4Run*) override;

	protected:
		G4HepRepFile* fHepRepFile;
	};
}

#endif // !TC_RUN_ACTION_HH
