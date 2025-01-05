
1. Por qué se eligió el problema
Se eligió este problema porque involucra la validación de datos y manipulación de colecciones de números, lo que 
permite practicar la gestión de estructuras como vectores y el procesamiento de archivos, habilidades esenciales para
el desarrollo en C++.

2. Técnica o estructura de datos utilizada
En este problema se utiliza principalmente la programación dinámica para comprobar la seguridad de un informe y el 
uso de vectores para almacenar los niveles de cada informe. Además, en la segunda parte, se aplica un enfoque de 
prueba y error al intentar eliminar niveles para lograr un informe seguro.

3.Descripción de cómo se ha abordado la resolución
Parte 1: Se lee un archivo con los informes y se comprueba si cada uno cumple con las condiciones de seguridad 
mediante la función esSegura(), que revisa las diferencias entre niveles.
Parte 2: Además de comprobar la seguridad del informe, si no es seguro, se intenta hacer seguro eliminando un nivel 
del informe, usando la función esSeguraConDampener().