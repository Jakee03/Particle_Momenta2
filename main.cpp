/*
#include <iostream>
#include <vector>
#include <utility>
#include "Particle.h"

int main() {
    try {
        //test particles
        // 2 electrons, 4 muons, 2 taus
        std::vector<Particle> particles;
        particles.push_back(Particle("electron", 0.511, 0.1, 0.1, 0.1));
        particles.push_back(Particle("electron", 0.511, -0.1, 0.2, 0.0));
        
        particles.push_back(Particle("muon", 105.7, 10.0, 5.0, 2.0));
        particles.push_back(Particle("muon", 105.7, -20.0, 10.0, -5.0));
        particles.push_back(Particle("muon", 105.7, 15.0, -5.0, 3.0));
        particles.push_back(Particle("muon", 105.7, -10.0, 20.0, -2.0));
            
        particles.push_back(Particle("tau", 1776.8, 50.0, -10.0, 5.0));
        particles.push_back(Particle("tau", 1776.8, 40.0, 15.0, -5.0));

        std::cout << "\nTesting Particle Class Functions:\n" << std::endl;

        //sum 4-mom of the two electrons
        Particle electron_sum = particles[0] + particles[1];
        std::cout << "Summed electrons energy: " << electron_sum.getE() << " MeV" << std::endl;

        //dot product of 1st 2 muons
        double muon_dot = particles[2].dotProduct(particles[3]);
        std::cout << "Dot product of the first two muons: " << muon_dot << " (MeV^2)" << std::endl;

        //assignment operator test
        std::cout << "\nTesting Assignment Operator:\n" << std::endl;
        Particle electronAssign;
        electronAssign = particles[0];
        std::cout << "Assigned electron energy: " << electronAssign.getE() << " MeV" << std::endl;

        //copy constructor test 
        std::cout << "\nTesting Copy Constructor:\n" << std::endl;
        Particle muonCopy(particles[2]);
        std::cout << "Copied muon energy: " << muonCopy.getE() << " MeV" << std::endl;

        //move constructor test
        std::cout << "\nTesting Move Constructor:\n" << std::endl;
        Particle E("electron", 0.511, 0.5, 0.5, 0.5);
        Particle movedE(std::move(E));

        //move muon test
        std::cout << "\nTesting Move Assignment:\n" << std::endl;
        Particle M("muon", 105.7, 10.0, 5.0, 2.0);
        Particle targetM;
        targetM = std::move(M);

        std::cout << "\n End of Tests, starting cleanup...\n" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
*/