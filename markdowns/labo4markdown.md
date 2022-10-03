author: Equipo de instructores FDP
summary: Segunda práctica de laboratorio FDP
id: laboratorio-4-fdp-0222
tags: workshop,iguide
categories: C
environments: Visual Studio Code
status: Published
feedback link: A link where users can go to provide feedback (e.g. the git repo or issue page)

# Fundamentos de Programación: Laboratorio 4

## Introducción

![logo-uca](./img/labo1/image001.jpg)

En este laboratorio se introducirán dos conceptos claves de la programación en C: **Funciones** y **punteros**

## Funciones

### ¿Qué es una función?
Las funciones son fragmentos de código que se ejecutan solamente cuando son llamadas (o invocadas) desde alguna instrucción dentro del código. Una de las principales ventajas del uso de funciones es que las podemos reutilizar tantas veces como queramos. Es decir, escribimos las instrucciones una vez y las podemos llamar muchas veces.
El uso de funciones obedece el principio de programación de dividir una tarea complicada en partes más fáciles de manejar.

### Sintaxis
Las funciones en C deben incluir las siguientes partes:
+ El tipo de dato que retorna (int, float, double, bool, etc.).
+ Un nombre que la identifique, de manera similar a una variable (sin espacios de por medio).
+ Un par de paréntesis () y llaves {}.
+ Opcionalmente, en el interior de los paréntesis podemos indicar **parámetros**. Estos son datos que enviamos a la función desde su llamada. Agregarlos o no dependerá de lo que necesite la lógica de la función.
+ La instrucción <code>return</code> (dependiendo de la lógica de la función).

```c
//Partes de una función:
//int es el tipo de dato que retornará
//unaFuncion es el nombre de la función
    //Dentro de los paréntesis:
    //float es el tipo de dato que enviamos como parametro
    //numeroDecimal es el nombre con el que identificaremos
    //al valor del parametro dentro de la función
    //No es necesario enviar datos del mismo tipo de la función,
    //como en este ejemplo
int unaFuncion(float numeroDecimal) {
    //Instrucciones a ejecutar
}
```

Las funciones pueden ser declaradas de dos maneras:<br><br>
**Arriba de la función main**
```c
int unaFuncion(float numeroDecimal){
    //Instrucciones a ejecutar
}

int main(){

    return 0;
}
```

**Abajo de la función main**<br>
En este caso, debemos agregar un prototipo de la función antes del main.
```c
int unaFuncion(float numeroDecimal);

int main(){
    return 0;
}

int unaFuncion(float numeroDecimal){
    //Instrucciones a ejecutar
}
```

## Ejemplos de funciones

**Ejemplo 1: Creando una función de tipo int**
```c
#include <stdio.h>

int sumarDosNumeros(int num1, int num2);

int main(){
    int a = 5, b = 10, resultado;

    //sumarDosNumeros(a, b); Aquí se manda a llamar la variable,
    //pero no lo almacena en ningún lado
    resultado = sumarDosNumeros(a, b);
    printf("El resultado de a y b es %d", resultado);

    //Esta es una forma alternativa
    //Aunque no la guardemos en una variable,
    //el valor se retorna a la impresión en pantalla
    printf("El resultado de a y b es %d", sumarDosNumeros(a, b));

    return 0;
}

//Esta función recibe dos números enteros como parametros
//y retorna un número entero
int sumarDosNumeros(int num1, int num2){
    //Los nombres de los parametros son independientes
    //de los nombres de las variables que mandemos

    int suma = num1 + num2;
    return suma;//Se retorna el valor de la suma

    //return num1 + num2; Esta es una forma alternativa que devuelve el resultado
    //sin tener que guardarlo en una variable
}
```

**Ejemplo 2: Creando una función de tipo void**
```c
#include <stdio.h>

//Esta función no recibe parametros
//y tampoco retorna valores
//Aunque no tenga parametros,se deben agregar los paréntesis
void imprimirHolaMundo(){
    printf("Hola Mundo!");
    //Lo único que hace la función es imprimir el mensaje "Hola Mundo!"
}

int main(){

    //Aunque la función no necesite parametros
    //se necesitan los paréntesis en la llamada de la función
    imprimirHolaMundo();
    //Como no retorna nada, no hay necesidad de guardar en una variable

    return 0;
}
```

