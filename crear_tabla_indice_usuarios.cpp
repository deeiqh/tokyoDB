#include "Funciones.h"

void crear_tabla_indice_usuarios() // crea tablas hardcodeadas
{
    //creadno tabla de usuarios
    fstream arch_usuarios;
    arch_usuarios.open(tabla_usuarios ext, fstream::binary | fstream::out);
    
    //primera linea
    string linea("");
    Tam tamCampo = static_cast<Tam> (stoul("20"));
    linea += formatear_casilla(tamCampo, "20"); // casilla es el valor individual a ser escrito
    linea += formatear_casilla(tamCampo, "8");
    linea += formatear_casilla(tamCampo, "1") + "\n";    
    arch_usuarios << linea;
    
    //linea 2
    linea = "";
    linea += formatear_casilla(tamCampo, "ID");
    linea += formatear_casilla(tamCampo, "User");
    linea += formatear_casilla(tamCampo, "Creador");
    linea += formatear_casilla(tamCampo, "Eliminado");
    linea += formatear_casilla(tamCampo, "Nivel_valor");
    linea += formatear_casilla(tamCampo, "Pass");
    linea += formatear_casilla(tamCampo, "TipoDoc");
    linea += formatear_casilla(tamCampo, "NumDoc") + "\n";
    arch_usuarios << linea;
    
    //linea 3 - registro de usuario admin
    linea = "";
    linea += formatear_casilla(tamCampo, "1");
    linea += formatear_casilla(tamCampo, "admin");
    linea += formatear_casilla(tamCampo, "God");
    linea += formatear_casilla(tamCampo, "No");
    linea += formatear_casilla(tamCampo, "1");
    linea += formatear_casilla(tamCampo, criptar("admin"));
    linea += formatear_casilla(tamCampo, "DNI");
    linea += formatear_casilla(tamCampo, "777") + "\n";
    arch_usuarios << linea;
    
    arch_usuarios.close();
    
    //crear archivo indice de User
        //datos para el archivo indice
    vector<Tam> v(valores_primera_linea(tabla_usuarios));
    Tam tam_campo_usuarios = v[0];
    Tam cant_campo_usuarios = v[1];
        //crear archivo indice
    fstream arch_indice;
    arch_indice.open("Indice_"  tabla_usuarios  "_User"  ext, fstream::binary | fstream::out);
        //linea 1
    linea = "";
    linea += formatear_casilla(tamCampo, to_string(tam_campo_usuarios));    
    linea += formatear_casilla(tamCampo, "2");// 2 es el numero de orden del campo user en la tabla
    linea += formatear_casilla(tamCampo, "1") + "\n"; //1 es la cantidad de registros en la tabla indice
    arch_indice << linea;
        //linea 2
    linea = "";
    linea += formatear_casilla(tamCampo, "User");
    linea += formatear_casilla(tamCampo, "ID") + "\n";
    arch_indice << linea;   
    
        // colocar registro en indice    
    linea = "";
    linea += formatear_casilla(tamCampo, "admin");
    linea += formatear_casilla(tamCampo, "1") + "\n";
    arch_indice << linea;   
    arch_indice.close();
    
    //crear archivo indice de Pass
        //crear archivo indice
    arch_indice.open("Indice_"  tabla_usuarios  "_Pass"  ext, fstream::binary | fstream::out);
        //linea 1
    linea = "";
    linea += formatear_casilla(tamCampo, to_string(tam_campo_usuarios));
    linea += formatear_casilla(tamCampo, "6");// 1 es el numero de orden del campo user en la tabla
    linea += formatear_casilla(tamCampo, "1") + "\n"; //1 es la cantidad de registros en la tabla indice    
    arch_indice << linea;
        //linea 2
    linea = "";
    linea += formatear_casilla(tamCampo, "Pass");
    linea += formatear_casilla(tamCampo, "ID") + "\n";
    arch_indice << linea;   
    
        // colocar registro en indice    
    linea = "";
    linea += formatear_casilla(tamCampo, criptar("admin"));
    linea += formatear_casilla(tamCampo, "1") + "\n";
    arch_indice << linea;   
    
    arch_indice.close();    
    
    //crear tabla de niveles
    fstream arch_niveles;
    arch_niveles.open(tabla_niveles ext, fstream::binary | fstream::out);
    
    //primera linea
    linea = "";
    tamCampo = static_cast<Tam> (stoul("20"));
    linea += formatear_casilla(tamCampo, "20"); // casilla es el valor individual a ser escrito
    linea += formatear_casilla(tamCampo, "3");
    linea += formatear_casilla(tamCampo, "3") + "\n";    
    arch_niveles << linea;
    
    //linea 2
    linea = "";
    linea += formatear_casilla(tamCampo, "ID");
    linea += formatear_casilla(tamCampo, "Valor");
    linea += formatear_casilla(tamCampo, "Nombre") + "\n";
    arch_niveles << linea;
    
    //linea 3 - registro de usuario admin
    linea = "";
    linea += formatear_casilla(tamCampo, "1");
    linea += formatear_casilla(tamCampo, "1");
    linea += formatear_casilla(tamCampo, "Administrador") + "\n";
    arch_niveles << linea;
    linea = "";
    linea += formatear_casilla(tamCampo, "2");
    linea += formatear_casilla(tamCampo, "2");
    linea += formatear_casilla(tamCampo, "Profesor") + "\n";
    arch_niveles << linea;
    linea = "";
    linea += formatear_casilla(tamCampo, "3");
    linea += formatear_casilla(tamCampo, "3");
    linea += formatear_casilla(tamCampo, "Alumno") + "\n";
    arch_niveles << linea;
    
    arch_niveles.close();
        
}