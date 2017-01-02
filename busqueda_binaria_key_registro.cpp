#include "Funciones.h"

Entero busqueda_binaria_key_registro(string nombre_archivo, string key, Tam tamCampos,
                                        Tam cantCampos, Entero low, Entero high)
{
    fstream arch;
    arch.open(nombre_archivo + ext, fstream::in);
    
    Tam tamBloque = tamCampos*cantCampos+1;
    Tam mid;
    string c(" ",tamCampos);
    while(high - low > tamBloque){
        mid = (high - low)/(tamBloque*2);
        mid = (mid -1)*tamBloque + 1 + low;
        arch.seekg(mid,fstream::beg);
        arch.read(&c[0],tamCampos);
        if(c.compare(key) < 0)
            low = mid + tamBloque -1;
        else
            high = mid + tamBloque -1;
    }
    high = high - tamBloque +1;
    arch.seekg(high,fstream::beg);
    arch.read(&c[0],tamCampos);
    Entero r;
    istringstream c_(c);
    c_ >> c; // porque lee "campo    ", con espacios
    if (c.compare(key) == 0) 
        r = high;
    else
        r = -1;
    
    arch.close();
    return r;
}