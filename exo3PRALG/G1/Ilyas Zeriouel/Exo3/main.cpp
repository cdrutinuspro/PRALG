// Project:  Exo3
// Student(s): Ilyas ZERIOUEL

#include "eleves.h"
#include <ctime>
#include <cstdlib>

int main() {
    int compteur=0;
    std::vector<Eleve> eleves;
    int length_eleves = 10; //variable selon nos souhaits
    srand((unsigned)time(0));
    for (int j=0; j<length_eleves; j++) {
        int length_name = 1 + rand()%10;
        std::string name;
        name += 'A' + rand()%26;
        for (int i=1; i<length_name; i++) {
            name += 'a' + rand()%26;
        }
        eleves.push_back(Eleve(name, rand()%21));
    }
    decreasing_names(eleves, compteur);
    std::cout << "compteur = " << compteur << std::endl;
    compteur = 0;
    decreasing_marks(eleves, compteur);
    std::cout << "compteur = " << compteur << std::endl;
	return 0;
}
