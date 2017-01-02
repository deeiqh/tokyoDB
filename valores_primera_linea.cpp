#include "Funciones.h"

vector<Tam> valores_primera_linea(string nombre_archivo)
{
    vector<Tam> v;
    fstream arch;        
    arch.open(nombre_archivo + ext, fstream::in);
    arch.seekg(0, fstream::beg);

    string linea_, tamCampos_, cantCampos_, cantRegistros_;
    getline(arch,linea_);
    istringstream linea(linea_);
    linea >> tamCampos_;
    Tam tamCampos = static_cast<Tam> (stoul(tamCampos_));
    v.pb(tamCampos);
    
    linea >> cantCampos_;
    Tam cantCampos = static_cast<Tam> (stoul(cantCampos_));  
    v.pb(cantCampos);
    
    linea >> cantRegistros_;
    Tam cantRegistros = static_cast<Tam> (stoul(cantRegistros_));  
    v.pb(cantRegistros);
    
    arch.close();    
    
    return v;
}