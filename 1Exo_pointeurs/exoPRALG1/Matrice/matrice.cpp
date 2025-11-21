#include "matrice.h"
#include <cassert>
using namespace std;

/// Affichage
ostream& operator<<(ostream& str, const Matrice& A) {
    for(int i= 0; i<A.nrow(); i++) {
        for(int j= 0; j<A.ncol(); j++)
            str << A(i,j) << ' ';
        str << endl;
    }
    return str;
}

/// Constructeur
Matrice::Matrice(int nrow, int ncol) {
    cout << "Constructeur" << endl;
    m = nrow; n = ncol;
    tab = new float[m*n];
    compteur = new int(1);
}

/// Constructeur par copie
Matrice::Matrice(const Matrice& A) {
    m = A.m; n = A.n;
    tab = A.tab;
    compteur = A.compteur;
    ++ *compteur;
    cout << "Copie: " << *compteur << endl;
}

/// Destructeur
Matrice::~Matrice() {
    cout << "~: " << *compteur << endl;
    if(-- *compteur == 0) {
        delete [] tab;
        delete compteur;
        cout << "Destruction effective" << endl;
    }
}

/// Affectation
Matrice& Matrice::operator=(const Matrice& A) {
    cout << "operator=" << *compteur << endl;
    if(this != &A) {
        if(-- *compteur == 0) {
            delete [] tab;
            delete compteur;
        }
        m = A.m; n = A.n;
        tab = A.tab;
        compteur = A.compteur;
        ++ *compteur;
    }
    return *this;
}

/// Acces a l'element
float Matrice::operator()(int i, int j) const {
    assert(0<=i && i<m && 0<=j && j<n);
    return tab[n*i+j];
}

/// Acces a l'element
float& Matrice::operator()(int i, int j)  {
    assert(0<=i && i<m && 0<=j && j<n);
    return tab[n*i+j];
}

/// Multiplication
Matrice Matrice::operator*(const Matrice& A) const {
    assert(n == A.m);
    Matrice M(m, A.n);
    for(int i=0; i<M.m; i++)
        for(int j=0; j<M.n; j++) {
            float s=0;
            for(int k=0; k<n; k++)
                s += operator()(i,k)*A(k,j);
            M(i,j) = s;
        }
    return M;
}
