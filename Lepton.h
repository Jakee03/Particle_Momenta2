#ifndef LEPTON_H
#define LEPTON_H

#include "Particle.h"

//lepton inherits from particle
class Lepton : public Particle {
protected:
    int lepton_number;

public:
    //constructors
    Lepton();
    Lepton(std::string name, double mass, double charge, bool is_antiparticle, double E, double px, double py, double pz);

    //destructor
    virtual ~Lepton() override;

    //getter (for antiparticles)
    int get_lepton_number() const;
};

class Neutrino : public Lepton {
private:
    //decide later

public:
    //constructor
    Neutrino(std::string flavour, bool is_antiparticle, double E, double px, double py, double pz);

    virtual ~Neutrino() override;
};

#endif