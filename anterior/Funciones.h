#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Tabla.h"
#include "Usuario.h"

using namespace std;

#define nombre_archivo_niveles "Niveles"
#define nombre_tabla_usuarios "Tabla_Usuarios"

bool buscar_linea(string, string);

bool novicidad(string);

string criptar(string);

void registrar_en_tabla(string, Registro *); //registrar registro en cualquier tabla

void registrar_usuario();

void ver_niveles();

void hardcodear_admin();

void insertar_orden_linea(Tam);

void insertar_info_linea(string);
// void verificar_existencia(string);

#endif /* FUNCIONES_H */

