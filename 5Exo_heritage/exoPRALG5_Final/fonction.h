#ifndef FONCTION_H
#define FONCTION_H

class Fonction {
public:
    virtual ~Fonction() {}
    virtual Fonction* clone() const=0; // "Constructeur virtuel"

    virtual float operator()(float x) const=0;

    virtual Fonction* derivee() const=0;

    virtual float inverse(float y) const;
};

#endif
