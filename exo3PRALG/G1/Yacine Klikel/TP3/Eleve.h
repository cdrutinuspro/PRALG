#include <string>
#include <vector>

class Eleve {
public:
    Eleve(const std::string& nom, int note);
    std::string getNom() const;
    int getNote() const;
private:
    std::string nom;
    int note;
};

class CompareNom {
    const std::vector<Eleve>& tab;
    int* ptr;
public:
    CompareNom(const std::vector<Eleve>& t, int* p) : tab(t), ptr(p) {}
    bool operator()(int i, int j) const;
};

class CompareNoteDecroissant {
    const std::vector<Eleve>& tab;
    int* ptr;
public:
    CompareNoteDecroissant(const std::vector<Eleve>& t, int* p) : tab(t), ptr(p) {}
    bool operator()(int i, int j) const;
};

void AfficherDansOrdre(const std::vector<Eleve>& eleves, const std::vector<int>& ordre);