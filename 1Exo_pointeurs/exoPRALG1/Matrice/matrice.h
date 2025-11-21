#pragma once
#include <iostream>

/// Classe avec copie superficielle
class Matrice {
    int m, n;
    float* tab;
    int* compteur;
public:
    Matrice(int nrow, int ncol);
    Matrice(const Matrice& A);
    ~Matrice();
    Matrice& operator=(const Matrice& A);

    int nrow() const { return m; }
    int ncol() const { return n; }
    float operator()(int i, int j) const;
    float& operator()(int i, int j);
    
    Matrice operator*(const Matrice& A) const;
};

std::ostream& operator<<(std::ostream& str, const Matrice& A);
