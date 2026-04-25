#include "FourMomentum.h"
#include <iostream>
#include <stdexcept>

FourMomentum::FourMomentum(double E, double x, double y, double z) : px(x), py(y), pz(z) {
    set_energy(E);
}

void FourMomentum::set_energy(double E) {
    if (E < 0) throw std::invalid_argument("Energy cannot be negative");
    this->E = E;
}

//physics
//sum 4-vecs
FourMomentum FourMomentum::operator+(const FourMomentum& other) const {
    return FourMomentum(get_energy() + other.get_energy(), get_px() + other.get_px(), get_py() + other.get_py(), get_pz() + other.get_pz());
}

//dot product
double FourMomentum::dot_product(const FourMomentum& other) const {
    double spatial = (get_px() * other.get_px()) + (get_py() * other.get_py()) + (get_pz() * other.get_pz());
    return (get_energy() * other.get_energy()) - spatial;
}

//setters and getters
double FourMomentum::get_energy() const { return E; }
double FourMomentum::get_px() const { return px; }
double FourMomentum::get_py() const { return py; }
double FourMomentum::get_pz() const { return pz; }

void FourMomentum::set_px(double px) { this->px = px; }
void FourMomentum::set_py(double py) { this->py = py; }
void FourMomentum::set_pz(double pz) { this->pz = pz; }

std::ostream& operator<<(std::ostream& os, const FourMomentum& m) {
    os << "(" << m.get_energy() << ", " << m.get_px() << ", " << m.get_py() << ", " << m.get_pz() << ")";
    return os;
}