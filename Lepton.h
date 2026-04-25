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

    void print() const override;
};

class Neutrino : public Lepton {
private:
    //decide later

public:
    //constructor
    Neutrino(std::string flavour, bool is_antiparticle, double E, double px, double py, double pz);

    virtual ~Neutrino() override;

    void print() const override;
};

class Electron : public Lepton {
private:
    //decide later

public:
    //constructor
    Electron(bool is_antiparticle, double E, double px, double py, double pz);
    ~Electron() override = default;
    void print() const override;
};

class Muon : public Lepton {
private:
    //decide later
public:
    //constructor
    Muon(bool is_antiparticle, double E, double px, double py, double pz);
    ~Muon() override = default;
    void print() const override;
};

class Tau : public Lepton {
private:
    //decide later
public:
    //constructor
    Tau(bool is_antiparticle, double E, double px, double py, double pz);
    ~Tau() override = default;
    void print() const override;
};

#endif