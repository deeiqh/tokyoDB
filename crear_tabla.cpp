#include "Funciones.h"

void crear_tabla(Usuario *usuario)
{
    cout << "Nombre de tabla:\t";
    string nombre_tabla;
    cin >> nombre_tabla;
       
    fstream arch_tabla;
    arch_tabla.open(nombre_tabla + ext, fstream::in | fstream::out);
    
    if(!arch_tabla.is_open()){//si es tabla nueva tabla nueva
        
        arch_tabla.clear();
        arch_tabla.open(nombre_tabla + ext, fstream::binary | fstream::out);
        arch_tabla.close(); //se crea la tabla
        
        if (verificar_nivel(usuario, nombre_tabla)){
            //escribir linea 1 y cabecera
            crear_tabla_(nombre_tabla);
            cout << "La tabla se ha creado.\n\n";
        }        
        else{
            remove((nombre_tabla + ext).c_str()); //eliminar si el nivel no es adecuado
            cout << "La tabla NO se ha creado.\n\n";
        }
    }
    else{        
        cout << "La tabla " << nombre_tabla << " ya existe.\n\n";
    }
    
    
    
    
    /*
    //primera linea
    string linea("");
    Tam tamCampo = static_cast<Tam> (stoul("20"));
    linea += formatear_casilla(tamCampo, "20"); // casilla es el valor individual a ser escrito
    linea += formatear_casilla(tamCampo, "8");
    linea += formatear_casilla(tamCampo, "1") + "\n";    
    arch_usuarios << linea;
     * */
}
