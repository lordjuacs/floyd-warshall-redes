# Algoritmo Floyd Warshall
Implementación del algoritmo de enrutamiento Floyd-Warshall para el curso de Redes y Comunicaciones (2021-2) en UTEC.

Se evidencia la matriz de distancias y de recorrido para cada iteración, al igual que el camino de enrutamiento desde cada nodo hacia todos los demás, mostrando el costo total del camino.

Basado en el Proyecto de Grafos realizado en 2020: https://github.com/lordjuacs/graph-implementation

## Ejecución

Dentro del archivo `main.cpp`, descomentar las funciones correspondientes para obtener distintos resultados:


```c++ 
Tester::executeExamples();
```
Muestra un menú interactivo para crear un grafo propio.

![](https://i.imgur.com/JIcVNjd.png)

 ```c++ 
Tester::runExampleUnDirected();
```

Ejecuta el Floyd-Warshall en el siguiente grafo dirigido.

![](https://i.imgur.com/M2bzV3L.png)




```c++
Tester::runExampleDirected();
```

Ejecuta el Floyd-Warshall en el siguiente grafo no dirigido.

![](https://i.imgur.com/Btnp38C.png)



