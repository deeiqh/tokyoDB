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

void escribir_mapa(string nombre_indice, map<string,string> *mapa, Tam tamCampos,
                    Tam posicion);

map<string,string> *levantar_registro_mapa(string nombre_archivo, Tam tamCampos, 
                                           Tam  cantCampos,
                                            Tam ordenCampo, Tam cantRegistros, Tam posicion);

string sobreescribir_campo(string nombre_tabla, string key_, string campo, string campo_);

void modificar_campo_registro(Usuario *usuario);

//-------------------------------------------------------------------------------------

void indexar_campo(Usuario *usuario);

//-------------------------------------------------------------------------------------

void crear_tabla(Usuario *usuario);

//-------------------------------------------------------------------------------------

void eliminar_tabla(Usuario *usuario);

void eliminar_indice(Usuario *usuario);

void agregar_campo(Usuario *usuario);

void eliminar_registro(Usuario *usuario);

void mostrar_registro(Usuario *usuario);


#endif

