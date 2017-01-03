#include "Funciones.h"

void modificar_campo_registro(Usuario *usuario)
{
    cout << "Nombre de tabla:\t";
    string nombre_tabla;
    cin >> nombre_tabla;   
    
    if (verificar_nivel(usuario, nombre_tabla)){
        //pedir key
        string key_;
        cout << "Key:\t";
        cin >> key_; 
        
        //pedir campo,
        string campo;
        cout << "Campo (de la cabecera):\t";
        cin >> campo; 
        
        //pedir campo nuevo
        string campo_;
        cout << "Campo Nuevo:\t";
        cin >> campo_;
        if (campo == "Pass")
                campo_ = criptar(campo_);
        
        //si no esta indexado solo se sobreescribe el campo
        fstream arch_indice;
        string nombre_indice = "Indice_" + nombre_tabla + "_" + campo;
        arch_indice.open( nombre_indice + ext, fstream::in | fstream::out);
        
        if (!arch_indice.is_open()){
            string campo__; //campo__ es el original del campo
            campo__ = sobreescribir_campo(nombre_tabla, key_, campo, campo_);
        }else{
            //si esta indexado se sobreescribe el campo en tabla y se actualiza el indice
            
            string campo__;
            campo__ = sobreescribir_campo(nombre_tabla, key_, campo, campo_); // retorna campo__ y orden
            
            //levanto registros de indice a map, 
                // elimino campo_ de mapa 
                    // agrego registro a map, escribo map a indice
            
            //datos
            vector<Tam> v(valores_primera_linea(nombre_indice));    
            Tam tamCampos = v[0];
            Tam cantCampos = v[1];
            Tam cantRegistros = v[2];
            Tam posicion = tamCampos*3 + 1 + tamCampos*2 + 1; //posicion de primer registro del indice
            map<string,string> *mapa;

            //levanto registros a mapa
            arch_indice.close();
            mapa = levantar_registro_mapa(nombre_indice, tamCampos, cantCampos, 2, cantRegistros, posicion);
            
            //elimino campo_ actual del mapa
            istringstream is(campo__);
            is >> campo__;
            cout << campo__;
            (*mapa).erase(campo__);
            
            //agrego mi registro
            (*mapa)[campo_] = key_;
            
            // escribo map
            posicion = tamCampos*3 + 1 + tamCampos*2 +1; //posicion de primer registro de indice
            escribir_mapa(nombre_indice, mapa, tamCampos, posicion);
            
            delete mapa;
        }
        cout << "Campo modificado.\n\n";
    }
}