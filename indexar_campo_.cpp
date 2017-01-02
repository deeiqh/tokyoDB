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
    
    fstream arch_tabla;
    arch_tabla.open(nombre_tabla + ext, fstream::in | fstream::out);
    Tam posicion = tamCampos*3 + 1 + tamCampos*cantCampos + 1; //posicion de primer registro de tabla
    arch_tabla.seekg(posicion, fstream::beg);
    
    map<string,string> mapa;
    
        //levanto registros a mapa
    char campo_[tamCampos];
    char key_[tamCampos]; // key del mapa   
    int i = 1;
    string temp1, temp2;
    istringstream is;
    for(int j = 0; j != cantRegistros; j++){
        arch_tabla.read(&campo_[0], tamCampos); // el key de la tabla es un campo del mapa
        
        posicion += tamCampos * (ordenCampo-1); //ubico en el campo adecuado
        arch_tabla.seekg(posicion, fstream::beg);
        arch_tabla.read(&key_[0], tamCampos);

        // guardo en mapa
        is.str(string(key_));
        is >> temp1;
        
        is.clear();
        is.str(string(campo_));
        is >> temp2;
        mapa[temp1] = temp2; 
        
        posicion = (tamCampos*3 + 1 + tamCampos*cantCampos + 1) + 
                    i*(tamCampos*cantCampos + 1);//ubico en el siguiente registro
        i++;
        is.clear();
    }
    arch_tabla.close();
    
        // escribo map
    posicion = tamCampos*3 + 1 + tamCampos*2 +1; //posicion de primer registro de indice
    fstream arch_indice;
    arch_indice.open("Indice_"+nombre_tabla+"_"+campo + ext, fstream::in | fstream::out);
    arch_indice.seekp(posicion, fstream::beg);
    string temp;
    tr(mapa, it){
        temp = "";
        temp += (formatear_casilla(tamCampos, it->first));
        temp += (formatear_casilla(tamCampos, it->second))  + "\n";        
        arch_indice << temp; 
    }   
    
        //actualizar cantidad de registros
    posicion = tamCampos * 2; //ubico en el campo adecuado
    arch_indice.seekp(posicion, fstream::beg);
    temp = (formatear_casilla(tamCampos, to_string(cantRegistros)));       
    arch_indice.write(&temp[0], tamCampos);
        
    arch_indice.close();
    
}