#pragma once
#include "Eleve.h"
class CompareNom
{
public:
int* ptr = nullptr;
bool operator()(Eleve EleveA, Eleve EleveB) const { 
	++*ptr;
	return EleveA.nom[0] < EleveB.nom[0]; 
	}

};

