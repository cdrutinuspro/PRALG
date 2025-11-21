#define _USE_MATH_DEFINES // Pour M_PI sous Windows
#include <cmath>

#include "polynome.h"
#include "trigo.h"
#include <iostream>

int main() {
    std::cout << "Fonction x->2x+3: ";
    Affine aff(2,3);
    std::cout << "2*1+3=" << aff(1) << std::endl;

    std::cout << "Polynome x->x^3: ";
    float coef[] = {1,0,0,0};
    Polynome x3(coef,3);
    std::cout << "1^3="<<x3(1) << " 2^3="<<x3(2) << " 3^3="<<x3(3) << std::endl;

    std::cout << "Derivee de x->x^3 (x->3x^2): ";
    Fonction* dx3 = x3.derivee();
    std::cout << "3*1^2=" << (*dx3)(1) << " 3*2^2=" << (*dx3)(2) << std::endl;
    delete dx3;

    std::cout << "Racine cubique: ";
    std::cout << "3=27^(1/3)=" << x3.inverse(27) << std::endl;

    std::cout << "Fonction tangente: ";
    Trigo t("tan");
    std::cout << "1=tan(pi/4)=" << t(M_PI/4) << std::endl;

    std::cout << "Derivee de tangente (1+tan^2): ";
    Fonction* dt = t.derivee();
    std::cout << "2=tan'(pi/4)=" << (*dt)(M_PI/4) << std::endl;
    std::cout << "Derivee seconde de tangente 2(1+tan^2)tan: ";
    Fonction* d2t = dt->derivee();
    std::cout << "4=tan''(pi/4)=" << (*d2t)(M_PI/4) << std::endl; 
    delete dt;
    delete d2t;

    std::cout << "Arc-tangente: ";
    std::cout << "pi=4*atan(1)=" << 4*t.inverse(1) << std::endl;
    return 0;
}
