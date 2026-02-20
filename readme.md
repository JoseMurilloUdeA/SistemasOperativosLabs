# Reto 1:
**Curso:** Operating Systems  
**Reto:** Reto 1 – Entrando en confianza con la terminal  

**Integrantes**
- Jose Luis Murillo Fernandez
- Mateo Gaviria Ruiz

## Desarrollo del Taller

## Punto 2:
==Imágenes en la carpeta de adjuntos==

## Punto 3:
Se creó el directorio utilizando mkdir para crear la carpeta lab0 que era hija de otras carpetas por lo que usamos la opción -p ya que esas carpetas padre no existían:

```bash
mkdir -p ~/operating-systems-20261/laboratories/lab0
```

- `mkdir`: crea directorios.    
- `-p`: crea directorios padre si no existen.
- `~`: representa el directorio home del usuario.
## Punto 4: 

```bash
cd ~/operating-systems-20261/laboratories/lab0
```

- `cd`: cambia de directorio.
## Punto 5:
```bash
pwd > path.txt
```

- `pwd`: muestra la ruta absoluta.
- `>`:  le dice a la terminal que debe de guardar es ruta en un archivo.
- `path.txt`: archivo donde se guardó la ruta.

## Punto 6:
```bash
mkdir example music photos projects
```

El comando mkdir permite crear uno o más directorios separados. Se hace separando los nombres por espacios.

## Punto 7:
```bash
for DIRECTORY in example music photos projects; do 
  (cd "$DIRECTORY" && for FILE in file{1..100}; do touch "$FILE"; done)
done
```

Creamos, usando un ciclo que recorría las carpetas dentro de lab0, 100 archivos con nombre file# 
- `for`: ciclo.
- `file{1..100}`: nombra los archivos como file1, file2, ..., file100
- `touch`: crea archivos vacíos.

![[Pasted image 20260219191146.png]]
## Punto 8: 
``` bash
# CODIGO 1
for DIRECTORY in example music photos projects; do (cd "$DIRECTORY" && ls | grep -E '(e[1-9]|10|100|8[1-9]|9[0-9])$' | xargs -r rm -r); done

# CODIGO 2
FILES=$(ls | grep ls | grep -E ´(e[1-9]|8[1-9]|9[1-9]|10|100)$´

for DIRECTORY in $(ls); do (cd “$DIRECTORY” && rm -d $FILES); done
```

En este punto hicimos dos códigos diferentes pero similares.
Usamos un ciclo for de la misma forma que hicimos en el punto 7, este comando filtra usando una expresión regular el final del nombre de los archivos que se deban de borrar, luego usando el comando xargs eso valores para convertir la salida del filtro en un argumento para el comando -rm que es el de remover o eliminar.

El segundo código guarda en una variable una lista de los archivos filtrada por la expresión regular, luego usando un ciclo for recorriendo los archivos de lab0 buscaba dentro de ellos las concidencias y las eliminaba con rm.

Se eliminaron los archivos:
- file1 a file10
- file81 a file100

- `rm`: elimina archivos.
- Se utilizó expansión de llaves para seleccionar rangos específicos.
## Punto 9:
```bash
mv example music photos ./projects
```

- `mv`: mueve archivos o directorios.  
- `./projects`: directorio destino.

## Punto 10:
```bash
find projects -maxdepth 1 -type f -exec rm -v -- {} + > ~/operating-systems-20261/laboratories/lab0/output.txt
```

- `find`: busca archivos.
- `-maxdepth 1`: solo en el nivel actual.
- `-type f`: solo archivos.
- `rm -v`: elimina mostrando detalle (verbose).
- `>`: redirige la salida al archivo `output.txt`.
