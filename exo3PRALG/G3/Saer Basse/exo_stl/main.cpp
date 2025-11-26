#include "eleve.h"
#include <vector>
#include <random> // Générateur aléatoire suggéré par chatgpt
#include <array> // Pour générer aléatoirement les noms (chatgpt)
#include <algorithm>

std::array<std::string, 26> caps = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "X", "Y", "Z"};
std::array<std::string, 26> lettre= {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "x", "y", "z"};

void display_vector(std::vector<Eleve> eleves)
{
    for (int i=0; i<eleves.size(); i++)
        eleves[i].display();
}

int main()
{
    std::random_device rd;  
    std::mt19937 gen(rd()); 

    std::uniform_int_distribution<> dist_note(0, 20);
    std::uniform_int_distribution<> dist_longueur(1,10);
    std::uniform_int_distribution<> dist_caps(0, caps.size() - 1);
    std::uniform_int_distribution<> dist_nom(0, lettre.size() - 1);

    int compteur=0;
    std::vector<Eleve> eleves;
    int nb_eleves;
    std :: cout << "Combien d'eleves voulez-vous ?" << std :: endl;
    std :: cin >> nb_eleves;
    for (int i=0; i<nb_eleves; ++i)
    {
        int taille_nom = dist_longueur(gen);
        std::string initial = caps[dist_caps(gen)];
        std::string lettres = "";
        for (int i=0; i<taille_nom; ++i)
        {
            lettres = lettres + lettre[dist_nom(gen)];
        }
        std::string nom_final = initial + lettres;
        eleves.push_back(Eleve(dist_note(gen), nom_final));
    }

    std::sort(eleves.begin(), eleves.end(), CompareNote(&compteur));
    display_vector(eleves);
    std :: cout << "Le nombre de comparaisons effecutees est: " << compteur << "." << std :: endl;
    return 0;
}