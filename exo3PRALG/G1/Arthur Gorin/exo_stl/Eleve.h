#ifndef ELEVE_H
#define ELEVE_H

#include <vector>
#include <string>




class Eleve {
    std::string nom;
    int note;
public :
    Eleve(std::string name, int mark);
    ~Eleve();
    void setmark(int mark);
    void setname(std::string name);
    int getmark() const;
    std::string getname() const;
};

class Comparenom{
    int* ptr;
public:
    Comparenom(int* p){ptr =p;};
    bool operator()(const Eleve& eleve1, const Eleve& eleve2) const {
        (*ptr)++;
        return eleve1.getname() < eleve2.getname();};
};

class Comparenote{
    int* ptr;
public:
    Comparenote(int* p){ptr =p;};
    bool operator()(const Eleve& eleve1, const Eleve& eleve2) const {
        (*ptr)++;
        return eleve1.getmark() > eleve2.getmark();};
};

std::string randomName();

void affichage(const std::vector<Eleve>& eleve);


#endif // ELEVE_H
