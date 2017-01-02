#include "Funciones.h"

void crear_indice(string nombre_tabla, string campo)
{
    //crear archivo indice (primera linea, cabecera) 
        
    vector<Tam> v(valores_primera_linea(nombre_tabla));
    Tam tamCampos = v[0];
    Tam cantCampos = v[1];
    
        // primera linea
    fstream arch_indice;
    arch_indice.open("Indice_"+nombre_tabla+"_"+campo + ext, fstream::in | fstream::out | fstream::trunc);    
    arch_indice.seekp(0, fstream::beg);    
    
    pair < string, map<string, Tam> > cabecera = cabecera_key_orden(nombre_tabla, tamCampos, campo);
    
    string linea("");
    linea += formatear_casilla(tamCampos, to_string(tamCampos)); 
    linea += formatear_casilla(tamCampos, to_string( (cabecera.second).find(campo)->second )); //orden del campo
    linea += formatear_casilla(tamCampos, "0") + "\n";    
    arch_indice << linea;
    
        // cabecera
    linea = "";    
    
    linea += formatear_casilla(tamCampos, campo); //campo es el key del indice
    linea += formatear_casilla(tamCampos, cabecera.first) + "\n"; 
    arch_indice << linea;
    
    arch_indice.close();
}