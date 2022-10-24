author: Equipo de instructores FDP
summary: Segunda práctica de laboratorio FDP
id: laboratorio-6-fdp-0222
tags: workshop,iguide
categories: C
environments: Visual Studio Code
status: Published
feedback link: A link where users can go to provide feedback (e.g. the git repo or issue page)

# Fundamentos de Programación: Laboratorio 6

## Introducción

![logo-uca](./img/labo1/image001.jpg)

En este laboratorio se presentarán dos herramientas ampliamente utilizadas por programadores: **Git** y **GitHub**

## GitHub

![github-logo](./img/labo6/github-logo.png)
### ¿Qué es GitHub?
GitHub es un sitio web y servicio en la nube que ayuda a los desarrolladores a almacenar y administrar su código, al igual que llevar un registro y control de cualquier cambio sobre el mismo. Para entender exactamente qué es GitHub, primero necesitas conocer los dos principios que lo conectan:
+ Control de versiones
+ Git

### ¿Qué es Control de versión?
Un control de versiones ayuda a los desarrolladores a llevar un registro y administrar cualquier cambio en el código del proyecto en el que estén trabajando. A medida que crezca el proyecto, el control de versiones se vuelve esencial.

Tomemos WordPress por ejemplo…


En este punto, WordPress es un gran proyecto. Si un desarrollador importante deseara trabajar en una parte en específico de la base de datos del código de WordPress, no sería seguro o eficiente permitir que pueda editar directamente sobre el código fuente “oficial”.
Por esto, la versión de control permite a los desarrollador trabajar de forma segura a través de una bifurcación (***fork***) y una fusión/unión (***merge***).
Con la bifurcación (_fork_), un desarrollador duplica parte del código fuente (llamado *repositorio*). Este desarrollador luego puede, de forma segura, hacer cambios a esa parte del código, sin afectar al resto del proyecto.
Después, una vez que el desarrollador logre que su parte del código funcione de forma apropiada, esta persona podría fusionar (_merge_) este código modificado al código fuente principal para hacerlo oficial.


Todos estos cambios luego son registrados y pueden ser revertidos si es necesario.

## Git

![git-logo](./img/labo6/git-logo.png)
### ¿Qué es Git?

Git es un sistema de control de versiones de código abierto creado por Linus Torvalds en el 2005.
Específicamente, Git es un sistema de control de versión distribuida, lo que quiere decir que la base del código entero y su historial se encuentran disponibles en la computadora de todo desarrollador, lo cual permite un fácil acceso a las bifurcaciones y fusiones.
Según la encuesta entre los desarrolladores de Stack Overflow, más de 87% de los desarrolladores usan Git.


### Diferencia entre Git y GitHub
GitHub es una compañía sin fines de lucro que ofrece un servicio de hosting de repositorios almacenados en la nube. Básicamente, hace que sea más fácil para individuos y equipos usar Git como control de versiones y para colaboración.
La interfaz de GitHub es bastante fácil de usar para cualquier desarrollador novato que quiera aprovechar las ventajas de Git. Sin GitHub, usar Git generalmente requiere de un poco más de conocimientos de tecnología y uso de líneas de comandos.
GitHub es tan fácil de usar que incluso algunas personas usan GitHub para administrar otro tipo de proyectos (como escribir libros).
Además de esto, cualquier persona puede inscribirse y alojar un repositorio de código público completamente gratuito, el cual hace que GitHub sea especialmente popular con proyectos de open source.

