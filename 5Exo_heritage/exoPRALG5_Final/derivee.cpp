#include "derivee.h"
#include <cassert>

/// Constructeur avec fonction integrale, a cloner
Derivee::Derivee(const Fonction* integ) {
    assert(integ!=0);
    integrale = integ->clone();
}

/// Contructeur par copie
Derivee::Derivee(const Derivee& f) {
    integrale = f.integrale->clone();
}

/// Destructeur
Derivee::~Derivee() {
    delete integrale;
}

/// Constructeur virtuel
Fonction* Derivee::clone() const {
    return new Derivee(*this);
}

/// Calcul de la derivee par difference finie
float Derivee::operator()(float x) const {
    const float epsilon=1e-2f;
    return ((*integrale)(x+epsilon)-(*integrale)(x-epsilon))/(2*epsilon);
}

/// On peut calculer la derivee d'une fonction derivee !
Fonction* Derivee::derivee() const {
    return new Derivee(this);
}
