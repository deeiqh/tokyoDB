#include "Funciones.h"

void agregar_registro(Usuario *usuario) // pide por consola el nombre de la tabla
{
    cout << "Nombre de tabla:\t";
    string nombre_tabla;
    cin >> nombre_tabla;   
    
    if (verificar_nivel(usuario, nombre_tabla)){
        //agregar_registro
        
        vector<Tam> v(valores_primera_linea(nombre_tabla));    
        Tam tamCampos = v[0];
        Tam cantCampos = v[1];   
        Tam cantRegistros = v[2];
        
        fstream arch_tabla;
        arch_tabla.open(nombre_tabla + ext, fstream::in | fstream::out);
        arch_tabla.seekg(tamCampos*3 + 1,fstream::beg);
        string cabecera;
        getline(arch_tabla, cabecera);
        
        istringstream is(cabecera);      
        
        //por cada campo pido
        string key_,campo, campo_;
        string registro("");
        fstream arch_indice;
        
        is >> campo;
        cout << campo << ":\t";
        cin >> key_;
        if (key_ == salir) { cout << "\n"; return;}
        registro += key_ + " "; 
        while(is >> campo){
            cout << campo << ":\t";
            cin >> campo_;
            if (campo_ == salir) { cout << "\n"; return;}
            if (campo == "Pass")
                campo_ = criptar(campo_);
            registro += campo_ + " ";
            //si no hay archivo indice del campo, seguir pidiendo campos
            //si hay indice, agregar al arch indice            
            arch_indice.open("Indice_" + nombre_tabla + "_" + campo + ext, fstream::in | fstream::out);
            if (arch_indice.is_open()){
                cout << "entrooo";
                arch_indice.close();
                arch_indice.clear();
                agregar_a_indice("Indice_" + nombre_tabla + "_" + campo, key_, campo_);                   
            }
            
        }
        //escribo en el archivo el registro       
        arch_tabla.seekp(0, fstream::end);
        is.clear();
        is.str(registro);
        string campo__;
        string linea("");
        while(is >> campo__){
            linea += formatear_casilla(tamCampos, campo__);
        }
        linea += "\n";
        arch_tabla << linea;
        
        
        //incrementar en 1 los registros
        Tam posicion = tamCampos * 2; //ubico en el campo adecuado
        arch_tabla.seekp(posicion, fstream::beg);
        string temp = (formatear_casilla(tamCampos, to_string(cantRegistros + 1)));       
        arch_tabla.write(&temp[0], tamCampos);
        
        arch_tabla.close();        

        cout << "\nRegistro agregado.\n\n";
    }        
}