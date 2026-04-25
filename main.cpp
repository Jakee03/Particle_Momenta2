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
    particles.push_back(std::make_unique<Electron>(false, 100.0, 10.0, 5.0, 2.0));
    particles.push_back(std::make_unique<Electron>(false, 150.0, -5.0, 2.0, -1.0));

    particles.push_back(std::make_unique<Muon>(false, 500.0, 0.0, 100.0, 50.0));
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

    //sum 4-vecs of electrons
    FourMomentum electron_sum = *particles[0] + *particles[1];
    std::cout << "Sum of Electron 4-Momenta: " << electron_sum << std::endl;
    }

    //dot product of antielectron and antimuon
    double dot = dot_product(*particles[6], *particles[7]);
    std::cout << "Dot Product of Anti-Electron and Anti-Muon: " << dot << " MeV^2\n" << std::endl;

    //unique pointer for new electron and move its data
    std::cout << "Moving unique pointer ownership" << std::endl;
    std::unique_ptr<Electron> unique_e = std::make_unique<Electron>(false, 200.0, 20.0, 10.0, 5.0);
    std::unique_ptr<Electron> moved_e = std::move(unique_e);
    if (!unique_e) {
        std::cout << "Original unique pointer is now null. Data moved to new pointer.\n" << std::endl;
        std::cout << "Moved Electron Data: ";
        moved_e->print();
    }
    std::cout << std::endl;

    //shared pointer for a tauon owned by multiple variables
    std::cout << "Shared pointer for a Tauon" << std::endl;
    std::shared_ptr<Tau> shared_tau = std::make_shared<Tau>(false, 1776.8, 10.0, 0.0, 0.0);
    {
        std::shared_ptr<Tau> detector_view = shared_tau;
        std::cout << "Tau currently owned by " << shared_tau.use_count() << " variables" << std::endl;
        std::cout << "Detector view of Tau: ";
        detector_view->print();
    }
    std::cout << "After detector view goes out of scope, Tau owned by " << shared_tau.use_count() << " variable(s)" << std::endl;


    return 0;
}