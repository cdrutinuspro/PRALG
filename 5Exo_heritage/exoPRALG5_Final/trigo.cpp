#include "trigo.h"
#include "derivee.h"
#include <cmath>
#include <cassert>

/// Constructeur
Trigo::Trigo(std::string type)
: nom(type) {}

/// Evaluation
float Trigo::operator()(float x) const {
    if(nom == "cos") return cos(x);
    if(nom == "sin") return sin(x);
    if(nom == "tan") return tan(x);
    assert(false);
    return 0;
}

/// Derivee
Fonction* Trigo::derivee() const {
    if(nom == "sin") // Derivee representable exactement
        return new Trigo("cos");
    return new Derivee(this); // Par difference finie
}

/// "Constructeur virtuel"
Fonction* Trigo::clone() const {
    return new Trigo(*this);
}
