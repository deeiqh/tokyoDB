#include "Funciones.h"

void agregar_a_indice(string nombre_indice, string key, string campo)
{
    //datos
    vector<Tam> v(valores_primera_linea(nombre_indice));    
    Tam tamCampos = v[0];
    Tam ordenCampo = v[1];    
    Tam cantRegistros = v[2];
    
    //levanto registros de indice a map, agrego registro a map, escribo map a indice
    fstream arch_indice;
    arch_indice.open(nombre_indice + ext, fstream::in | fstream::out);
    
    Tam posicion = tamCampos*3 + 1 + tamCampos*2 + 1; //posicion de primer registro del indice
    arch_indice.seekg(posicion, fstream::beg);
    
    map<string,string> mapa;
    
        //levanto registros a mapa
    char campo_[tamCampos];
    char key_[tamCampos]; // key del mapa   
    int i = 1;
    string temp1, temp2;
    istringstream is;
    for(int j = 0; j != cantRegistros; j++){
        arch_indice.read(&key_[0], tamCampos); // el key de la tabla es un campo del mapa
        
        posicion += tamCampos * (ordenCampo-1); //ubico en el campo adecuado
        arch_indice.seekg(posicion, fstream::beg);
        arch_indice.read(&campo_[0], tamCampos);

        // guardo en mapa
        is.str(string(key_));
        is >> temp1;
        
        is.clear();
        is.str(string(campo_));
        is >> temp2;
        mapa[temp1] = temp2; 
        
        posicion = (tamCampos*3 + 1 + tamCampos*2 + 1) + 
                    i*(tamCampos*2 + 1);//ubico en el siguiente registro
        i++;
        is.clear();
    }  
    //agrego mi registro
    mapa[campo] = key;
    // escribo map
    posicion = tamCampos*3 + 1 + tamCampos*2 +1; //posicion de primer registro de indice
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
    temp = (formatear_casilla(tamCampos, to_string(cantRegistros + 1)));       
    arch_indice.write(&temp[0], tamCampos);
        
    arch_indice.close();
    
    
}