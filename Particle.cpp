#include "Particle.h"
#include "FourMomentum.h"

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <memory>
#include <utility>
#include <cmath>

//default constructor
Particle::Particle() : name("unknown"), mass(0), charge(0), is_antiparticle(false), momentum(std::make_unique<FourMomentum>(0.0, 0.0, 0.0, 0.0)) {
}

//parameterized constructor
Particle::Particle(std::string name, double mass, double charge, bool is_antiparticle, double E, double px, double py, double pz)
    : name(name), mass(mass), charge(charge), is_antiparticle(is_antiparticle), 
      momentum(std::make_unique<FourMomentum>(E, px, py, pz)) {
    if (mass < 0) {
        throw std::invalid_argument("Particle mass cannot be negative.");
    }
    if (E < 0) {
        throw std::invalid_argument("Particle energy cannot be negative.");
    }

//destructor
Particle::~Particle() {
}

//copy constructor
Particle::Particle(const Particle& other)
    : name(other.name), mass(other.mass), charge(other.charge), is_antiparticle(other.is_antiparticle),
      momentum(std::make_unique<FourMomentum>(*other.momentum)) {
}

//copy assignment operator
Particle& Particle::operator=(const Particle& other) {
    if (this == &other) return *this; // self-assignment check

    name = other.name;
    mass = other.mass;
    charge = other.charge;
    is_antiparticle = other.is_antiparticle;

    //deep copy of momentum
    momentum = std::make_unique<FourMomentum>(*other.momentum);

    return *this;
}

//move constructor
Particle::Particle(Particle&& other) noexcept
 : name(std::move(other.name)), mass(other.mass), charge(other.charge), is_antiparticle(other.is_antiparticle),
   momentum(std::move(other.momentum)) {
}

//move assignment operator
Particle& Particle::operator=(Particle&& other) noexcept {
    if (this == &other) return *this;

    name = std::move(other.name);
    mass = other.mass;
    charge = other.charge;
    is_antiparticle = other.is_antiparticle;
    momentum = std::move(other.momentum);

    return *this;
}

//friend func
std::ostream& operator<<(std::ostream& os, const Particle& p) {
    os << p.name << " (Mass: " << p.mass << " MeV, Charge: " << p.get_charge() << ")";
    return os;
}

void Particle::print() const {
    std::cout << "Particle: " << name
                << "| Mass: " << mass << " MeV"
                << "| Charge: " << get_charge()
                << "| Energy: " << get_energy() << " MeV" << std::endl;
}

//friend func for 4-mom sum
FourMomentum operator+(const Particle& p1, const Particle& p2) {
    return *(p1.momentum) + *(p2.momentum);
}

//friend func for dot product
double dot_product(const Particle& p1, const Particle& p2) {
    return p1.momentum->dot_product(*p2.momentum);
}