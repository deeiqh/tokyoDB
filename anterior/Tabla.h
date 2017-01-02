#ifndef TABLA_H
#define TABLA_H

#include <iostream>
#include <string>
#include <fstream>
#include <map>

#define ext ".txt"

using namespace std;
using Registro = string;
using Tam = unsigned int; // tamaño
using Codigo = unsigned int;
using Cabecera = map<string, bool>;

class Tabla

{
protected:
    bool nueva; // si la tabla es nueva o ya estaba en la base de datos, da flexibilidad para no crear un archivo
    Tam cantidad_registros = 0;
    string nombre;
    string tipo; // Tabla de tipo Datos, Indice
    string campo_key;
    string nombres_campos;
    Tam tamanho_campo;
    fstream archivo;    
public:
    Tabla(bool nueva, string nombre, string tipo, string campo_key, string nombres_campos, Tam tamanho_campo):
        nueva(nueva), nombre(nombre), tipo(tipo),campo_key(campo_key), nombres_campos(nombres_campos), tamanho_campo(tamanho_campo)
        {
            if (nueva){
                archivo.open(nombre+ext, ostream::out); 
                Registro numeros(to_string(cantidad_registros) + " " 
                                                    + to_string(tamanho_campo) + " "
                                                    + to_string(cant_campos()+1) + " " + tipo);
                insertar_info_linea(numeros);//archivo << numeros\n;
                if (tipo == "Indice")//se hace un espacio para el orden del campo que se indexa
                    insertar_orden_linea(0);//archivo << "0\n";
                archivo.close();
                                               
                Registro *ptr_reg = genera_cabecera();
                insertar(ptr_reg);
                if (tipo != "Indice"){
                    Registro *indices = new string;
                    for(int i = 0; i < cant_campos(); i++) //se coloca el valor de 0 (no indexado)
                        *indices += " 0";
                    insertar(indices);
                }
            } // si no no se hace nada con el archivo                   
                
        };
    Tam tam_registros() const; 
    Tam cant_campos() const;
    Registro *genera_registro(); // se generan para luego escribirlos en la tabla
                                           //un reg de tabla siempre la llena el usuario
                                           // el gen_reg de indice lo hace el sistema
    Registro *genera_cabecera();
    void insertar(Registro *ptr_registro); // se formatea el reg para luego escribirlo , no se cierra el archivo
                                            // solo inserta, no actualiza el numero de registros
    void registrar(Registro *ptr_registro); // inserta y actualiza el numero de ergistros en la primera linea
    bool indexado(string campo);
    
    string getNombre() const {return nombre;};
    string getCampoKey() const {return campo_key;};
    string getCampos() const {return nombres_campos;};
    Tam getTamanho_campos()const {return tamanho_campo;};
    fstream *getArchivo() {return &archivo;};
};

#endif


