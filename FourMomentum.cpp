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