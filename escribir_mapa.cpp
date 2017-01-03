#include "Funciones.h"

void escribir_mapa(string nombre_indice, map<string,string> *mapa, Tam tamCampos,
                    Tam posicion)
{
    
    fstream arch_indice;
    arch_indice.open( nombre_indice + ext, fstream::in | fstream::out);
    
    arch_indice.seekp(posicion, fstream::beg);
    
    string temp;
    tr((*mapa), it){
        temp = "";
        temp += (formatear_casilla(tamCampos, it->first));
        temp += (formatear_casilla(tamCampos, it->second))  + "\n";        
        arch_indice << temp; 
    } 
    
    arch_indice.close();
}