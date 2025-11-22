#include "eleve.h"
#include <iostream>
#include <vector>
#include "eleve.h"

inline void afficher(const std::vector<Eleve>& v, const char* titre) {
    std::cout << "\n" << titre << " (" << v.size() << " eleves):\n";
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << "  - " << *it << "\n";
    }
}
