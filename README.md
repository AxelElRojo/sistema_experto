# Sistema Experto
Árbol de decisión que clasifica las aves encontradas en el *Bosque Colomos*,
localizado en Guadalajara, Jalisco.

## Desarrollado por
- Axel Morales Torres
- Raymon Alejandro Ortiz Ríos

# Dependencias
El programa no depende de librerías externas, pero requiere GNU Make para la compilación.

# Compilación
Con el comando:
```console
make
```
Se genera un ejecutable llamado `akinator`, el programa se ha compilado y probado con g++ 12.2.0 en Linux. No se ha probado en otros sistemas operativos
ni con otras versiones del compilador.

# Ejecución
Con la terminal en el directorio que contiene el ejecutable:
```console
./akinator
```
# Archivo de datos
El archivo `arbol.preOrder` guarda el recorrido preorder del árbol de decisión, lo que permite guardar el conocimiento y cargarlo cuando el
programa es ejecutado.

Normalmente, los árboles binarios requieren de 2 recorridos para poderse recrear desde archivos, sin embargo, este no es el caso para un árbol
de decisión, es posible recrearlos utilizando sólo el recorrido preorder.

En el archivo se guardan el dato del nodo y un booleano que indica si el nodo es rama u hoja. Para cargar el archivo se utiliza una función recursiva,
es el mismo procedimiento para guardar, pero en lugar de escribir al archivo, se lee el archivo.
