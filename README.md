# Particle Physics Simulation: Assignment 4
**Author:** Jacob Fairham

##Compilation Line

g++ -Wall -o  Assignment4 main.cpp Particle.h Particle.cpp

This is a program designed to simulate basic Standard Model particles (electrons, muons, tauons) and their kinematics using four-momentum.

The Minkowski metric and natural units (c=1) are used in the calculations and energy must be non-negative.

How to use:
Particles used in this program must be defined in the main.cpp file in the particles vector. They must follow the following format and the energy must be non-negative:

particles.push_back(Particle("electron", 0.511, 0.1, 0.1, 0.1));

Example calculations can be found in the main function. This includes ones with definitions in the class and those without. The particles are called on as indices in the particles vector (e.g: particles[0] is the first particle defined) then, after calculations, the relevant information can be extracted via the getters defined in Particle.cpp.

The program is designed to introduce and test a dynamically allocated std::vector via a pointer. The main function contains various tests to explore memory optimisation in C++.

To ensure memory safety, the "Rule of 5" was implemented:

- Destructor: Frees the allocated memory
- Copy Constructor: Performs a "deep copy" which allocates new memory and copies values so two objects don't share the same pointer
- Copy Assignment: Uses a self-assignment, cleans up existing memory and performs a deep copy
- Move Constructor: Transfers the pointer from a temporary object and nullifies the source
- Move Assignment: Cleans up existing resources and acquires the source's pointer

1. The basic file structure was built first with Particle.h, Particle.cpp and main.cpp. The header file defines the private members (name and std::vector<double>*) and declared the necessary getters, setters and the "Rule of 5" functions. 
2. Then in Particle.cpp the default and parameterized contructors were implemented. The destructor was implemented first to ensure the std::vector was properly deleted to prevent basic memory leaks.
3. Since the class uses a pointer, to prevent a double-free crash the copy constructor and copy assignment operator were implemented.
4. The logic allocates a new std::vector and copies the data over explicitly and contains a self-assignment check to the assignment operator.
5. To optimise performance, the move constructor and move assignment operator were implemented.
6. The setters and gettters were added with input validation to the energy setter to ensure the value is physical (E>0)
7. Wrote the physics calculations using the + operator for summing 4-vectors and the dotProduct function using the Minkowski metric.
8. Built the main.cpp file with inbuilt particles with their corresponding kinematic information
9. Included isolated tests for summing, dot products and explicitly triggered every component of the Rule of 5 to verify they were operating correctly

I chose to have the Particle class to directly manage the 4-momentum vector rather than wrapping the vector in a separate class in order to streamline the writing process while retaining functionality required.