// TP : STD due for Octobre 19th, 2025
// Collaborator : Soufiane SONDALI - Group 2

#include "Eleve.h"

int main(){
    srand(time(nullptr));
    int comptName =0, comptNote =0;
    std::vector<Eleve> Eleves;
    int index[NbEleve];
    for (int i=0; i < NbEleve; ++i){
        std::string name;
        char capitalCase = 'A' + rand()%26;
        name += capitalCase;
        for (int j=0; j < 1+rand()%10; ++j){
            char lowerCase = 'a' + rand()%26;
            name += lowerCase;
        }
        Eleves.push_back(Eleve(name, rand()%21));
        index[i] = i;
    }
    std::sort(index, index + NbEleve, CompareName(&Eleves, &comptName));
    display(index, Eleves);
    cout << "Iteration number for name sort = " << comptName << endl;
    std::sort(index, index + NbEleve, CompareNote(&Eleves, &comptNote));
    display(index, Eleves);
    cout << "Iteration number for note sort = " << comptNote << endl;
    return 0;
}
