#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <string>
#include <vector>

class Particle {
private:
    std::string name;
    //pointer
    //E,px,py,pz
    std::vector<double>* four_momentum;

public:
    //constructors and destructors
    //default constructor
    Particle();
    //parameterized constructor
    Particle(std::string p_name, double E, double px, double py, double pz);
    //Ro5
    //destructor
    ~Particle();
    //copy constructor
    Particle(const Particle& other);
    //copy assignment operator
    Particle& operator=(const Particle& other);
    //move constructor
    Particle(Particle&& other) noexcept;
    //move assignment operator
    Particle& operator=(Particle&& other) noexcept;

    //getters and setters
    std::string getName() const { return name;}
    double getE() const;
    double getPx() const;
    double getPy() const;
    double getPz() const;

    void setName(std::string n);
    void setE(double E);
    void setPx(double px);
    void setPy(double py);
    void setPz(double pz);

    //sum 4-vecs
    Particle operator+(const Particle& other) const;
    //dot product
    double dotProduct(const Particle& other) const;
    //print
    void print() const;

};

#endif