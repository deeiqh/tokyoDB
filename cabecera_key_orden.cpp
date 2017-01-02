#include "Funciones.h"

pair < string, map<string, Tam> >  cabecera_key_orden(string nombre_tabla, Tam tamCampos,  string campo)
{
    pair < string, map<string, Tam> > resultado;
    
    fstream arch_tabla;
    arch_tabla.open(nombre_tabla + ext, fstream::in);
    
    arch_tabla.seekg(0, fstream::beg);    
    Tam posicion = tamCampos*3 + 1; //posicion de inicio de cabecera
    
    arch_tabla.seekg(posicion, fstream::beg);    
    string line_;   // genero el map de cabeceras y ordenes
    getline(arch_tabla, line_);
    istringstream line(line_);
    string key, cab;
    line >> key;
    resultado.first = key; // guardo key
    Tam orden = 2;
    while(line >> cab){
        (resultado.second)[cab] = orden;
        orden++;
    }
    
    arch_tabla.close();
    
    return resultado;
}

