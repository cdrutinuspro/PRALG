#pragma once
#include <iostream>
#include "Eleve.h"
class CompareNote
{
public:
	int* ptr = nullptr;

	bool operator()(Eleve EleveA, Eleve EleveB) const { 
		++*ptr;
		return EleveA.note > EleveB.note; 
	
	}
};

