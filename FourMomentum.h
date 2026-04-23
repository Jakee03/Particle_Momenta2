#ifndef FOURMOMENTUM_H
#define FOURMOMENTUM_H
#include <iostream>

class FourMomentum {
private:
    double E;
    double px, py, pz;

public:
    //constructor w validation
    FourMomentum(double e = 0, double x = 0, double y = 0, double z = 0);
    
    //getters and setters
    double get_energy() const;
    double get_px() const;
    double get_py() const;
    double get_pz() const;

    void set_energy(double E);
    void set_px(double px);
    void set_py(double py);
    void set_pz(double pz);

    //sum 4-vecs
    FourMomentum operator+(const FourMomentum& other) const;
    //dot product
    double dot_product(const FourMomentum& other) const;

};

#endif