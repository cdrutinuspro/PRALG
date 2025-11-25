#include "eleve.h"
#include <cstdlib>
#include<ctime>
using namespace std;

Eleve::Eleve(){
    grade=rand()%21;
    string s= string(1,char('A'+rand()%26));
    int len=1+rand()%10;
    for(int i=0; i<len;i++){
        s+=string(1,char('a'+rand()%26));
    }
    Name=s;
}


