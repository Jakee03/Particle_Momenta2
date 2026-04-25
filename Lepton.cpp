#include "Lepton.h"
#include <iostream>

//LEPTON IMPLEMENTATION

//default constructor
Lepton::Lepton() : Particle(), lepton_number(1) {}

//parameterized constructor
Lepton::Lepton(double mass, double charge, bool is_antiparticle, double E, double px, double py, double pz)
    : Particle(mass, charge, is_antiparticle, E, px, py, pz), lepton_number(1) {}

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
Neutrino::Neutrino(std::string flavour, bool anti, double E, double px, double py, double pz, bool interacted)
    : Lepton(0.0, 0.0, anti, E, px, py, pz), flavour(flavour), has_interacted(interacted) {}

Neutrino::~Neutrino() = default;

void Neutrino::print() const {
    Lepton::print();
    std::cout << " Type: " << flavour << " Neutrino | Has Interacted: " << (has_interacted ? "Yes" : "No") << std::endl;
}

//ELECTRON IMPLEMENTATION
    
Electron::Electron(bool anti, double E, double px, double py, double pz, double rad_length)
    : Lepton(0.511, -1.0, anti, E, px, py, pz), radiation_length(rad_length) {}

void Electron::print() const {
    Lepton::print();
    std::cout << " Type: " << (is_antiparticle ? "Anti-" : "") << "Electron | Radiation Length: " << radiation_length << " cm" << std::endl;
}

//MUON IMPLEMENTATION

Muon::Muon(bool anti, double E, double px, double py, double pz, bool isolated)
    : Lepton(105.7, -1.0, anti, E, px, py, pz), is_isolated(isolated) {}

void Muon::print() const {
    Lepton::print();
    std::cout << " Type: " << (is_antiparticle ? "Anti-" : "") << "Muon | Isolated: " << (is_isolated ? "Yes" : "No") << std::endl;
}

//TAU IMPLEMENTATION

Tau::Tau(bool anti, double E, double px, double py, double pz, std::string decay_mode)
    : Lepton(1776.8, -1.0, anti, E, px, py, pz), decay_mode(decay_mode) {}

void Tau::print() const {
    Lepton::print();
    std::cout << " Type: " << (is_antiparticle ? "Anti-" : "") << "Tau | Decay Mode: " << decay_mode << std::endl;
}