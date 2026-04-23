#include <iostream>
#include <vector>
#include <utility>
#include "Particle.h"
#include "FourMomentum.h"
#include "Lepton.h"

int main() {
    //container of base class pointers
    std::vector<std::unique_ptr<Particle>> particles;

    particles.push_back(std::make_unique<Lepton>("Muon", 105.6, -1.0, false, 200, 10, 0, 0));
    particles.push_back(std::make_unique<Neutrino>("Tau", false, 50, 0, 0, 0));

    std::cout << "Printing Particles: " <<std::endl;
    for (const auto& p : particles) {
        p->print();
        std::cout << "-----------------" << std::endl;
    }

    return 0;
}