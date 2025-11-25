#include "CompareNote.h"

CompareNote::CompareNote(int*c) : ptr(c) {};

bool CompareNote::operator()(const Eleve&E1, const Eleve&E2) const {
    ++*ptr;
    return (E1.get_note()>E2.get_note());
}
