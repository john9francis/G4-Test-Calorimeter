#include "PrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"

namespace TC {
	PrimaryGeneratorAction::PrimaryGeneratorAction() {
		fParticleGun = new G4ParticleGun();

		const G4String& particleName = "gamma";
		G4ThreeVector momentumDirection = G4ThreeVector(0, 0, 1);
		G4ThreeVector particlePosition = G4ThreeVector();
		G4double particleEnergy = 6 * MeV;

		// default particle kinematic
		G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
		G4ParticleDefinition* particle = particleTable->FindParticle(particleName);

		// set the gun's settings
		fParticleGun->SetParticleDefinition(particle);

		fParticleGun->SetParticlePosition(particlePosition);
		fParticleGun->SetParticleMomentumDirection(momentumDirection);
		fParticleGun->SetParticleEnergy(particleEnergy);
	}

	PrimaryGeneratorAction::~PrimaryGeneratorAction() {
		delete fParticleGun;
	}

	void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) {
		fParticleGun->GeneratePrimaryVertex(anEvent);
	}


}