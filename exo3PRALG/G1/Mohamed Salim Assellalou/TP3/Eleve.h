#pragma once

class Eleve{
public:
    std::string nom;
    int note;

    Eleve();
    Eleve(const std::string& n, int s);
};

class CompareNom{
public:
    int* compteur;
    CompareNom(int* p=nullptr);
    bool operator()(const Eleve& a, const Eleve& b) const;
};

class Classe{
    std::vector<Eleve> liste;
    static std::string nomRandom(st)
};
