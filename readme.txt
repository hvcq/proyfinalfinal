---------------------------------------
Instrucciones para el uso del programa
---------------------------------------

SETUP
    - El paso previo a ejecutar el programa, es compilarlo, para ello
      dentro de la carpeta contenedora de los archivos "proyecto 2",
      ejecute el siguiente comando:

      g++ *.cpp -o main

USO
    - Una vez realizada la fase de SETUP, el uso del programa es de
      la siguiente manera:

    (1) Para ejecutar en linux escriba en la consola:

        ./main

    (2) Se le pedira que ingrese las dimensiones de la grilla (n,m).
        Ejemplo de entradas validas son:
        - 0 0
        - 0 1
        - 5 5
        - 100 100
        - 100
          100
    
    (3) Luego se le desplegará un menú con las funciones del programa.
        Para seleccionar una opcion ingrese el número asociado a una funcion.

        Ejemplo de entradas validas son:

        - 0
        (esta acción cierra el programa)

        - 1
        (esta acción dibuja una grilla con pesos por lo que se le pedira un rango
        los valores de a y b para definir el rango [a,b] en que se asignaran los
        pesos aleatoriamente)

    (4) Para salir ingrese "0" en el menu
        
