#include <iostream>
#include "stl.h"
using namespace std;

int main()
{
    std::vector<Eleves> v= generate(10);

    int compteur_nom = 0;

    afficher_tri_nom(v,  &compteur_nom);

    int compteur_note = 0;
    afficher_tri_note(v, &compteur_note);


    //pour maintenir la fenêtre de sortie ouverte
    std::cout << "Appuyez sur Entrée pour quitter..." << std::endl;
    std::cin.get();
    return 0;
}
