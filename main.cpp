#include <iostream>
#include "Usuario.h"
#include "Funciones.h"

using namespace std;

int main(void)
{    
    Usuario *p_usuario = new Usuario;
    
    p_usuario->maneja_tokyoDB(); // cargar las funciones de tokyoDB
    mapSF *mapa_fun = p_usuario->get_p_mapa_funciones();  
    
    cout << "tokyoDB\nCuando quiera salir escriba "<< salir <<".\n\n"; // salir == _bye    
    
    loguear(p_usuario); // el usuario tendra un handle (por defecto hay un usuario admin)
    
    if (p_usuario->get_user() != ""){ // si se ha logueado    
        //en este punto el usuario debe estar logueado
        //esperando comando
        cout << "Comando: ";
        string comando;        
        while (cin >> comando){
            while (mapa_fun->find(comando) == mapa_fun->end() && comando != salir){ // verificar si está el comando
                cout << "¿" << comando << "?. Prueba con otra sentencia.\n\n";
                cout << "Comando: ";
                cin >> comando;
            }

            if (comando == salir) break;        
            (*mapa_fun)[comando](p_usuario); // usar la funcion cargada segun el comando, ejm: loguear(p_usuario);
            cout << "Comando: ";
        }
    }
    
    cout << "See you, " << p_usuario->get_user() << ", our tokyoDB cowboy for today.\n";
    
    delete p_usuario->get_p_mapa_funciones();
    delete p_usuario;
    
    return 0;    
}

