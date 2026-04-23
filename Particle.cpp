#include "Particle.h"

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <cmath>

//default constructor
Particle::Particle() : mass(0), charge(0), is_antiparticle(false), name("unknown"), momentum(std::make_unique<FourMomentum>(0.0, 0.0, 0.0, 0.0)) {
    std::cout << "Calling Default Constructor" << std::endl;
}

//parameterized constructor
Particle::Particle(std::string name, double mass, double q, bool anti, double E, double px, double py, double pz)
    : mass(mass), charge(q), is_antiparticle(anti), name(name), 
      momentum(std::make_unique<FourMomentum>(E, px, py, pz)) {       
    std::cout << "Calling Parameterized Constructor" << std::endl;
}

//destructor
Particle::~Particle() {
    std::cout << "Calling Destructor" << std::endl;
}

//copy constructor
Particle::Particle(const Particle& other) : name(other.name) {
    std::cout << "Calling Copy Constructor" << std::endl;
    four_momentum = new std::vector<double>(*other.four_momentum);
}

//copy assignment operator
Particle& Particle::operator=(const Particle& other) {
    std::cout << "Calling Copy Assignment Operator" << std::endl;
    if (this == &other) return *this; // self-assignment check

    delete four_momentum;

    name = other.name;
    four_momentum = new std::vector<double>(*other.four_momentum);

    return *this;
}

//move constructor
Particle::Particle(Particle&& other) noexcept : name(std::move(other.name)), four_momentum(other.four_momentum) {
    std::cout << "Calling Move Constructor" << std::endl;
    other.four_momentum = nullptr; // prevent double delete
}

//move assignment operator
Particle& Particle::operator=(Particle&& other) noexcept {
    std::cout <<"Calling Move Assignment Operator" << std::endl;
    if (this == &other) return *this;

    delete four_momentum;

    name = std::move(other.name);
    four_momentum = other.four_momentum;
    other.four_momentum = nullptr;

    return *this;
}


