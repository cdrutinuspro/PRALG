#include "fonction.h"
#include <cassert>

/// Inverse par methode de Newton
float Fonction::inverse(float y) const {
    const int niterations=100;
    const float epsilon=1e-5f;
    float x=1.0f;
    Fonction* df = derivee();
    for(int i=0; i<niterations; i++) {
        float x0=x;
        x = x0+(y-(*this)(x0))/(*df)(x0);
        if(x0-epsilon<x && x<x0+epsilon)
            break;
    }
    delete df;
    return x;
}
