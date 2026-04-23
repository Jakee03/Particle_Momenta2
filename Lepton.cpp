#include "Lepton.h"
#include <iostream>

//LEPTON IMPLEMENTATION

//default constructor
Lepton::Lepton() : Particle(), lepton_number(1) {}

//parameterized constructor
Lepton::Lepton(std::string name, double mass, double charge, bool is_antiparticle, double E, double px, double py, double pz)
    : Particle(name, mass, charge, is_antiparticle, E, px, py, pz), lepton_number(1) {}

//destructor
Lepton::~Lepton() = default;

//getter (lep no. flips for antis)
int Lepton::get_lepton_number() const {
    return is_antiparticle ? -lepton_number : lepton_number;
}

void Lepton::print() const {
    Particle::print();
    std::cout << " Family: Lepton | Lepton Number: " << get_lepton_number() << std::endl;
}

//NEUTRINO IMPLEMENTATION

//default constructor
Neutrino::Neutrino(std::string flavour, bool anti, double E, double px, double py, double pz)
    : Lepton(flavour + " neutrino", 0.0, 0.0, anti, E, px, py, pz) {}

Neutrino::~Neutrino() = default;

void Neutrino::print() const {
    Lepton::print();
    std::cout << " Type: Neutrino" << std::endl;
}