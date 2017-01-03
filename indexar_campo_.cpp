#include "Funciones.h"

void indexar_campo_(string nombre_tabla, string campo)
{
    //crear archivo indice (primera linea, cabecera)
    crear_indice(nombre_tabla, campo);
 
    vector<Tam> v(valores_primera_linea(nombre_tabla));    
    Tam tamCampos = v[0];
    Tam cantCampos = v[1];    
    Tam cantRegistros = v[2];
    
    v = valores_primera_linea("Indice_" + nombre_tabla + "_" + campo);
    Tam ordenCampo = v[1];

    //levanto registros de tabla a map, escribo map a indice
    
    Tam posicion = tamCampos*3 + 1 + tamCampos*cantCampos + 1; //posicion de primer registro de tabla   
    map<string,string> *mapa;
    
    //levanto registros a mapa
    mapa = levantar_registro_mapa(nombre_tabla, tamCampos, cantCampos,
                                    ordenCampo, cantRegistros, posicion);
    
    // escribo map
    posicion = tamCampos*3 + 1 + tamCampos*2 +1; //posicion de primer registro de indice
    escribir_mapa("Indice_"+nombre_tabla+"_"+campo, mapa, tamCampos, posicion);
    
    //actualizar cantidad de registros
    fstream arch_indice;
    arch_indice.open( "Indice_"+nombre_tabla+"_"+campo + ext, fstream::in | fstream::out);    
    
    posicion = tamCampos * 2; //ubico en el campo adecuado
    arch_indice.seekp(posicion, fstream::beg);
    
    string temp = (formatear_casilla(tamCampos, to_string(cantRegistros)));       
    arch_indice.write(&temp[0], tamCampos);
        
    arch_indice.close();
    delete mapa;
    
}