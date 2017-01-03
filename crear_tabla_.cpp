#include "Funciones.h"

void crear_tabla_(string nombre_tabla)
{
    fstream arch_tabla;
    arch_tabla.open(nombre_tabla + ext, fstream::in | fstream::out);
    
    //pedir primera linea    
    
    string registro("");
    
    cout << "Tamanho de los campos:\t";
    Tam tamCampos;
    cin >> tamCampos;
    registro += to_string(tamCampos) + " ";
    
    cout << "Cantidad de campos:\t";
    Tam cantCampos;
    cin >> cantCampos;
    registro += to_string(cantCampos) + " ";
    
    registro += " 0 "; // la tabla se crea con 0 registros
    
    // escribir primera linea, formateada
    
    istringstream is(registro);
    registro = "";
    string temp;
    while (is >> temp){ 
        registro += formatear_casilla(tamCampos, temp);
    }
    registro += "\n";
    arch_tabla << registro;
    
    //cabecera
    
    //leer datos
    registro = "";
    cout << "Campos de cabecera:\n";
    for(int i = 0; i!= cantCampos; i++){
        cout << "Campo " << i+1 <<":\t";
        cin >> temp;
        registro += temp + " ";
    }
    
    //escribir cabecera
    is.clear();
    is.str(registro);
    registro = "";
    while (is >> temp){ 
        registro += formatear_casilla(tamCampos, temp);
    }
    registro += "\n";
    arch_tabla << registro;      
    
    arch_tabla.close();
}