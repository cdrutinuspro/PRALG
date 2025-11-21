#include "polynome.h"
#include <algorithm>
#include <cassert>

/// Constructeur
Polynome::Polynome(const float* coefficients, int degre)
: coef(new float[degre+1]), deg(degre) {
    for(int i=0; i<=degre; i++)
        coef[i] = coefficients[i];
}

/// Constructeur par copie
Polynome::Polynome(const Polynome& P)
: Fonction(P), coef(new float[P.deg+1]), deg(P.deg) {
    for(int i=0; i<=deg; i++)
        coef[i] = P.coef[i];
}

/// Destructeur
Polynome::~Polynome() {
    delete [] coef;
}

/// "Constructeur virtuel", normalement pas utile pour un polynome mais
/// necessaire pour ne pas en faire une classe abstraite
Fonction* Polynome::clone() const {
    return new Polynome(*this);
}

/// Evaluation du polynome
float Polynome::operator()(float x) const {
    float y=0;
    for(int i=0; i<=deg; i++)
        y = y*x+coef[i];
    return y;
}

/// Derivee d'un polynome est un polynome, donc nous pouvons calculer
/// explicitement.
Fonction* Polynome::derivee() const {
    Polynome* dP = new Polynome(coef, std::max(0,deg-1));
    for(int i=0; i <= dP->deg; i++)
        dP->coef[i] *= deg-i;
    return dP;
}

/// Ne pouvant pas construire un tableau {a,b}, on utilise un tableau bidon
static float tab2[] = {0,0};

/// Constructeur x->ax+b
Affine::Affine(float a, float b)
: Polynome(tab2, 1) {
    coef[0]=a;
    coef[1]=b;
}

/// Inversion triviale pour fonction affine
float Affine::inverse(float y) const {
    assert(coef[0]!=0);
    return (y-coef[1])/coef[0];
}
