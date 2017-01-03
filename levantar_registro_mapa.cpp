#include "Funciones.h"

map<string,string> *levantar_registro_mapa(string nombre_archivo, Tam tamCampos, 
                                            Tam  cantCampos, 
                                            Tam ordenCampo, Tam cantRegistros, Tam posicion)
{
    fstream archivo;
    archivo.open( nombre_archivo + ext, fstream::in | fstream::out);
    archivo.seekg(posicion, fstream::beg);
    
    map<string,string> *mapa = new map<string,string>;
    
    char campo_[tamCampos];
    char key_[tamCampos]; // key del mapa   
    int i = 1;
    string temp1, temp2;
    istringstream is;
    
    for(int j = 0; j != cantRegistros; j++){
        
        archivo.read(&key_[0], tamCampos);

        posicion += tamCampos*(ordenCampo-1); //ubico en el campo adecuado
        archivo.seekg(posicion, fstream::beg);
        archivo.read(&campo_[0], tamCampos);

        // guardo en mapa
        is.str(string(key_));
        is >> temp1;

        is.clear();
        is.str(string(campo_));
        is >> temp2;
        if (ordenCampo == 2)//si es una archivo indice
            (*mapa)[temp1] = temp2; 
        else
            (*mapa)[temp2] = temp1;        

        posicion = (tamCampos*3 + 1 + tamCampos*cantCampos + 1) + 
                    i*(tamCampos*cantCampos + 1);//ubico en el siguiente registro
        
        i++;
        is.clear();
    } 
    
    archivo.close();
    
    return mapa;
}