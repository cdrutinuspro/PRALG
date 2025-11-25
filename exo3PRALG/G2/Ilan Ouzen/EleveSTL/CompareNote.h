#ifndef COMPARENOTE_H
#define COMPARENOTE_H
#include "Eleve.h"
class CompareNote{
private:
    int *ptr;
public:
    CompareNote(int *c);
    bool operator()(const Eleve&E1, const Eleve&E2) const;
};
#endif // COMPARENOTE_H
