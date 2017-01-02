#include "Tabla.h"
#include <iostream>
#include <sstream>
#include <map>

#define pb push_back

Tam Tabla::tam_registros() const
{
    return tamanho_campo * cant_campos();
}

Tam Tabla::cant_campos() const
{
    Tam n = 0;
    istringstream str(nombres_campos);
    string s;
    while(str >> s){
        n++;
    }
    return n;
}

string ingresar_campo(Tam tc)//tamaño de campo
{
    string temp;
    cin >> temp;
    while(temp.size() > tc){//que el tamaño del dato del campo no se mayor al establecido para el campo
        cin >> temp;
    }
    return temp;           
}
Registro *Tabla::genera_registro() 
{
    Registro *ptr_registro = new string;
    for(int i = 0; i < cant_campos()+1; i++){
        *ptr_registro += ingresar_campo(tamanho_campo);
        ptr_registro->pb(' ');
    }
    return ptr_registro;
}

Registro *Tabla::genera_cabecera()
{
    string *ptr_registro = new string(campo_key);
    (*ptr_registro) += " " + nombres_campos;
    return ptr_registro;

}

void Tabla::insertar(Registro *ptr_registro)
{
    
    istringstream is(*ptr_registro);
    string format;
    string temp;
    Tam cc = cant_campos() + 1;
    for(int i = 0; i < cc; i++){
        is >> temp; 
        format.append(temp);
        for(int j = 0; 
                            j < tamanho_campo - temp.size();//tamaño de cada campo - size de lo leido = espacio libre en el campo
                                                        j++)
                format.pb(' ');        
        if(i < cc -1) // para no imprimir el ultimo ' '
                format.pb(' ');
    }
    archivo.open(nombre+ext,fstream::in |fstream::app);
    archivo << format << '\n';
    archivo.close();
   
    delete ptr_registro;    
    
    
}

void registrar_en_tabla(string nombre_tabla, Registro *ptr_registro) // 1) nombre de tabla
{                                                           // 2) instancia tabla        
                                                            // 3) metodo insertar de tabla, usa el ptr_registro
                                                            // 4) subir a 1 en la linea 1 del archivo de tabla
    
    //con el nombre de tabla se levanta una tabla, permite insertar registros
    
    fstream archivo;
    archivo.open(nombre_tabla+ext, fstream::in );
    archivo.seekg(fstream::beg);
    
    string temp;
    getline(archivo, temp);//tomando números, para obtener el segundo(tamanho del campo)
    istringstream linea(temp);
    string num;
    linea >> num; linea >> num;
    Tam tamanho_campo = static_cast<Tam> (stoul(num));
    string tipo;
    linea >> tipo; linea >> tipo;
    
    getline(archivo, temp);//tomando cabecera
    archivo.close();
    linea.clear();
    linea.str(temp);
    string campo_key, campos;
    linea >> campo_key;
    getline(linea, campos);
    
    Tabla tabla(false, nombre_tabla, tipo, campo_key, campos, tamanho_campo);//tabla generica
 
    tabla.insertar(ptr_registro);
    
    //subir a 1 en la linea 1 del archivo de tabla
    // se hace aca y no en la clase tabla porque hay registros (cabceras, etc) queno deberian ser contados
    archivo.open(nombre_tabla+ext, fstream::in |fstream::out);        
    archivo.seekg(istream::beg);
    getline(archivo, temp);
    linea.clear();
    linea.str(temp);
    linea >> num;
    getline(linea,temp);
    temp = to_string( stoul(num)+1 ) + temp + "\n";
    archivo.seekp(ostream::beg);
    archivo << temp;
    archivo.close();
    
    
}

bool Tabla::indexado(string campo) // ver si el campo de la tabla esta indexado
{
    archivo.open(nombre+ext, istream:: in);
    //Tam move = (tamanho_campo+1)*cant_campos();
    //archivo.seekg(move, istream::beg());   
    
    string cabecera_t; istringstream cabecera;
    getline(archivo, cabecera_t); cabecera.str(cabecera_t);
    
    string valores_t; istringstream valores;
    getline(archivo, valores_t); valores.str(valores_t);    
    
    archivo.close();
    
    map<string,string> mapa;
    string val, val2;
    while (cabecera >> val && valores >> val2 ){
        mapa[val] = val2;
    }
    auto it = mapa.find(campo);
    if ( it != mapa.end() && it->second  == "1")
        return true;
    return false;
}



    
