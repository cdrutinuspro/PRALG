#include "eleve.h"

Eleve::Eleve(){
    static bool init = true;
    if(init){
        init = false;
        srand(time(0));
    }

    note = rand()%21;
    int len = 1 + rand()%10;
    char nom_c[len+1];
    nom_c[0] = 65 + rand()%26;
    for(int i = 1; i<len+1; i++){
        nom_c[i] = 97 + rand()%26;
    }
    nom = string(nom_c, len+1);
}

ostream& operator<<(ostream& str, Eleve e){
    str << e.get_nom() << "\t\t" << e.get_note() << endl;
    return str;
}
