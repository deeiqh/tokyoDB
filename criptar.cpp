
#include "Funciones.h"

string criptar(string pass)
{
    char key = 'J';
    string pass_;
    char temp;
    tr(pass,it){
        temp = *it ^ key;
        pass_.pb(temp);
    }
    return pass_;
}
