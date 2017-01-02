#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <map>
#include <sstream>
#include <vector>

#include "Usuario.h"

using namespace std;

//-------------------------------------------------------------------------------------
string criptar(string pass);
string formatear_casilla(Tam tamCampo, string casilla);
vector<Tam> valores_primera_linea(string nombre_archivo);

void crear_tabla_indice_usuarios(); // crea tablas hardcodeadas

//-------------------------------------------------------------------------------------

Entero busqueda_binaria_key_registro(string nombre_archivo, string key, Tam tamCampos,
                                        Tam cantCampos, Entero low, Entero high);
Entero buscar_en_indice(string nombre_tabla, Tam tamCampos, string campo);

void loguear(Usuario *p_usuario);

//-------------------------------------------------------------------------------------

void agregar_a_indice(string nombre_indice, string key_, string campo_);

pair < string, map<string, Tam> >  cabecera_key_orden(string nombre_tabla, Tam tamCampos, string campo);

void crear_indice(string, string);

void indexar_campo_(string, string);

bool verificar_nivel(Usuario *usuario, string nombre_tabla);

void agregar_registro(Usuario *usuario); // pide por consola el nombre de la tabla

//-------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------





/*
void agregar_a_indice(string nombre_tabla, string campo, string key)
{
    fstream arch_indice;
    arch_indice.open("Indice_" + nombre_tabla + "_User" + ext, fstream::binary | fstream::in | fstream::out);
    
    //levanto registros a map, agrego registro(campo y key), escribo map
    map<string,string> mapa;
        //levanto registros
        
    string linea_, tamCampos_;
    getline(arch_indice,linea_);
    istringstream linea(linea_);
    linea >> tamCampos_;
    string cantRegistros;
    linea >> cantRegistros;
    Tam tamCampos = static_cast<Tam> ( stoul(tamCampos_));   
    
    Tam posicion = tamCampos*3 + 2 + tamCampos*2 + 2 + 1;//al inicio del nuevo registro
    arch_indice.seekg(posicion);
        //levanto a map
    string campo_(" ", tamCampos);
    string key_(" ", tamCampos);
    string temp(" ",2);//para que lea el salto de linea    
    while(!arch_indice.eof()){
        arch_indice.read(&campo_[0], tamCampos);
        arch_indice.read(&key_[0], tamCampos);
        arch_indice.read(&temp[0], 2);
        mapa[campo_] = key_;
        campo_ = "";  
        key_ = "";
        temp = "";
    }
        // agrego registro
    mapa[campo] = key;
        // escribo map
    arch_indice.seekp(posicion);
    tr(mapa, it){
        temp = "";
        temp.append(formatear_casilla(tamCampos,it->second));
        temp.append(formatear_casilla(tamCampos,it->first));        
        arch_indice << temp + "\n"; 
    }   
    
    // subir a 1 el numero de registros en el archivo (primera linea)   
    arch_indice.seekp(fstream::beg);
    arch_indice.seekp(tamCampos+1);
    cantRegistros = to_string( stoul(cantRegistros) + 1 );
    arch_indice.write(&formatear_casilla(tamCampos,cantRegistros)[0], tamCampos);
    
    arch_indice.close();
    
}
*/


void eliminar_tabla(Usuario *usuario);

void eliminar_indice(Usuario *usuario);

void crear_tabla(Usuario *usuario);

void indexar_campo(Usuario *usuario);

void agregar_campo(Usuario *usuario);

void modificar_campo_registro(Usuario *usuario);

void eliminar_registro(Usuario *usuario);

void mostrar_registro(Usuario *usuario);


#endif

