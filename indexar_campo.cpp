#include "Funciones.h"

void indexar_campo(Usuario *usuario)
{
    cout << "Nombre de tabla:\t";
    string nombre_tabla;
    cin >> nombre_tabla;   
    
    cout << "Campo a indexar:\t";
    string campo;
    cin >> campo;      
    
    if (verificar_nivel(usuario, nombre_tabla)){
        indexar_campo_(nombre_tabla, campo); 
        cout << "Campo indexado.\n\n";
    }
}