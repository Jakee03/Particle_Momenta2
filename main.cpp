#include <iostream>
#include <vector>
#include <utility>
#include "Particle.h"
#include "FourMomentum.h"
#include "Lepton.h"

int main() {
    //container of base class pointers
    std::vector<std::unique_ptr<Particle>> particles;
    //2e, 4m, anti e, anti m, m neu, e neu, tau, anti tau
    particles.push_back(std::make_unique<Electron>(false, 100.0, 10.0, 0.0, 0.0));
    particles.push_back(std::make_unique<Electron>(false, 150.0, 15.0, 0.0, 0.0));

    particles.push_back(std::make_unique<Muon>(false, 200.0, 20.0, 0.0, 0.0));
    particles.push_back(std::make_unique<Muon>(false, 230.0, 10.0, 0.0, 0.0));
    particles.push_back(std::make_unique<Muon>(false, 100.0, 15.0, 0.0, 0.0));
    particles.push_back(std::make_unique<Muon>(false, 90.0, 60.0, 0.0, 0.0));

    particles.push_back(std::make_unique<Electron>(true, 150.0, 15.0, 0.0, 0.0));
    particles.push_back(std::make_unique<Muon>(true, 90.0, 60.0, 0.0, 0.0));

    particles.push_back(std::make_unique<Neutrino>("Muon", false, 10.0, 5.0, 0.0, 0.0));
    particles.push_back(std::make_unique<Neutrino>("Electron", false, 20.0, 10.0, 0.0, 0.0));

    particles.push_back(std::make_unique<Tau>(false, 300.0, 30.0, 0.0, 0.0));
    particles.push_back(std::make_unique<Tau>(true, 350.0, 35.0, 0.0, 0.0));

    std::cout << "Printing Particles: " <<std::endl;
    for (const auto& p : particles) {
        p->print();
        std::cout << "-----------------" << std::endl;
    }

    return 0;
}