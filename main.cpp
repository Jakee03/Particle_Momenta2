#include <iostream>
#include <vector>
#include <utility>
#include "Particle.h"
#include "FourMomentum.h"
#include "Lepton.h"

int main() {
    //container of base class pointers
    std::vector<std::unique_ptr<Particle>> particles;

    particles.push_back(std::make_unique<Electron>(false, 100.0, 10.0, 0.0, 0.0));    particles.push_back(std::make_unique<Neutrino>("Tau", false, 50, 0, 0, 0));
    particles.push_back(std::make_unique<Muon>(true, 200.0, 20.0, 0.0, 0.0));
    particles.push_back(std::make_unique<Tau>(false, 300.0, 30.0, 0.0, 0.0));

    std::cout << "Printing Particles: " <<std::endl;
    for (const auto& p : particles) {
        p->print();
        std::cout << "-----------------" << std::endl;
    }

    return 0;
}