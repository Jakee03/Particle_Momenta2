#include "Particle.h"

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <cmath>

//default constructor
Particle::Particle() : name("unknown"), four_momentum(new std::vector<double>(4, 0.0)) {
    std::cout << "Calling Default Constructor" << std::endl;
}

//parameterized constructor
Particle::Particle(std::string p_name, double E, double px, double py, double pz) {
    std::cout << "Calling Parameterised Constructor" << std::endl;
    if (E < 0) {
    throw std::invalid_argument("Energy cannot be negative");
}
    if (p_name != "electron" && p_name != "muon" && p_name != "tau") {
        throw std::invalid_argument("Invalid SM particle name. Must be electron, muon, or tau.");
}


    name = p_name;
    four_momentum = new std::vector<double>();
    four_momentum->push_back(E);
    four_momentum->push_back(px);
    four_momentum->push_back(py);
    four_momentum->push_back(pz);
}

//destructor
Particle::~Particle() {
    std::cout << "Calling Destructor" << std::endl;
    delete four_momentum;
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

//getters
double Particle::getE() const { return (*four_momentum)[0]; }
double Particle::getPx() const { return (*four_momentum)[1]; }
double Particle::getPy() const { return (*four_momentum)[2]; }
double Particle::getPz() const { return (*four_momentum)[3]; }

//setters

}
void Particle::setPx(double px) { (*four_momentum)[1] = px; }
void Particle::setPy(double py) { (*four_momentum)[2] = py; }
void Particle::setPz(double pz) { (*four_momentum)[3] = pz; }

