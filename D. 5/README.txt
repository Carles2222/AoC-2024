1. ¿Por qué se eligió este problema?
Este problema fue seleccionado porque trabaja con la validación y reordenamiento de secuencias basadas en reglas 
específicas. Es interesante ya que combina lógica condicional y estructuras de control, siendo adecuado para aprender
a aplicar ordenaciones con restricciones.

2. ¿Qué técnica o estructura de datos se emplea?
Se utiliza grafos, ya que las reglas se modelan como dependencias entre nodos, donde las páginas representan nodos y 
las reglas representan aristas dirigidas. Además, se usa una técnica de ordenación topológica para validar y reordenar
las páginas.

3. ¿Cómo se ha abordado la resolución?
Primera parte: Se verificó si las páginas en cada actualización cumplen con las reglas dadas. Esto se logró verificando, 
para cada regla, si las páginas aparecen en el orden correcto en la secuencia.

Segunda parte: Las actualizaciones incorrectas se reordenaron utilizando un algoritmo de ordenación topológica sobre 
las reglas aplicables a las páginas incluidas. Luego, se calculó la suma de los valores centrales de estas secuencias.