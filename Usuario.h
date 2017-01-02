#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <map>
#include <fstream>

using namespace std;

using Tam = unsigned int;
using Entero = int;
using Real = float;

class Usuario;
typedef void (*Ptr_funcion) (Usuario *); // las funciones para operar la base de datos
using mapSF = map<string, Ptr_funcion>;

#define salir "_bye"
#define tabla_usuarios "Tabla_Usuarios_Alumno" //nivel mas bajo para que todos puedan usarla
#define tabla_niveles "Tabla_Niveles_Administrador"
#define ext ".txt"
#define pb push_back
#define tr(c,it) for(auto it = c.begin(); it != c.end(); it++)

class Persona
{
private:
    Tam numDoc;
    string tipoDoc;
    string nombre;
    string apellido;    
    
public:
    Persona(){};
    
    void set_numDoc(Tam numero_doc) {numDoc = numero_doc;}
    Tam get_numDoc() {return numDoc;}
    
    void set_tipoDoc(string tipo_doc) {tipoDoc = tipo_doc;}
    string get_tipoDoc() {return tipoDoc;}
    
    void set_nombre(string n) {nombre = n;}
    string get_nombre() {return nombre;}
    
    void set_apellido(string a) {apellido = a;}
    string get_apellido() {return apellido;}
    
    virtual void maneja_tokyoDB() = 0;
};

class Usuario: public Persona
{
private:
    string user = ""; //nombre de usuario
    Real valor_nivel = 0;
    mapSF *p_mapa_funciones;
    
public:
    Usuario(){};
    
    void set_user(string u) {user = u;}
    string get_user() {return user;}
       
    void set_valor_nivel(Real n) {valor_nivel = n;}
    Real get_valor_nivel() {return valor_nivel;}
    
    void set_p_mapa_funciones(mapSF *p) {p_mapa_funciones = p;}
    mapSF *get_p_mapa_funciones() {return p_mapa_funciones;}
    
    virtual void maneja_tokyoDB() override;
};

#endif /* USUARIO_H */

