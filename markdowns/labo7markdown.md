summary: Segunda práctica de laboratorio FDP
id: laboratorio-7-fdp-0222
tags: workshop,iguide
categories: C
environments: Visual Studio Code
status: Published
feedback link: A link where users can go to provide feedback (e.g. the git repo or issue page)

# Fundamentos de Programación: Laboratorio 7

## Introducción

![logo-uca](./img/labo1/image001.jpg)

Este laboratorio consiste en el manejo de archivos desde un programa en C.

## Manejo de archivos en C

Toda la información ingresada durante la ejecución de un programa se pierde cuando este finaliza. En caso de que se quiera guardar datos, lo podemos hacer por medio de un archivo que guardaremos en nuestra computadora, el cual seguirá existiendo incluso si el programa termina de ejecutarse.

Los principales tipos de archivos que debemos conocer son:
+ **Archivos de texto (.txt)**: No hace falta explicar en qué consiste este tipo de archivo, solo necesitamos saber que el contenido es texto, es fácil de leer, modificar, requieren un poco más de espacio y proveen poca seguridad al contenido.
+ **Archivos binarios (.bin)**: Son archivos cuyo contenido se almacena en binario (0 y 1). A diferencia de los archivos de texto, son más difíciles de leer, pero pueden almacenar más datos y proveen mayor seguridad al contenido.

Por ahora nos enfocaremos en los archivos de texto.

## Operaciones con archivos

En C podemos realizar 4 operaciones básicas:
+ Crear un archivo nuevo.
+ Abrir un archivo existente.
+ Leer y escribir en un archivo.
+ Cerrar un archivo.

<br>
Para poder realizar estas operaciones necesitamos un nuevo tipo de puntero, el cual es:

```c
FILE* archivo;
```

Para abrir un archivo debemos utilizar la función <code>fopen()</code> y el puntero será la referencia utilizada en nuestro programa para poder manipular el archivo que deseamos.

La función recibe el nombre del archivo que deseamos manipular y el modo de manipulación:

|**Modo**|**Significado**|**Resultado**|
|--------|---------------|-------------|
|r|Leer (Read)|Si no existe, fopen() retorna NULL|
|w|Escribir (Write)|Si existe, sobreescribe el archivo, si no, lo crea|
|a|Adjuntar (Append)|Si existe, escribe información hasta el final del archivo, si no, lo crea|

Para abrir un archivo, simplemente utilizamos:

```c
archivo = fopen("prueba.txt", "m");
```

Donde <code>prueba.txt</code> es el nombre del archivo y <code>m</code> el modo.

Hay que cerrar el archivo cuando hayamos terminado de leerlo:
```c
fclose(archivo);
```

## Leyendo un archivo

Para leer un archivo hay varias opciones; sin embargo, la más sencilla, aunque limitada, es leer el archivo carácter por carácter, utilizando un ciclo while que determine si aún no se ha alcanzado el final del archivo con la palabra reservada EOF (End Of File):
```c
#include <stdio.h>

int main()
{
    FILE* a = fopen("numeros.txt", "r");
    
    //Es buena practica confirmar que el archivo se ha abierto correctamente
    if (a == NULL)
    {
        printf("ERROR!");
        return 1;
    }

    char ch;
    ch = fgetc(a);
    while (ch != EOF){
        printf("%c", ch);
        ch = fgetc(a);
    }

    fclose(a);

    return 0;
}
```

La función <code>fgetc()</code> obtiene un carácter de un archivo y pasa al siguiente, por lo que al hacerlo repetidas veces, eventualmente llegaremos al final del archivo.

## Escribir en un archivo

Para escribir en un archivo debemos utilizar el modo **w** y utilizar la función <code>fprintf()</code>, la cual funciona igual que la función <code>printf()</code>, con la diferencia de que el primer argumento es el puntero con el cual referenciamos nuestro archivo.

```c
#include <stdio.h>

int main()
{
    FILE *a = fopen("numeros.txt", "w");

    // Es buena practica confirmar que el archivo se ha abierto correctamente
    if (a == NULL)
    {
        printf("ERROR!");
        return 1;
    }

    int num = 1;

    do
    {
        scanf("%d", &num);
        fprintf(a, "%d", num);
        fprintf(a, "\n");
    } while (num != 0);

    fclose(a);
    return 0;
}
```

Este programa obtiene inputs del usuario y los va almacenando en un archivo llamado "numeros.txt".

## Consideraciones

+ Aunque no es estrictamente necesario, es buena práctica cerrar un archivo que fue abierto.
+ Existen varias maneras de leer un archivo. Se recomienda buscar más información sobre este tema y en especial sobre la función <code>fgets()</code> y sobre la función <code>fscanf()</code>.
+ Para poder utilizar la función <code>fopen()</code>, el archivo debe existir en el mismo directorio donde está nuestro programa. De no ser así, se debe enviar la ruta completa del archivo (C:/users/...).
+ Existe otro tipo de archivo que es extensión .csv, el cual es un archivo de texto que representa una hoja de cálculo de excel, donde cada fila es una fila de la hoja de cálculo, y cada columna de la misma fila se distingue mediante una coma (,) en el archivo de texto.
+ El modo **a** y el modo **w** funcionan exactamente igual si el archivo no existe aún en la computadora.

## Ejercicios de laboratorio
Usando los temas cubiertos en el laboratorio, cree los programas correspondientes para los siguientes enunciados:
1. Escriba un programa que en un archivo escriba los número positivos por el usuario y en otro los negativos.
2. Escriba un programa que de un archivo de texto que contiene números, obtenga su promedio y lo muestre en consola. Se sugiere utilizar la función <code>fgets()</code> y la función <code>atoi()</code>.
3. Escriba un programa que almacene cuantas letras **a** tiene una palabra en la primera línea, cuantas letras **e** en la segunda, cuantas letras **i** en la tercera, y así sucesivamente para las demás vocales.