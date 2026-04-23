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
    std::cout << "Calling Default Constructor" << std::endl;
}

//parameterized constructor
Particle::Particle(std::string name, double mass, double charge, bool is_antiparticle, double E, double px, double py, double pz)
    : name(name), mass(mass), charge(charge), is_antiparticle(is_antiparticle), 
      momentum(std::make_unique<FourMomentum>(E, px, py, pz)) {       
    std::cout << "Calling Parameterized Constructor" << std::endl;
}

//destructor
Particle::~Particle() {
    std::cout << "Calling Destructor" << std::endl;
}

//copy constructor
Particle::Particle(const Particle& other)
    : name(other.name), mass(other.mass), charge(other.charge), is_antiparticle(other.is_antiparticle),
      momentum(std::make_unique<FourMomentum>(*other.momentum)) {
    std::cout << "Calling Copy Constructor" << std::endl;
}

//copy assignment operator
Particle& Particle::operator=(const Particle& other) {
    std::cout << "Calling Copy Assignment Operator" << std::endl;
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
    std::cout << "Calling Move Constructor" << std::endl;
}

//move assignment operator
Particle& Particle::operator=(Particle&& other) noexcept {
    std::cout <<"Calling Move Assignment Operator" << std::endl;
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


