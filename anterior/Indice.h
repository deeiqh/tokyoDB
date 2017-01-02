#ifndef INDICE_H
#define INDICE_H

//#include <map>
#include <fstream>
#include "Tabla.h"

using namespace std;
//using Indice_ = map<string, Codigo>;

class Indice: public Tabla

{
private:
    Tam orden_campo;
public:    
    // hay 2 archivos: el de la tabla origen y el nuevo que es el indice (campo heredado)
    Indice(Tabla *tabla_origen, bool novicidad, string campo): // archivo + cabecera
        Tabla(novicidad, "Indice_" + tabla_origen->getNombre() + "_" + campo, "Indice",
                campo, tabla_origen->getCampoKey(), tabla_origen->getTamanho_campos())
        {
            orden_campo = orden(tabla_origen, campo);
            
            archivo.open(nombre+ext, fstream::in | fstream::out); //escribir el orden del campo en el archivo del indice
                                                // es la segunda linea
            archivo.seekg(fstream::beg);
            string temp;
            getline(archivo, temp);            
            insertar_orden_linea(orden_campo); //archivo << to_string(orden_campo) + "\n";
            archivo.close();
            
            /*
            Tam orden_campo(tabla_origen, campo);
            Registro *orden = string("0 ");
            *orden += to_string(orden_campo);
            insertar(orden);
             */
        };
        
    Tam orden(Tabla *tabla_origen, string campo);
    Registro *genera_registro(Registro *reg); //del registro completo de la tabla lo adecua a uno para indice 
                                                // segun campo
    void indexar(Registro *ptr_ri = NULL); //LEVANTO ARCHIVO INDICE, ACOMODO Y SOBREESCRIBO
    Tam get_ordenCampo(){return orden_campo;};
    void actualizar_td(Tabla *tabla_datos);
    

};

#endif

           