tokyoDB

Es una base de datos orientada a cualquier tipo de uso (Biclitecas, Aulas, Comedor, etc), pues permite crear tablas, registros, modificar registros, etc, de manera genérica.

Además se tiene predefinido ciertos niveles para los usuarios, así se logra que ciertas tablas solo sean accedidas o editadas por ciertos usuarios.

El usuario predefinido es "admin" (y contraseña "admin") , de nivel Admininstrador.

Todos los archivos de texto son generados por el programa; es decir, solo es necesario tener los .cpp y .h para poner a funcionar la base de datos.
Nombre de las tablas:
                Tabla_"NombreDeTabla"_"NivelMinimoParaUsarla".txt
                    Por defecto solo se crean los niveles Administrador(1), Profesor(2), Alumno(3), están en la tabla      Tabla_Niveles_Administrador.txt, si se quiere se pueden agregar o quitar niveles y para ello se debe indicar el nombre y el valor del nivel (que puede ser un número real). Como dice el nombre de la tabla hay que ser de nivel Administrador para editarla.
            
                    
El uso es intuitivo, solo hay que conocer los comandos, entre ellos: 

  agregar_registro
  
  modificar_campo_registro
  
  indexar_campo
  
  crear_tabla
  
  Próximamente: 
  
  eliminar_registro 
  
  eliminar_tabla // ¿será adecuado implementarlo?
  
  eliminar_indice // remove
  
  agregar_campo // solo posible al crear una tabla
  
  mostrar_registro // para búsquedas complejas
 
