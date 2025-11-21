#ifndef POLYNOME_H
#define POLYNOME_H

#include "fonction.h"

class Polynome : public Fonction {
public:
    Polynome(const float* coefficients, int degre);
    Polynome(const Polynome& P);
    ~Polynome();
    virtual Fonction* clone() const;

    virtual float operator()(float x) const;
    virtual Fonction* derivee() const;
protected:
    float* coef;
    int deg;
};

class Affine : public Polynome {
public:
    Affine(float a, float b);
    virtual float inverse(float y) const;
};

#endif
