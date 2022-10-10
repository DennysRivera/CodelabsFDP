author: Equipo de instructores FDP
summary: Segunda práctica de laboratorio FDP
id: laboratorio-5-fdp-0222
tags: workshop,iguide
categories: C
environments: Visual Studio Code
status: Published
feedback link: A link where users can go to provide feedback (e.g. the git repo or issue page)

# Fundamentos de Programación: Laboratorio 5

## Introducción

![logo-uca](./img/labo1/image001.jpg)

En este laboratorio se introducirá una de las estructuras de datos más utilizadas dentro de la programación: **arreglos**

## Arrays

### ¿Qué es un array?
A grandes rasgos, los arrays o arreglos (nombre en español) son estructuras de datos. Esto quiere decir que contiene elementos de un tipo de dato dado y los almacena de manera consecutiva en la memoria.

Los arreglos que estudiaremos a continuación son unidimensionales. Hay que tener en cuenta que los arreglos pueden ser multidimensionales; a los arreglos de dos dimensiones se les conoce como matrices.

### Características de un array
+ Solo puede almacenar datos de un solo tipo; es decir, un array de enteros solo puede almacenar enteros, un array de caracteres solo puede almacenar caracteres. Adicionalmente, el tipo de datos que almacena un array no se puede cambiar.
+ Es una estructura de datos estática, lo que significa que, una vez establecido su tamaño, no se puede modificar. Si se establece un array con tamaño de 10, solamente podrá almacenar un máximo de 10 datos.
+ En relación con el punto anterior, aunque no se puede superar el tamaño máximo del array, sí es posible establecer un máximo superior y solo usar las casillas que necesitemos. Por ejemplo, podemos almacenar 5 datos en un array de tamaño 10 y dejar 5 casillas vacías (tener en cuenta que puede mostrar un valor de 0 si queremos usar cualquiera de esas casillas vacías para algún proceso que no sea la asignación de valores). Las casillas vacías siempre ocuparán un espacio en memoria, incluso si no les asignamos valoes.
+ Cada casilla de un array se identifica con un número, llamado index (índice en español), que comienza desde 0. Para un array de tamaño 5, sus índices serían: 0, 1, 2, 3, 4.

## Representación visual de un array
![imagen-array](./img/labo5/arrays.svg)

## Declarando un array
### Partes de la declaración de un array
Un array se declara al igual que cualquier otra variable, por lo que es obligatorio incluir lo siguiente:
+ El tipo de dato del array; es decir, el tipo de datos que almacenará.
+ Un nombre que lo identifique.
+ El tamaño del array entre corchetes. Por ejemplo, [5] para un array de tamaño cinco. Alternativamente, podemos omitir el tamaño, siempre y cuando inicializemos el arreglo cuando lo declaremos.

**Ejemplo 1: Declaración de distintos tipos de arrays**
```c
// Este array es de tipo int, y es de tamaño 10
int arrayEnteros[10];

// Este array es de tipo float, y es de tamaño 15
float arrayFloats[15];

// Este array es de tipo char, y es de tamaño 5
char arrayChar[5];
```

**Ejemplo 2: Inicializando un array**
```c
// Un array se puede inicializar de la siguiente forma:
int array[5] = {1,2,3,4,5};
// La declaración del contenido debe ir entre llaves { }
// Los valores de la inicialización no pueden superar el tamaño
// del array

// Alternativamente, se puede omitir el tamaño del array
int array[] = {1,2,3,4,5,6,7};
// Lo anterior inicializa un array de tamaño 7
```

## Manejo de arrays
Cuando se tiene un array ya declarado, se pueden modificar los valores almacenados. Para esto, debemos llamar al array y especificar el **índice** del valor.
```c
#include <stdio.h>

int main(){
    // Se tiene un array ya declarado
    int array[5];

    // A continuación asignaremos sus valores:
    array[0] = 10;
    array[1] = 1;
    array[2] = 7;
    array[3] = 12;
    array[4] = 5;

    printf("El numero almacenado es: %d", array[0]);

    return 0;
}
```

Puesto que solo podemos acceder a una posición del array a la vez, el código anterior imprimirá 10, ya que es el valor en la posición 0 del array.

Para recorrer un array en su totalidad, o una parte según se desee, se recomienda el uso de bucles, como **for** o **while**.
```c

#include <stdio.h>

int main(){
    int array[5];

    array[0] = 10;
    array[1] = 1;
    array[2] = 7;
    array[3] = 12;
    array[4] = 5;

    for(int i = 0; i < 5; i++){
        printf("El numero almacenado en al posición %d es: %d", i, array[i]);
    }

    return 0;
}
```
Lo anterior nos mostrará todos los números almacenados en el array.

