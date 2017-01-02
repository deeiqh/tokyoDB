
#include "Funciones.h"
#include "Usuario.h"
#include "Indice.h"

using namespace std;

#define pb push_back
#define tr(c,it) for(auto it = c.begin(); it != c.end(); it++)

bool buscar_linea(string nombre_archivo, string linea)
{
    
    fstream arch; 
    arch.open(nombre_archivo+ext, fstream::in); 
    string temp;
    while(!arch.eof()){
        getline(arch, temp);
        if (temp == linea){
            arch.close();
            return true;
        }
    }
    arch.close();
    return false;
    
}

bool novicidad(string nombre_archivo)
{
    fstream archivo;
    archivo.open(nombre_archivo+ext, fstream::in);
    if (archivo.is_open()){
        archivo.close();
        return false;
    }else
        return true;
}


string criptar(string pass)
{
    char key = 'J';
    string pass_;
    char temp;
    tr(pass,it){
        temp = *it ^ key;
        pass_.pb(temp);
    }
    return pass_;
}



void registrar_usuario()
{
    string nivel, pass, user;
    cout << "\t\tuser:\t";
    cin >> user;
    cout << "\t\tnivel:\t";
    cin >> nivel;        


    while (!buscar_linea(nombre_archivo_niveles, nivel)) {//verificar que nivel sea permitido
        cout << "\t\tnivel:\t";
        cin >> nivel;
    }

    cout << "\t\tpass:\t";//registrar
    cin >> pass;
    pass = criptar(pass);

    Doc d;
    cout << "\t\ttipoDoc:\t";
    cin >> d;

    NumDoc n;
    cout << "\t\tnumDoc:\t";
    cin >> n;

    Registro *reg = new Registro(user + " " + nivel + " " + pass + 
                                    " " + "No" + " " + d + " " + n);// el tipo de documento podria ser no relacional

    registrar_en_tabla(nombre_tabla_usuarios, reg); // registrar en tabla existente
    
}

void ver_niveles()
{
    fstream archivo_de_niveles;
    archivo_de_niveles.open(nombre_archivo_niveles ext, fstream::in);
    while(!archivo_de_niveles.eof()){
        string nivel;
        getline(archivo_de_niveles, nivel);
        cout << " - " << nivel;
    }
    cout << '\n';
}

void hardcodear_admin()// hardcodea la Tabla_Usuarios y crea Indice_usuarios_Nivel
{
    //crear tabla (archivo+cabeceras+formatos)
    string campo_key("User");
    string nombres_campos("Nivel Pass Eliminado TipoDoc NumDoc");
    Tam tamanho_campo = 15;
    string tipo("Datos");
    Tabla t_usuarios(true, nombre_tabla_usuarios, tipo, campo_key, nombres_campos, tamanho_campo);
    
    //escribir registro de admin
    Registro *reg = new Registro("admin Admin " + criptar("l0cvra") + " No DNI 666");
    
    
    registrar_en_tabla(nombre_tabla_usuarios, reg);// se hace delete a reg
                                                   // registrar = insertar + agregar un 1
    
    //hardcodear indice de usuarios
    Indice indice_user_nivel(&t_usuarios, true, "Nivel"); // indexar user, nivel . true es la novicidad de la tabla
                                                            // de donde se indexa
    //Registro *reg_ = indice_user_nivel.genera_registro(reg);
    //indice_user_nivel.indexar( reg_ ); // hace delete al registro usado;
    
}

void insertar_orden_linea(string nombre_tabla, Tam orden)
{
    //string resultado = "orden - - -\n"      
    
}

void insertar_info_linea(string nombre_tabla, string info_) // string info: cantRegistros tamCampo cantCampos tipo
{   
    // string info: cantRegistros tamCampo cantCampos tipo - - 
    istringstream info(info_);
    string temp;    
    info >> temp;
    info >> temp;
    Tam tamCampo = static_cast<Tam> (stoul(temp));
    info >> temp;
    Tam cantCampos = static_cast<Tam> (stoul(temp));
    for (int i = 0; i != cantCampos + 1 - 4; i++)
        info_ += " - ";
    
    
    // string formateado: "cantRegistros tamCampo cantCampos tipo  -     -    "
    info.clear();
    info.str(info_);
    string format;
    for(int i = 0; i < cantCampos + 1; i++){
        info >> temp; 
        format.append(temp);
        for(int j = 0; 
                            j < tamCampo - temp.size();//tamaño de cada campo - size de lo leido = espacio libre en el campo
                                                        j++)
                format.pb(' ');        
        if(i < cantCampos -1) // para no imprimir el ultimo ' '
                format.pb(' ');
    }
    
    //escribir en primera linea el format + \n
    fstream *archivo;
    archivo.open(nombre_tabla+ext,fstream::in |fstream::out);
    archivo.seekp(fstream::beg);
    archivo << format << '\n';
    archivo.close();
    
}

/*
void agregar_nivel(string nombre_archivo, string nivel);
void verificar_existencia(string nombres_archivos){
 
    string nombre_archivo;
    istringstream line(nombres_archivos);
    
    while(line >> nombre_archivo){
        
        fstream archivo;
        archivo.open(nombre_archivo, fstream::in);
        
        if (archivo.is_open()){ // si archivo de niveles, archivo de usuarios existe
            
            archivo.close();            
            
        }else{ //crear archivos: niveles, operaciones y usuario
            
            if (nombre_archivo == nombre_archivo_niveles){       
         
                string niveles_ = "Alumno Profesor Visitante";
                istringstream niveles(niveles_);
                string nivel;
                while (niveles>>nivel)
                    agregar_nivel(nombre_archivo,nivel);
                
                archivo.open(nombre_archivo, fstream::in);
                while(!archivo.eof()){ //es el archivo de niveles, crear los archivos de operaciones para los niveles
                    getline(archivo,nivel);
                    fstream archivo_operaciones;
                    string nombre_archivo_operaciones("Usuario_" + nivel + "_operaciones");
                    archivo_operaciones.open(nombre_archivo_operaciones, fstream::out);
                    archivo_operaciones.close();                    
                }                
                archivo.close();
            }
            else if(nombre_archivo == nombre_tabla_usuarios){
                string campo_key("User");
                string nombres_campos("Nivel Pass Eliminado TipoDoc NumDoc");
                Tam tamanho_campo = 10;
                Tabla t_usuarios(true, nombre_tabla_usuarios, "Datos", campo_key, nombres_campos, tamanho_campo);
            }       
            
            
        }            
    }
    
}

void agregar_nivel(string nombre_archivo, string nivel){
    fstream archivo;
    archivo.open(nombre_archivo, fstream::app );
    archivo << nivel << '\n';
    archivo.close();
}
*/