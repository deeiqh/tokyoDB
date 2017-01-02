#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <set>
#include "Indice.h"

#define nombre_indice_usuarios_nivel "Indice_Usuarios_Nivel"

#define tr(c,it) for(auto it = c.begin(); it != c.end(); it++)

void Indice::indexar(Registro *ptr_ri) //LEVANTO ARCHIVO INDICE, ACOMODO Y SOBREESCRIBO
{   //LEVANTO Y ACOMODO
    archivo.open(nombre+ext, fstream::in | fstream::out); //indice_tabla_campo
    
    Registro temp;
    getline(archivo, temp);
    getline(archivo, temp);
    getline(archivo, temp);//de aca para adelante estan los registros
    
    // acomodo
    istringstream registro;
    string key, campo;
    set< pair<string, string> > estructura;
    pair<string, string> par;
    while(getline(archivo, temp)){//acomodo los registros del archivo
        
        registro.clear();
        registro.str(temp);
        
        registro >> key;
        registro >> campo;
        
        if (nombre == nombre_indice_usuarios_nivel){
            par.first = key;
            par.second = campo;
        }else{
            par.first = campo;
            par.second = key;       
        }
        
        estructura.insert(par);     
    }
    
    if(ptr_ri != NULL){ // acomodo el registro ingresante
        registro.clear();
        registro.str(*ptr_ri);
        registro >> key;
        registro >> campo;
        par.first = campo;
        par.second = key; 
        estructura.insert(par);
    }  
    
    //escribo todos los registros
    archivo.seekg(fstream::beg);
    getline(archivo, temp);
    getline(archivo, temp);
    getline(archivo, temp);//de aca para adelante estan los registros
    //ESCRIBO
    tr(estructura, it){
        temp = "";
        temp.append(it->second) += " ";
        temp.append(it->first);
        
        Registro *reg = new Registro(temp);
        
        insertar(reg); // se hace delete al ptr_reg, dentro de insertar se formatea
    }   
    
    // subir a 1 el numero de registros en el archivo (primera linea)
    archivo.seekg(fstream::beg);
    getline(archivo, temp);
    registro.clear();
    registro.str(temp);
    string num;
    registro >> num;
    getline(registro,temp);
    temp = to_string( stoul(num)+1 ) + temp + "\n";
    archivo.seekp(fstream::beg);
    archivo << temp;
    
    delete ptr_ri;    
    archivo.close();
    
    /*
    //dejo el archivo en blanco, luego pongo cabecera
    archivo.open(nombre+ext, fstream::out);
    archivo.close();
    Registro *ptr_cabecera = genera_cabecera();
    insertar(ptr_cabecera);//notar que el insert abre de nuevo el archivo (append), y luego lo cierra
    */
}

Registro *Indice::genera_registro(Registro *reg)
{
    Registro *ptr_registro = new Registro("");
    
    istringstream in(*reg);
    string temp;
    in >> temp;
    (*ptr_registro).append(temp) += " ";
    Tam count = 1;
    while(in >> temp){        
        if (count == orden_campo){
            (*ptr_registro).append(temp);
            return ptr_registro;
        }
        else
            count++;
    }   
    return ptr_registro;
}

Tam Indice::orden(Tabla *tabla_origen, string campo)
{
    string campos_t = tabla_origen->getCampos();
    istringstream campos(campos_t);
    
    string temp;
    Tam count = 1;
    while(campos>>temp){
        if(temp == campo)
            return count;
        else
            count++;
    }
}

void Indice::actualizar_td(Tabla *tabla_datos)//segunda linea de tabla (0 |0 0) actualizar(0 | 1 0)
{
    fstream *arch = (tabla_datos->getArchivo());
    arch->open(tabla_datos->getNombre()+ext, fstream::in | fstream::out | fstream::binary);
    Registro boo;
    getline(*arch, boo);
    Tam move = (tamanho_campo+1)*orden_campo; //cant_campos no incluye el campo_key
    arch->seekp(move, fstream::cur);
    arch->write("1",1);
    
    arch->close();
    
    
}