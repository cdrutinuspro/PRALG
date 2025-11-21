// PRALG exo1
// Matrice avec copie superficielle

#include "matrice.h"
#include <cstdlib>
using namespace std;

void init(Matrice& A) {
    for(int i=0; i<A.nrow(); i++)
        for(int j=0; j<A.ncol(); j++)
            A(i,j) = rand() / (float)RAND_MAX;
}

int main() {
    Matrice A(2,3);
    Matrice B(3,2);
    init(A);
    init(B);
    cout << "A=" << endl << A << endl;
    cout << "B=" << endl << B << endl;

    cout << "A*B=" << endl << A*B << endl;

    Matrice C(A); // Copie
    C = B; // Affectation
    return 0;
}