Los bucles también nos sirven para almacenar valores.
```c

#include <stdio.h>

int main(){
    int array[10];

    // Este bucle guarda los números del 1 al 10
    // dentro del array
    for(int i = 0; i < 10; i++){
        array[i] = i;
    }

    return 0;
}
```

## Otras instrucciones con arrays
Al igual que podemos almacenar valores concretos dentro de un array, también podemos almacenar los valores contenidos en otras variables.
```c

#include <stdio.h>

int main(){
    int array[10];
    int numero = 5

    int array[0] = numero;

    return 0;
}
```

También es posible almacenar valores ingresados por usuarios.
```c

#include <stdio.h>

int main(){
    int array[10];

    // Esto guardará el valor ingresado por el usuario
    // en la quinta posición del arreglo
    printf("Ingrese un entero: ");
    scanf("%d", &array[4]);

    return 0;
}
```
Podemos guardar el valor de una casilla de un array dentro de otra variable.
```c

#include <stdio.h>

int main(){
    int array[] = {1,2,3,4,5,6};

    // Esto asigna el valor de
    // la cuarta posición de array
    // Es decir, 4
    int numero = array[3];


    return 0;
}
```

**Advertencia**

Aunque las siguientes líneas se parezcan, cada una funciona de manera muy diferente:
+ <code>int array[5]</code> crea un array de tamaño 5.
+ <code>array[5] = 5</code> asigna el valor **5** a la sexta posición del array.
+ <code>array[5] = numero</code> asigna el valor que se encuentra almacenado en la variable <code>numero</code> a la sexta posición del array.
+ <code>numero = array[5]</code> asigna el valor que se encuentra almacenado en la sexta posición del array a la variable <code>numero</code>.

## Otras consideraciones
+ Los array funcionan como una variable normal, por lo que las podemos combinar con otras instrucciones que hemos visto hasta ahora.
+ Tomando en cuenta lo anterior, también se comportan como variables cuando las usamos en conjunto con funciones.
+ En esencia, los arrays son punteros, lo que permite trabajar con los valores como tal.

## Ejercicios de laboratorio
Usando los temas cubiertos en el laboratorio, cree los programas correspondientes para los siguientes enunciados:
1. Un arreglo de enteros que contenga 20 multiplos de un número ingresado por el usuario y luego mostrarlo en pantalla. Por ejemplo, si el número ingresado es 3, se debe mostrar: 3, 6, 9, 12,..., hasta llegar a 60.
2. Se debe crear un array de tamaño N y llenarlo con números; para comodidad, llene el array con números aleatorios entre 1 y 10. El usuario debe ingresar el tamaño N y un número, del cual se debe contar las repeticiones. Al final se debe mostrar un mensaje indicando cuántas veces se repite el número dentro del array. Por ejemplo, si tenemos el array de tamaño 14: 1,2,2,2,3,5,5,1,5,1,1,2,4,4; y el número a buscar es 2, se debe mostrar un mensaje que indique que el número 2 se repite 4 veces en el arreglo. Recuerde que puede crear números aleatorios inicializando <code>srand(time(NULL))</code> y generando el número con <code>rand() % A + B</code>; donde A es el límite superior y B es el inferior.
3. Se debe crear un array de tamaño N (el ususario debe introducir el tamaño) y llenarlo con números aleatorios. Utilice una **función** que reciba el array; la **función** debe mostrar el array original y el array al revés. Por ejemplo, si tenemos el array: 1,3,6,9,0,9,2,4; se debe mostrar en pantalla 1,3,6,9,0,9,2,4 y 4,2,9,0,9,6,3,1 (que es el mismo array pero al revés). **Es obligatorio el uso de la función**.
4. Se debe crear un array de tamaño N (el usuario debe introducir el tamaño) y llenarlo con números aleatorios. A continuación, el usuario debe poder elegir si quiere cambiar algún número del array o terminar con el programa (puede hacer esto con el uso de un bucle). Si decide cambiar un número, el usuario debe ingresar el nuevo número. El tamaño del array debe ser mayor que 10. Nota: recuerde que para ubicar un elemento dentro de un array se hace por medio de su índice. Por ejemplo, si tenemos el array: 10,12,3,44,5,6,17,8,29,10; y el usuario quiere cambiar el número 12 por el número 100, debe ingresar el índice (1) y el nuevo valor (100), lo que daría el siguiente array: 10,100,3,44,5,6,17,8,29,10. Se debe imprimir el array cada vez que se cambia algún número.