**Ejemplo 3: Creando una función void con parametros**
```c
#include <stdio.h>

//La función recibe parametros,
//pero no es necesario que retorne algún valor
void imprimirNumero(int numero){
    printf("El numero es %d", numero);
}

int main(){
    int numero = 2;

    imprimirNumero(numero);

    return 0;
}
```

## Punteros
Los punteros son variables especiales que se utilizan para almacenar direcciones de valores, en vez de valores en sí.
```c
int numero = 5;//Creamos una variable que almacena el valor 5
int *puntero = &numero;
//El puntero almacenara la dirección de dónde se almacena 
//la variable numero, pero también podemos "acceder" al valor que se almacena ahí
```

Supongamos que la variable <code>numero</code> está almacenada en la dirección **6**. Entonces, si imprimieramos la dirección de <code>numero</code> (con &numero), nos mostraría **6** (& se usa para ingresar a la dirección en memoria).

Si imprimimos solamente la variable <code>puntero</code> (sin \*), nos mostraría **6**, porque lo que almacena es la dirección, no el valor. Al usar <code>*puntero</code>, podemos "ver" lo que se almacena en la dirección, que es el número **5**.

*Nota: Se recomienda investigar por cuenta propia, ya que se trata de un tema relativamente sencillo, pero confuso.*

## Punteros en funciones
Cuando usamos funciones y les enviamos variables como parametros, lo que estamos haciendo es crear una copia del valor y usar esa copia. Es posible enviar los mismos datos a través de sus direcciones; esto se llama "enviar por referencia".

A continuación, usaremos los mismos ejemplos de funciones, pero adaptados para usar punteros.

**Ejemplo 1: Una función con datos por referencia**
```c
#include <stdio.h>

int sumarDosNumeros(int *num1, int *num2);

int main(){
    int a = 5, b = 10, resultado;
    int *ptrA, *ptrB;
    ptrA = &a;//Aquí almacenamos la dirección de a en el punteroA
    ptrB = &b;//Hacemos lo mismo con el punteroB

    //Alternativamente, podemos asignar los valores desde su declaración, así:
    //int *ptrA = &a, *ptrB = &b;

    resultado = sumarDosNumeros(ptrA, ptrB);
    printf("El resultado de a y b es %d", resultado);

    //Esta es una forma alternativa
    //Podemos enviar la dirección de las variables sin almacenarlas en punteros
    printf("El resultado de a y b es %d", sumarDosNumeros(&a, &b));

    return 0;
}

//Esta función recibe dos punteros de tipo entero como parametros
//y retorna un número entero
int sumarDosNumeros(int *num1, int *num2){
                                        
    int suma = *num1 + *num2;
    return suma;

    //return *num1 + *num2; Esta es una forma alternativa que devuelve el resultado
    //sin tener que guardarlo en una variable
}
```

**Ejemplo 2: Función void con puntero**
```c
#include <stdio.h>

//La función recibe un puntero,
//pero no es necesario que retorne algún valor
void imprimirNumero(int *numero){
    printf("El numero es %d", numero);
}

int main(){
    int numero = 2;

    imprimirNumero(&numero);

    return 0;
}
```

## Ejercicios de laboratorio

Usando los temas cubiertos en el laboratorio, cree los programas correspondientes para los siguientes enunciados:
1. Una función que reciba un número como parámetro, determine si es par o impar y muestre el resultado en un mensaje. Por ejemplo:
   ```c
    void estaEsUnaFuncionDePrueba(int numeroDecimal){
        //Instrucciones a ejecutar para verificar si el número es par o impar
    }
   ```

2. Una calculadora que realice las operaciones básicas (suma, resta, multiplicación, división) en funciones respectivas. Debe retornar el valor del resultado. Por ejemplo: una función para la suma, otra función para la resta, etc. Si a la función de suma se le mandan los valores 2 y 5, el valor a retornar debe ser 7; si a la función de multiplicación se le envían los valores 4 y 4, el valor a retornar debe ser 16.
3. Similar al ejercicio del laboratorio anterior, calcular la potencia N de un número base, pero desde una función que retorne el valor. En este ejercicio es obligatorio enviar los datos por referencia, es decir, hacer uso de punteros. Por ejemplo: 2^8 es 256. 3^7 es 2187.
4. Una función que reciba un límite inferior y uno superior, luego realizar la iteración de estos límites, sumando el valor de cada número del rango. Se debe retornar el valor final de la suma. Por ejemplo: La suma del rango 2 hasta 6 sería: 2 + 3 + 4 + 5 + 6 = 20.