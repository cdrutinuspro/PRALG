#ifndef ELEVE_H
#define ELEVE_H
#include <string>
class Eleve{
private:
    std::string nom;
    int note;
public:
    Eleve(std::string cara, int p);
    int get_note() const;
    std::string get_nom() const;
    void display() const;

};
#endif // ELEVE_H
