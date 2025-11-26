#ifndef ELEVE_H
#define ELEVE_H

#include <string>
using namespace std;


class Eleve {
private:
    string name;
    int grade;           

public:
    Eleve();                               // constructeur par défaut     
    Eleve(const string& name, int grade); // constructeur        

    // Getters 

    string getName() const;               // accès au nom
    int getGrade() const;                 // accès à la note

    // Setters
    void setName(const string& name);     // modification du nom
    void setGrade(int grade);             // modification de la note

    void afficher() const;                // affichage
    ~Eleve();                             // destructeur

};

class CompareName {                       
public :  
    int* ptr;
    explicit CompareName(int* p = nullptr) : ptr(p) {} // constructeur pour le pointeur qui est utilisé dans le main pour le compteur 
    bool operator()(const Eleve& a, const Eleve& b) const {       
        if (ptr) ++(*ptr); 
        return a.getName() < b.getName();  
        }
};

class CompareGrade {
public : 
    int* ptr;
    explicit CompareGrade(int* p = nullptr) : ptr(p) {}
    bool operator()(const Eleve& a, const Eleve& b) const {  
        if (ptr) ++(*ptr);
        return a.getGrade() > b.getGrade();  
        }
};

// C'st pas des fonctions qui rentrent dans les différentes classes mais elles sont utiles pour le code 


string randomName();
vector<Eleve> listofStudents(int n);
void affichage(const vector<Eleve>& classe);

#endif // ELEVE_H


