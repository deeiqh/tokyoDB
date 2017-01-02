#include <iostream>
#include <string>
#include <fstream>
#include "Tabla.h"
#include "Indice.h"
#include "Usuario.h"
#include "Funciones.h"

using namespace std;



//#define archivos_a_existir nombre_archivo_niveles  " "  nombre_tabla_usuarios
    // archivos a existir:
    //                  Niveles, Usuario_NIVEL_operaciones, Tabla_Usuarios


int main(void)
{
    //----------------------------------------------------------------------------------------
    cout << "tokyoDB" << '\n'; // los archivo niveles, tabla de usuario con admin y archivo de operaciones
                                    //estan hardcodeados
    
    //verificar_existencia(archivos_a_existir); //si no se crea la cabecera
        // archivos a existir:
        //                  Niveles, Usuario_NIVEL_operaciones, Tabla_Usuarios
    //----------------------------------------------------------------------------------------
    
    //----------------------------------------------------------------------------------------
    cout << "niveles:\t"; //ver los niveles de tokyoDB, archivo de niveles hardcodeado
    
    ver_niveles();
    
    //----------------------------------------------------------------------------------------
    
    //----------------------------------------------------------------------------------------
    //hardcodeando adecuadamente la cabecera y usuario admin en la Tabla_Usuarios (usuario admin por defecto)
    // solo se da la primerisima vez
    if(novicidad(nombre_tabla_usuarios))      
        hardcodear_admin();      
    //----------------------------------------------------------------------------------------
    
    //----------------------------------------------------------------------------------------
    cout << "login:" << '\n';
    
    cout << "\t user\t ¿registrarse?(s)\t";   
    
    string user;
    cin >> user;
    
    if (user == "s") // si se quiere registrar        
        registrar_usuario();
    else{ // si solo se loguea
        cout << "\t pass\t";
        string pass;
        cin >> pass;

        cout << "Ok, " << user;
    }
    //----------------------------------------------------------------------------------------
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*
    string nombre = "datos_personales";
    string tipo = "Datos";
    string key = "DNI";
    string campos = "CUI Apellido Pais";
    Tam long_campo = 15;
    
    Tabla t_dp(nombre, tipo, key, campos,long_campo);   //TABLA
    
    Registro *ptr_rt = t_dp.genera_registro();    // REGISTRO TIPO TABLA,  DATA DEL USUARIO    
    
    string campo_index = "Apellido";
    Indice i_dp_a(&t_dp, campo_index);//   ARCHIVO INDICE SEGUN campo_index, con orden_campo
    
    Registro *ptr_ri = i_dp_a.genera_registro(ptr_rt); //GENERO REGISTRO PARA INDICE
    
    i_dp_a.indexar(ptr_ri);//indexar el registro en la tabla indiceLEVANTO ARCHIVO INDICE, ACOMODO Y SOBREESCRIBO
    //i_dp_a.indexar(); ordena una tabla indice sin ordenar
    
    i_dp_a.actualizar_td(&t_dp);//UPDATE REGISTRO DE INDEXACION DE TABLA
    
    t_dp.insertar(ptr_rt);                        // DATA A TABLA    
    */
    /*
    string campos = "CUI Apellido Pais";
    Tabla t_datos_personales("datos_personales","Datos","DNI",campos,15);
    
    Registro *ptr_registro = t_datos_personales.genera_registro();
    t_datos_personales.insertar(ptr_registro);
    
    
    
    if (!t_datos_personales.indexado("Apellido")){
        //existe un registro, si no esta indexado el campo que quiero lo
        //    ingreso, luego indexo (siempre se sobrescribe el mismo archivo indice) y cambio a 1
        
        Registro *ptr_registro2 = t_datos_personales.genera_registro();        
        
        
        Indice indice_tdp_apellido(&t_datos_personales, "Apellido"); // crea la tabla de indice, ya se escribe la cabecera
        Registro *ptr_reg = indice_tdp_apellido.genera_registro(ptr_registro2); // solo devuelvo key y el apellido
        indice_tdp_apellido.insertar(ptr_reg); //insertar en posicion adecuada (se formatea el registro)
        
        //actualizar de 0 a 1 en la tabla, tengo orden_campo
        indice_tdp_apellido.actualizar_td(&t_datos_personales); //td tabla de datos
        
        t_datos_personales.insertar(ptr_registro2);    
    }
    
    */
    
    
    
    
    
    return 0;
}

