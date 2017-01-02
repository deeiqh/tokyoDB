#include "Funciones.h"

string formatear_casilla(Tam tamCampo, string casilla)
{
    string format(casilla);
    for(int i = 0; i != tamCampo - casilla.size(); i++)//tamaño de cada campo - size de lo leido = espacio libre en el campo
            format.pb(' ');
    return format;
}