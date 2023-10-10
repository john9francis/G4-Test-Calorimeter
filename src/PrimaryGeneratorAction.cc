#include "PrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"

#include "Randomize.hh"
#include "globals.hh"



namespace TC
{
	PrimaryGeneratorAction::PrimaryGeneratorAction() {
		fParticleGun = new G4ParticleGun();

		// define particle properties
		G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
		const G4String& particleName = "gamma";
		G4ParticleDefinition* particle = particleTable->FindParticle(particleName);
		fParticleGun->SetParticleDefinition(particle);

		G4ThreeVector momentumDirection = G4ThreeVector(0, 0, 1);
		fParticleGun->SetParticleMomentumDirection(momentumDirection);

		G4double energy = 5 * MeV;
		fParticleGun->SetParticleEnergy(energy);

		G4ThreeVector position = G4ThreeVector(0, 0, -5 * cm);
		fParticleGun->SetParticlePosition(position);


	}

	PrimaryGeneratorAction::~PrimaryGeneratorAction() {
		delete fParticleGun;
	}

	void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event)
	{
		fParticleGun->GeneratePrimaryVertex(event);
	}
}