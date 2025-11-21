#ifndef TRIGO_H
#define TRIGO_H

#include "fonction.h"
#include <string>

class Trigo : public Fonction {
public:
    Trigo(std::string type);
    virtual float operator()(float x) const;
    virtual Fonction* derivee() const;
    virtual Fonction* clone() const;
private:
    std::string nom;
};

#endif
