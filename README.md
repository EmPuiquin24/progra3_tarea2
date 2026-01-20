# CoreNumeric

Autor: *Hector Emilio Huaman Puiquin*

## Instrucciones de ejecución

1. Tener instalado C++ 20 y CMake.

2. Clonar el repositorio y navegar a la carpeta raíz del proyecto.

3. Compilar el programa:
- En caso sea la primera vez compilando el proyecto: 
``` 
mkdir build && cd build
cmake ..
cmake --build . 
```
- En caso quieras recompilar los tests, solo basta con:
``` 
cd build // En caso no estés ya en la ruta
cmake ..
cmake --build
``` 

4. Correr los tests con:
``` 
./Tests
```


