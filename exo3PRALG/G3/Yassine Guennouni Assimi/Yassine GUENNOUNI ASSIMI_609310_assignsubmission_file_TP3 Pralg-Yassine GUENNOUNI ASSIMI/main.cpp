// Imagine++ project
// Project:  TP3 PRALG
// Student(s): Yassine GUENNOUNI ASSIMI
#include "Eleve.h"

void display_list_of_student(const vector<Eleve>& list_of_student){
    vector<Eleve>::const_iterator iterator=list_of_student.begin();
    for (;iterator!=list_of_student.end();++iterator){
        cout<<iterator->student_name()<<" "<<iterator->student_grade()<<endl;
    }
}

int main() {
    // initRandom();
    int compteur1=0;
    int compteur2=0;
    vector <Eleve> list_of_student;
    for (int index=0;index<10;++index){
        int random_grade= rand()%21; //intRandom(0,20);
        int random_length= 1 + rand()%10; //intRandom(1,10);
        string random_name;
        random_name.push_back(static_cast<char>('A' + rand()%26));
        for(int index_bis=0; index_bis<random_length;++index_bis){
            random_name.push_back(static_cast<char>('a' + rand()%26));
        }
        list_of_student.push_back(Eleve(random_name,random_grade));
    }
    cout<<"Nom et notes generees aleatoirement"<<endl;
    display_list_of_student(list_of_student);
    cout<<endl;

    sort(list_of_student.begin(),list_of_student.end(),CompareNote(&compteur1,true));//le true indique que le classement suivra un ordre décroissant
    cout<<"Classement base sur les notes (ordre decroissant): "<<endl;
    display_list_of_student(list_of_student);
    cout<<"Nombre de comparaisons : "<<compteur1<<endl;
    cout<<endl;

    compteur1=0;
    sort(list_of_student.begin(),list_of_student.end(),CompareNote(&compteur1,false));//le false indique que le classement suivra un ordre croissant
    cout<<"Classement base sur les notes (ordre croissant): "<<endl;
    display_list_of_student(list_of_student);
    cout<<"Nombre de comparaisons : "<<compteur1<<endl;
    cout<<endl;

    sort(list_of_student.begin(),list_of_student.end(),CompareNom(&compteur2,true));//le true indique que le classement suivra un ordre décroissant
    cout<<"Classement base sur l'ordre alphabetique (ordre decroissant): "<<endl;
    display_list_of_student(list_of_student);
    cout<<"Nombre de comparaisons : "<<compteur2<<endl;
    cout<<endl;

    compteur2=0;
    sort(list_of_student.begin(),list_of_student.end(),CompareNom(&compteur2,false));//le false indique que le classement suivra un ordre croissant
    cout<<"Classement base sur l'ordre alphabetique (ordre croissant): "<<endl;
    display_list_of_student(list_of_student);
    cout<<"Nombre de comparaisons : "<<compteur2<<endl;

    return 0;

}
