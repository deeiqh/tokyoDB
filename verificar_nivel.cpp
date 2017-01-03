#include "Funciones.h"


bool verificar_nivel(Usuario *usuario, string nombre_tabla)
{
    fstream arch_tabla;
    arch_tabla.open(nombre_tabla + ext, fstream::in | fstream::out);
    if(!arch_tabla.is_open()){//verificar que exista la tabla
        cout << "La tabla " << nombre_tabla << " no existe.\n\n";
        return false;
    }
    else{
        arch_tabla.close();
        arch_tabla.clear();
        //extraer el nivel del nombre de la tabla
        istringstream line(nombre_tabla);
        string nivel;
        getline(line, nivel, '_');
        getline(line, nivel, '_');
        getline(line, nivel, '_');
        
        // indexar si no existe el indice niveles-nombre
        fstream arch_indice;
        arch_indice.open("Indice_" tabla_niveles "_Nombre" ext, fstream::in | fstream::out);
        if(!arch_indice.is_open()){
            indexar_campo_(tabla_niveles, "Nombre");
            arch_indice.open("Indice_" tabla_niveles "_Nombre" ext, fstream::in | fstream::out);
        }        
        
        // buscar id del nombre del nivel, return false si no se encuentra el nombre del nivel
        Entero posicion;
        vector<Tam> v(valores_primera_linea(tabla_niveles));    
        Tam tamCampos = v[0];
        Tam cantCampos = v[1];
        Entero low = tamCampos*3 + 1 + tamCampos*2 + 1 -1;
        arch_indice.seekg(0, fstream::end);
        Entero high = arch_indice.tellg();
        high -= 1;
        posicion = busqueda_binaria_key_registro("Indice_" tabla_niveles "_Nombre",
                    nivel, tamCampos, 2, low, high);
        if (posicion == -1){
            cout << "Su nivel no está registrado\n\n";
            return false;     
        }
        string id; //leo el id
        posicion += tamCampos;
        arch_indice.seekg(posicion, fstream::beg);
        char c[tamCampos];
        arch_indice.read(&c[0], tamCampos);
        istringstream id_(c);
        id_ >> id;        
        
        arch_indice.close();
        
        // con el id buscar en la tabla el valor del nivel
        low = tamCampos*3 + 1 + tamCampos*cantCampos + 1 -1;
        arch_tabla.open(tabla_niveles ext, fstream::in | fstream::out);
        arch_tabla.seekg(0, fstream::end);
        high = arch_tabla.tellg();
        high -= 1;
        posicion = busqueda_binaria_key_registro(tabla_niveles,
                    id, tamCampos, cantCampos, low, high);
        
        string valor; //leo el valor de ese id
        posicion += tamCampos;
        arch_tabla.seekg(posicion, fstream::beg);
        arch_tabla.read(&c[0], tamCampos);
        id_.clear();
        id_.str(c);
        id_ >> valor;      
        arch_tabla.close();
        
        // comparar los valores: valor del usuario y valor de la tabla
        if ((usuario->get_valor_nivel()) <= static_cast<Real> (stof(valor)))
            return true;
        else{
            cout << "Se requiere mayor nivel para la operación.\n\n";
            return false;
        }
        
    }    
    
    
    // cout << "Para esta operación su nivel es inferior al míninimo\n\n";
}
