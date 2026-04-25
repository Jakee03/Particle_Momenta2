# Particle Physics Simulation: Assignment 5
**Author:** Jacob Fairham
**Student ID** 11074241

##Compilation Line

g++ -Wall -o  Assignment5 main.cpp Particle.cpp FourMomentum.cpp Lepton.cpp

This is a program designed to simulate basic Standard Model particles (electrons, muons, tauons) and their kinematics using four-momentum.

The Minkowski metric and natural units (c=1) are used in the calculations and both mass and energy must be non-negative.

How to use:
Particles used in this program must be defined in the main.cpp file in the particles vector. They must follow the format defined in their derived classes and the energy and mass must be non-negative.

Formatting:
- Neutrino(std::string flavour, bool anti, double E, double px, double py, double pz, bool interacted)
- Electron(bool anti, double E, double px, double py, double pz, double rad_length)
- Muon(bool anti, double E, double px, double py, double pz, bool isolated)
- Tau(bool anti, double E, double px, double py, double pz, std::string decay_mode)

Standard members are: anti (bool for if antiparticle), E (energy), px/y/z (momentum)

Additionally: neutrinos must contain their flavour and interaction state (bool), electrons must state their radiation length (e.g in detector material), muons must state if they are isolated (bool) and tauons must state their decay mode (hadronic/leptonic)

Example calculations can be found in the main function. The particles are called on as indices in the particles vector (e.g: particles[0] is the first particle defined) then, after calculations, the relevant information can be extracted via the getters defined in FourMomentum.cpp.

This program is designed to practice inheritance, smart pointers and friendship

To ensure memory safety, the "Rule of 5" was implemented:

- Destructor: Frees the allocated memory
- Copy Constructor: Performs a "deep copy" which allocates new memory and copies values so two objects don't share the same pointer
- Copy Assignment: Uses a self-assignment, cleans up existing memory and performs a deep copy
- Move Constructor: Transfers the pointer from a temporary object and nullifies the source
- Move Assignment: Cleans up existing resources and acquires the source's pointer

How this was built:
1. The foundation was copied from Assignment 4 since this is a continuation
2. The Particle class was split into Particle for physical properties and FourMomentum for maths then Lepton class was created
3. std::unique_ptr<FourMomentum> was introduced along with the Rule of 5 for memory management
4. Specialised classes created for Neutrino, Electron, Muon and Tau
5. Virtual print function implemented to enable polymorphism
6. is_antiparticle() bool added to flip the signs of charge and lepton number
7. Specific data members added to the leaf classes to distinguish them
8. Friend functions added and operator overloading to make program intuitive and maintain encapsulation
9. main.cpp edited from original code to test program functionality:
    - Virtual print function
    - Operator overload
    - Unique pointer transfer with std::move
    - Shared pointer use

Link to report:
https://docs.google.com/document/d/1IxH1A-2n6jaz3KGTYmjR5sva2l591BrYNpLLRtSLSqM/edit?usp=sharing