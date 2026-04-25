#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "FourMomentum.h"

class Particle {
protected:
    double mass;
    double charge;
    bool is_antiparticle;
    std::unique_ptr<FourMomentum> momentum;

public:
    //constructors and destructors
    //default constructor
    Particle();
    //parameterized constructor
    Particle(double mass, double charge, bool is_antiparticle, double E, double px, double py, double pz);
    
    //Ro5
    //destructor
    virtual ~Particle();
    //copy constructor
    Particle(const Particle& other);
    //copy assignment operator
    Particle& operator=(const Particle& other);
    //move constructor
    Particle(Particle&& other) noexcept;
    //move assignment operator
    Particle& operator=(Particle&& other) noexcept;

    double get_energy() const { return momentum->get_energy(); }

    //antiparticle
    double get_charge() const { return is_antiparticle ? -charge : charge; }

    friend std::ostream& operator<<(std::ostream& os, const Particle& p);

    virtual void print() const;

    friend FourMomentum operator+(const Particle& p1, const Particle& p2);
    friend double dot_product(const Particle& p1, const Particle& p2);
};

#endif