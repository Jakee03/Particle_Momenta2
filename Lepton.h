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
    Lepton(double mass, double charge, bool is_antiparticle, double E, double px, double py, double pz);

    //destructor
    virtual ~Lepton() override;

    //getter (for antiparticles)
    int get_lepton_number() const;

    void print() const override;
};

class Neutrino : public Lepton {
private:
    std::string flavour;
    bool has_interacted;

public:
    //constructor
    Neutrino(std::string flavour, bool is_antiparticle, double E, double px, double py, double pz, bool interacted);

    virtual ~Neutrino() override;

    void set_interacted(bool status);
    bool get_interacted() const;
    void print() const override;
};

class Electron : public Lepton {
private:
    double radiation_length;

public:
    //constructor
    Electron(bool is_antiparticle, double E, double px, double py, double pz, double rad_length);
    ~Electron() override = default;
    void set_radiation_length(double r1);
    double get_radiation_length() const;
    void print() const override;
};

class Muon : public Lepton {
private:
    bool is_isolated;
public:
    //constructor
    Muon(bool is_antiparticle, double E, double px, double py, double pz, bool isolated);
    ~Muon() override = default;
    void set_isolated(bool status);
    bool get_isolated() const;
    void print() const override;
};

class Tau : public Lepton {
private:
    std::string decay_mode;
public:
    //constructor
    Tau(bool is_antiparticle, double E, double px, double py, double pz, std::string decay_mode);
    ~Tau() override = default;
    void set_decay_mode(std::string mode);
    std::string get_decay_mode() const;
    void print() const override;
};

#endif