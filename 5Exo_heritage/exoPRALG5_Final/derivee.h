#ifndef DERIVEE_H
#define DERIVEE_H

#include "fonction.h"

class Derivee : public Fonction {
public:
    Derivee(const Fonction* integ);
    Derivee(const Derivee& f);
    virtual ~Derivee();
    virtual Fonction* clone() const; // "Constructeur virtuel"

    virtual float operator()(float x) const;
    virtual Fonction* derivee() const;

protected:
    const Fonction* integrale; // La fonction dont on derive
};

#endif
