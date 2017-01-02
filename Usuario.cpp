#include "Usuario.h"
#include "Funciones.h"

using namespace std;

mapSF *mapear_funciones(void);
void Usuario::maneja_tokyoDB()
{
    mapSF *p_mapa_funciones = mapear_funciones();    
    
    //crear archivo por defecto Tabla_Usuarios, si no esta creado previamente
    fstream arch_usuarios;
    arch_usuarios.open(tabla_usuarios ext, fstream::in | fstream::out);
    if (!arch_usuarios.is_open()){
        crear_tabla_indice_usuarios(); // se crea la tabla y se indexa el campo user
        
    }
    
    set_p_mapa_funciones(p_mapa_funciones);
}

mapSF *mapear_funciones()
{
    mapSF *mapa = new mapSF;
    (*mapa)["loguear"] = loguear;
    (*mapa)["eliminar_tabla"] = eliminar_tabla;
    (*mapa)["eliminar_indice"] = eliminar_indice;
    (*mapa)["crear_tabla"] = crear_tabla;
    (*mapa)["indexar_campo"] = indexar_campo;
    (*mapa)["agregar_campo"] = agregar_campo;
    (*mapa)["agregar_registro"] = agregar_registro;
    (*mapa)["modificar_campo_registro"] = modificar_campo_registro;
    (*mapa)["eliminar_registro"] = eliminar_registro;
    (*mapa)["mostrar_registro"] = mostrar_registro;
    return mapa;
}