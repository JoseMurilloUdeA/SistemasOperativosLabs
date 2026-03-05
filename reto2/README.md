# Sistema de Registro de Tickets en C

## Estructura del Proyecto

El proyecto está organizado en módulos:

- src/: código fuente
- type/: archivos header
- assets/: almacenamiento de tickets
- Makefile: compilación automática

## Compilación

## Ejecución
```
make run
```

## Limpieza
```
make clean
```

## Explicación Técnica
### Uso de punteros

El Ticket se crea dinámicamente con malloc y se manipula mediante punteros.
Las funciones reciben estructuras por referencia.

### Manejo de memoria

Se reserva memoria para:
- Estructura Ticket
- Cadenas dinámicas

Se libera con free para evitar memory leaks.

### Generación del radicado

Se usa:
- time(NULL)
- rand()

Combinados para generar un número único.

### Manejo de errores

Se valida:
- malloc != NULL
- fopen != NULL
- entradas vacías
- ID numérico
- correo con '@'

### Makefile

Incluye:
- all
- clean
- run

Compila con:
gcc -Wall -Wextra -std=c11