#include "eleves.h"
#include <algorithm>
#include <iostream>

int main(int argc, char** argv) {
    std::size_t N = 25;
    if (argc >= 2) {
        try { N = static_cast<std::size_t>(std::stoul(argv[1])); }
        catch (...) { std::cerr << "Argument invalide; N=25 par défaut\n"; }
    }

    auto v = genere_echantillon(N);
    afficher(v, "Échantillon initial (non trié)");

    {
        std::vector<Eleve> copie = v;
        int cmp_count = 0;
        CompareNom cmp{&cmp_count};
        std::sort(copie.begin(), copie.end(), cmp);
        afficher(copie, "Tri alphabétique (par nom croissant)");
        std::cout << "Comparaisons effectuées (nom): " << cmp_count << "\n";
    }


    {
        std::vector<Eleve> copie = v;
        int cmp_count = 0;
        CompareNote cmp{&cmp_count};
        std::sort(copie.begin(), copie.end(), cmp);
        afficher(copie, "Tri par note décroissante");
        std::cout << "Comparaisons effectuées (note): " << cmp_count << "\n";
    }

    return 0;
}
