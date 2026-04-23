#include "Lepton.h"
#include <iostream>

//default constructor
Lepton::Lepton() : Particle(), lepton_number(1) {}

//parameterized constructor
Lepton::Lepton(std::string name, double mass, double charge, bool is_antiparticle, double E, double px, double py, double pz)
    : Particle(name, mass, charge, is_antiparticle, E, px, py, pz), lepton_number(1) {}

    