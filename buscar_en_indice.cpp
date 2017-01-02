#include "Funciones.h"

Entero buscar_en_indice(string nombre_tabla, Tam tamCampos, string campo)
{   //se asume que el archivo indice existe
    fstream arch_indice;
    arch_indice.open(nombre_tabla + ext, fstream::in);
    
    //datos para la busqueda binaria de el primer campo (key) en un rango de registros de
                                                            // cualquier archivo
    Entero posicion = tamCampos*3 + 1 + tamCampos*2 + 1 -1;//antes del nuevo registro
    Entero low = posicion;    
    
    arch_indice.seekg(0, fstream::end);
    Entero high = arch_indice.tellg();
    high -= 1;
    
    arch_indice.close();
    
    Entero posicion_campo = busqueda_binaria_key_registro(nombre_tabla, campo, tamCampos, 2, low, high); //abre y cierra archivo
    
    return posicion_campo; 
}