## Parte práctica
### Primeros pasos
+ Lo primero que se debe hacer es crear una cuenta de usuario ingresando al siguiente enlace [https://github.com/](https://github.com/).
+ Si bien es posible subir archivos directamente desde la página de GitHub, en muchas ocasiones se le pedirá que utilice Git directamente. Para poder utilizarlo, hay que descargarlo desde [https://git-scm.com/](https://git-scm.com/).
  + Una vez descargado, hay que configurar las variables globales de git para nombre de usuario:<br>
  ```
  git config --global user.name "tu_usuario"
  ```
  + Y para correo electrónico:<br>
  ```
  git config --global user.email tu@email.com
  ```
  + Tener en cuenta que estos comandos son para un usuario global (por ejemplo, para tu computadora personal). Para equipos compartidos se recomienda solo hacerlos locales. Para eso basta con eliminar **--global** del comando.

## Crear repositorios
Existen diferentes maneras de crear un repositorio:

### Desde GitHub
La primera opción es crearlo directamente desde GitHub, con el botón "New repository". Luego de configurar las opciones del repositorio y haberlo creado, podemos comenzar a subir nuestros archivos.

Esto es un repositorio remoto, pero nosotros debemos trabajar con un repositorio local. Para esto debemos "conectarnos" con el repositorio remoto, clonándolo. Debemos tener una carpeta en nuestra computadora en donde guardaremos el repositorio. Cuando la tengamos lista, debemos entrar a la carpeta desde la consola de git. Afortunadamente, hay una opción que permite abrir la consola de Git directamente en la carpeta; hay que hacer clic derecho en la carpeta y seleccionar ***Git Bash Here***. Un repositorio se clona con el comando:
```
git clone <url del repositorio remoto>
```

### Desde Git
La otra opción es crearlo a través de comandos desde la consola de git. Primero hay que crear una carpeta que nos servirá como repositorio, abrir su ubicación en la consola de Git y seguir estos pasos que nos provee GitHub:
```
git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin <url del repositorio remoto>
git push -u origin main
```

## Comandos básicos de Git

**init**<br>
Este comando es para configurar que una carpeta se usará como repositorio para un proyecto.
```
git init
```

**clone**<br>
Este comando se utiliza para clonar un repositorio existente al repositorio actual.
```
git clone
```

**add**<br>
Este comando se usa para agregar un archivo o carpeta a la etapa de stage. Todo lo que esté en esta etapa se agregará al commit.
```
git add "archivo"
```
Alternativamente, se puede usar esta otra versión para agregar **todos** los documentos del proyecto actual a la etapa de stage.
```
git add .
```

**commit**<br>
Este comando se utiliza para hacer un commit. Un commit es básicamente firmar/registrar los cambios realizados a un repositorio; esto incluye creación, adición, eliminación y modificación de archivos y carpetas. Se debe agregar un mensaje que resuma en qué consisten los cambios hechos. Por ejemplo: "Adición de botones", "Eliminación de función recursiva", "Corrección de error en línea N".
```
git commit -m "Mensaje del commit" 
```

**remote add**<br>
Este comando es para crear un repositorio remoto.
```
git remote add origin <url del repositorio remoto> 
```

**push**<br>
Este comando se utiliza para enviar tus commits a tu repositorio remoto. Aunque se haya hecho un <code>git commit</code>, esos cambios permanecerán en tu repositorio local hasta que se suban al remoto.
```
git push origin master
```
"master" se refiere a la rama principal en la que se trabaja el proyecto. Esto se puede cambiar para trabajar en diferentes ramas.
Después de haber hecho un push inicial, podremos acortar el comando a:
```
git push
```

**pull**<br>
Este comando se utiliza para actualizar tu repositorio local con el remoto. Digamos que estás trabajando con un equipo; tú tienes un repositorio local y subes los cambios a un repositorio remoto. Si alguien de tu equipo modifica el código, es necesario actualizar tu repositorio local para tener la última versión del código y evitar conflictos de versiones. Tener en cuenta que no será posible hacer hacer si tu repositorio local no está actualizado, y forzarlo puede crear problemas con el código.
```
git pull
```

**checkout**<br>
Este comando permite cambiar entre ramas existentes.
```
git checkout <nombre de la rama>
```

**checkout -b**<br>
Similar al comando anterior, con la diferencia de que este crea una rama y cambia inmediatamente a esta.
```
git checkout -b <nombre de la rama> 
```

## Tarea de laboratorio
Leer la sección sobre Strings en C y realizar los ejercicios correspondientes. Cuando se haya terminado, procede a subir los ejercicios a un repositorio remoto.

Recuerda crear tu cuenta de GitHub y descargar Git.

## Strings en C
### ¿Qué es un String?
Un String uesuna cadena de caracteres. En C, estas cadenas se manejan como arrays de caracteres, lo que significa que cada caracter ocupará una posición dentro del array, por lo que cada cadena estará limitada a un número N de caracteres máximo.
Los Strings se manejan enteramente como arrays, incluyendo su declaración:
```c
// Esto declara un string que solo almacenará
// 10 caracteres como máximo
char nombre[10];

// Esto inicializa un string de tamaño 7,
// porque siempre se agregar un valor nulo al final del array
char heroe[] = "Batman";

// Esto inicializa un string de tamaño 10,
// pero que ocupará las primeras 5 posiciones
char villano[10] = "Joker";
```

Lo anterior fue la manera sencilla y rápida de declarar un String, escribiendo todo el contenido entre comillas. También podemos declarar cada letra como un elemento individual. Si queremos trabajarlo de esta manera, hay que tener en cuenta que se debe agregar un valor nulo ('\0') al final de cada array.

**Nota:** Siempre dejar una posición extra dentro de array para almacenar este valor nulo.

```c
// Esto es el equivalente a
// char heroe[] = "Batman";
char heroe[] = {'B','a','t','m','a','n','\0'}
```

Puesto que los Strings son arrays, no podemos simplemente asignarles un nuevo valor; se puede a través de sus posiciones individuales, pero es más tardado. Para poder asignar nuevos valores a un String, podemos hacer uso de ciertas funciones para almacenar nuevos valores:

La primera opción es usando <code>scanf("%s", array)</code>. Aunque es fácil de usar, la desventaja es que solamente almacenará el valor hasta que encuentre un espacio en blanco, un salto de línea, una tabulación o cualquier delimitación de texto.
```c
#include <stdio.h>
int main()
{
    char nombre[20];
    printf("Ingresa tu nombre: ");
    scanf("%s", nombre);
    printf("Tu nombre es %s.", name);
    return 0;
}
```
Los Strings no necesitan el & para agregar el valor a la variable.

Además de <code>scanf()</code>, contamos con <code>fgets()</code> para leer y almacenar toda una línea de texto (siempre y cuando sea menor que el tamaño del aarray), y con <code>puts()</code> para imprimirlo.
```c
#include <stdio.h>
int main()
{
    char nombre[20];
    printf("Ingresa tu nombre: ");
    fgets(name, sizeof(name), stdin);
    puts(name);
    return 0;
}
```

**Nota:** Dado que se tratan de variables, es posible pasar Strings como parámetros a funciones.

## Ejercicios de laboratorio
Usando la información sobre Strings en C, cree los programas correspondientes para los siguientes enunciados:
1. El usuario puede ingresar un texto y una combinación de letras a buscar dentro del texto. Debe mostrar en pantalla un mensaje en caso de que la combinación de letras esté presente dentro del texto y un mensaje en caso de que no esté presente. Por ejemplo: Para el texto "Lunes es el primer día de la semana" y la combinación de letras "primer", se debería mostrar un texto indicando que sí se encontró. Para este ejercicio se puede apoyar de la función <code>strstr()</code>, que evalúa substrings.
2. El usuario puede ingresar una palabra y se debe evaluar si dicha palabra es un palíndromo. Los palíndromos son palabras o frases cuya primera letra es la misma que la última, la segunda es la misma que la penúltima, la tercera es la misma que la antepenúltima, y así sucesivamente. Por ejemplo: "Somos", "Reconocer", "Oso" son palíndromos. (Pista: debe evaluar letra por letra).