#include "Funciones.h"

string sobreescribir_campo(string nombre_tabla, string key_, string campo, string campo_) //ejm campo es Pass y campo_ es <:3y
{
    //con key_ hago busqueda binaria en la tabla
    
    vector<Tam> v(valores_primera_linea(nombre_tabla));    
    Tam tamCampos = v[0];
    Tam cantCampos = v[1];
    
    Entero posicion = tamCampos*3 + 1 + tamCampos*cantCampos + 1 -1;//antes del nuevo registro
    Entero low = posicion;    
    
    fstream arch_tabla;
    arch_tabla.open( nombre_tabla + ext, fstream::in | fstream::out);
    arch_tabla.seekg(0, fstream::end);
    Entero high = arch_tabla.tellg();
    high -= 1;
    arch_tabla.close();
    
    Entero posicion_campo = 
        busqueda_binaria_key_registro(nombre_tabla, key_, tamCampos, cantCampos, low, high);
    
    //con la posicion de key me ubico en el campo__ a sobreescribir    
    
    pair < string, map<string, Tam> > par; 
    par = cabecera_key_orden(nombre_tabla, tamCampos, campo);
    Tam orden = (par.second).find(campo)->second; // orden del campo
    
    char c[tamCampos];
    posicion = posicion_campo + tamCampos*(orden-1);   

    arch_tabla.clear();
    arch_tabla.open( nombre_tabla + ext, fstream::in | fstream::out);
    
    arch_tabla.seekg(posicion, fstream::beg);
    arch_tabla.read(&c[0],tamCampos); //c listo para retornarse
    
    //sobreescribo el campo
    
    arch_tabla.seekp(posicion, fstream::beg);
    string n = formatear_casilla(tamCampos, campo_);
    arch_tabla.write(&n[0],tamCampos);
    
    arch_tabla.close();
    return string(c);            
}
