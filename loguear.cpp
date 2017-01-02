#include "Funciones.h"

void loguear(Usuario *p_usuario)
{  // escribir _bye para salir    
    cout << "Logueo...\n\n";
    string user, comando;
    cout << "User:\t";
    cin >> user;
    if (user == salir) return;
    else{
        //leer el tamanho de campos y la cantidad de la tabla de usuarios
            // tamanho para buscar User en indice, obtener ID
            // cantidad de campos para que con el ID halle la "posicion" adecuada
                // para iniciar la busq binaria de registros
        vector<Tam> v(valores_primera_linea(tabla_usuarios));
        
        Tam tamCampos = v[0];
        Tam cantCampos = v[1];
        // Tam cantRegistros = v[2];
        
        //busco "posicion de user"  en indice, tengo ID, voy a ID (busqueda binaria en tabla) salto a pass y confirmo 
        Entero posicion_user; 
        while ((posicion_user = buscar_en_indice("Indice_" tabla_usuarios "_User", tamCampos, user)) == -1){ // retorna posicion o -1
            cout << user << " no está registrado.\n\n";
            cout << "User:\t";
            cin >> user;
            if (user == salir) return;
        }              
        
        //leo de consola el pass a verificar
        string pass;
        cout << "Pass:\t"; cin >> pass; 
        if (pass == salir) return;
        
        //con "posicion_user" obtengo ID, en el mismo indice
        char c[tamCampos];
        fstream arch;
        arch.open("Indice_" tabla_usuarios "_User"  ext, fstream::in);    
        arch.seekg(posicion_user + tamCampos, fstream::beg);        
        arch.read(&c[0],tamCampos);
        string id(c);
        arch.close();
        
        //busco la posicion del ID en la tabla
            //busqueda binaria
                //datos para la busqueda binaria
        arch.open(tabla_usuarios ext, fstream::in);
        Entero posicion = tamCampos*3 + 1 + (tamCampos*cantCampos + 1) -1;//antes del nuevo registro
        Entero low = posicion;
        arch.seekg(0, fstream::end);
        Entero high = arch.tellg();
        high -= 1;
        arch.close();                   
        istringstream id_(id);// porque lee "campo    ", con espacios
        id_ >> id;
        Entero posicion_id = busqueda_binaria_key_registro(tabla_usuarios, id, tamCampos, cantCampos, low, high);
           
        //con "posicion_id" leo Pass de la tabla, Pass tiene orden 6
        arch.open(tabla_usuarios ext, fstream::in);    
        arch.seekg(posicion_id + tamCampos*5, fstream::beg);
        arch.read(&c[0],tamCampos);
        istringstream c_(c);// porque lee "campo    ", con espacios
        c_ >> c;
        string pass_(criptar(c));
        arch.close();
        
        //verifico coincidencia de Pass
        while(pass != pass_){
            cout << "Pass incorrecto.\n\nPass:\t";
            cin >> pass;
            if (pass == salir) return;
        }
        //data a instancia usuario
        p_usuario->set_user(user);
            //colocando el nivel del usuario en la instancia
        arch.open(tabla_usuarios ext, fstream::in);    
        arch.seekg(posicion_id + tamCampos*4, fstream::beg);//Nivel tiene orden 5  
        arch.read(&c[0],tamCampos);
        c_.clear();
        c_.str(c);// porque lee "campo    ", con espacios
        c_ >> c;
        arch.close();
        p_usuario->set_valor_nivel(static_cast<Real> (stof(c)));
        
        cout << "\nListo.\nSesión: " << p_usuario->get_user()<< "\n\n";
    }
}