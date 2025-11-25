#ifndef COMPARENOM_H
#define COMPARENOM_H

#include "Eleve.h"
class CompareNom{
private:
    int *ptr;
public:
    CompareNom(int *c);
    bool operator()(const Eleve&E1, const Eleve&E2) const;
};
#endif // COMPARENOM_H
