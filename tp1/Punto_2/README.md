## PUNTO 2 - ARCHIVO `.gitignore`
### para que utiliza el archivo .gitignore?
es un archivo de texto utilizado por Git para indicar que archivos o carpetas no deben ser rastreados o subidos al repositorio. Su función principal es mantener el proyecto más ordenado, evitar que se subas archivos temporales o inncesarios.
Generalmente se coloca en el directorio raiz del proyecto, aunque tambien es posible configurar un .gitignore global que aplique a todos los repositorios del usuario.

### por qué es conveniente incluirlo?
es conveniente inlcuir el archivo .gitignore porque ayuda a mantener el repositorio limpio y organizado, evitando que se agreguen archivos irrelevantes al repositorio, ademas facilita el trabajo colaborativo al evitar conflictos con archivos locales de cada desarrollador y permite que cada uno tenga sus propias configuraciones sin afectar el codigo compartido

### cuando se debe crear?
- lo ideal es crear el archivo al inicio del proyecto, antes de comenzar a subir archivos al repositorio. sin embargo, también puede agregarse más adelante si se detecta que hay archivos que no deberían formar parte del repositorio

### como se configura el archivo?
- el archivo `.gitignore`se configura escribiendo dentro de él los nombres de los archivos y carpetas que se quieren ignorar
 por ejemlpo:

- `*.exe` :ignora todos los archivos ejecutables.
- `*.o` :ignora todos los archivos objeto.
- `carpeta/` :ignora una carpeta completa y todo su contenido.
- `ignorado.txt` : ignora un archivo específico con ese nombre.
- `# comentario` :permite escribir comentarios dentro del archivo.


## PUNTO 3f:
- el programa toma un numero entero, para este caso es 452,  y le aplica una serie de transformaciones a la variable original:
- la funcion **invertido -> (f_alpha)** toma el valor original del número y lo invierte digito a digito. En este caso: 452 -> 254

- la funcion **mitadInvertido -> (f_beta)** divide el valor acutual entre 2
254 / 2 = 127

-la funcion **sumaDigitos -> (f_gamma)** calcula la suma de los digitos del numero actual y la suma al propio valor
suma = 7 + 2 + 1 = 10
resultado final = 127 + 137

### Observacion: 
durante la ejecucion en modo debugger se observó que el puntero siempre apunta a la misma direccion de memoria mientras que el valor almacenado cambia en cada funcion


## PUNTO 3g:
- al codigo le faltaba incluir la biblioteca  '<stdio.h>' ya que utiliza 'prinf' y 'scanf' y sin la biblioteca el compilador no reconoce correctamente estas funciones
- en la linea 14, valor1 se estaba pasando como valor en lugar de direccion, lo que provoca una falla en la ejecucion
- en las lineas 19 y 25, falta el ; al final de la instruccion, es un error de sintaxis que impide compilar el programa
- en la linea 5, la funcion recibe una copia del numero y al multiplicarlo por 2 ese cambio no afecta a valor1 en el main por lo que se modificó  la funcion para que reciba un puntero y asi poder cambiar directamente la variable original
