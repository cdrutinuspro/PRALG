#include "stl.h"


 //constructeur de Eleves
Eleves::Eleves(const string& n , int m )
     : name(n), mark(m) {}


// definition des méthodes et opérateurs de CompareNom
CompareNom::CompareNom(int* p) : ptr(p) {}

bool CompareNom::operator()(const Eleves& e1, const Eleves& e2) const {
    if (ptr) ++*ptr;
    return e1.name < e2.name;
}

// definition des méthodes et opérateurs de CompareNote
CompareNote::CompareNote(int* p): ptr(p){}

bool CompareNote::operator()(const Eleves& e1, const Eleves& e2) const {
    if (ptr) ++*ptr;
    return e1.mark>e2.mark;
}


// definiton des fonctions utiles

std::vector<Eleves> generate (int m){
    srand(time(0));
    std::vector<Eleves> v;

    for (int k=0; k<m;k++){
        int length=1+rand()%10; //génère la longueur aléatoire du nom
        std::string name;
        for (int i = 0; i<length; i++){
            char c;
            if (i==0){
                c= 'A'+ std::rand()%26;
            }
            else
                c= 'a'+std::rand()%26;
            name+=c;
        }
        int mark=std::rand()%21; //génère une note aléatoire entre 0 et 20
        v.push_back({name,mark});
    }


    return v;
}

void afficher_tri_nom(std::vector<Eleves> v, int* compteur){
    CompareNom cmp(compteur);
    std::sort(v.begin(), v.end(), cmp);
    cout<<"---Tri par Nom---"<<endl;
    for (const Eleves& e:v){
        cout<<e.name<<" : "<<e.mark<<endl;
    }
    cout<<"Nombre de comparaisons: "<<*compteur<<endl;
}

void afficher_tri_note(std::vector<Eleves> v, int* compteur){
    CompareNote cmp(compteur);
    std::sort(v.begin(), v.end(),cmp);
    cout<<"---Tri par Note---"<<endl;
    for (const Eleves& e:v){
        cout<<e.name<<" : "<<e.mark<<endl;
    }
    cout<<"Nombre de comparaisons : "<<*compteur<<endl;
}
