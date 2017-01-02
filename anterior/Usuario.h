#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "Tabla.h"



using namespace std;

using Doc = string;
using NumDoc = string;
using Eliminado = string;

// usuario sera un "tipo" de dato, las instancias tendran que tener una tabla en ese atributo
class Usuario
{
public:
    string user;
    Eliminado eliminado;
    string pass;
    string nivel; 
    string nombre_tabla_operaciones;// solo el nombre de la tabla
    Doc tipoDoc;
    NumDoc numDoc;
public:
    Usuario(string user, string nivel, string pass, Eliminado eliminado, Doc tipoDoc, NumDoc numDoc):
        user(user), nivel(nivel), eliminado(eliminado), pass(pass), tipoDoc(tipoDoc), numDoc(numDoc),
        nombre_tabla_operaciones ("Usuario_" + nivel + "_operaciones")
        {};
};
/*
class Visitante: public Usuario
{
private:
public: 
    Visitante(string nombre, string pass, Doc tipoDoc, NumDoc numDoc)
    {
        nivel = "Visitante";
        Usuario(nombre, pass, tipoDoc, numDoc);        
    }
};

class Profesor: public Usuario
{
private:
public: 
    Profesor(string nombre, string pass, Doc tipoDoc, NumDoc numDoc)
    {
        nivel = "Profesor";
        Usuario(nombre, pass, tipoDoc, numDoc);        
    }
};

class Alumno: public Usuario
{
private:
public: 
    Alumno(string nombre, string pass, Doc tipoDoc, NumDoc numDoc)
    {
        nivel = "Alumno";
        Usuario(nombre, pass, tipoDoc, numDoc);        
    } 
};
*/
#endif 
