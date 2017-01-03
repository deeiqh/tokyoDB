#include "Funciones.h"

void agregar_a_indice(string nombre_indice, string key, string campo)
{
    //datos
    vector<Tam> v(valores_primera_linea(nombre_indice));    
    Tam tamCampos = v[0];
    Tam cantRegistros = v[2];
    
    //levanto registros de indice a map, agrego registro a map, escribo map a indice
    
    Tam posicion = tamCampos*3 + 1 + tamCampos*2 + 1; //posicion de primer registro del indice
    
    map<string,string> *mapa;
    
    //levanto registros a mapa
    mapa = levantar_registro_mapa(nombre_indice, tamCampos, 2, 2, cantRegistros, posicion);

    //agrego mi registro
    (*mapa)[campo] = key;
            
    // escribo map
    posicion = tamCampos*3 + 1 + tamCampos*2 +1; //posicion de primer registro de indice
    escribir_mapa(nombre_indice, mapa, tamCampos, posicion); 
    
    //actualizar cantidad de registros
    fstream arch_indice;
    arch_indice.open( nombre_indice + ext, fstream::in | fstream::out);
    
    posicion = tamCampos * 2; //ubico en el campo adecuado
    arch_indice.seekp(posicion, fstream::beg);
    
    string temp = (formatear_casilla(tamCampos, to_string(cantRegistros + 1)));       
    arch_indice.write(&temp[0], tamCampos);
        
    arch_indice.close();
    delete mapa;
    
}