Día 12.


Ambos códigos resuelven el problema dividiendo el mapa en regiones de parcelas del mismo tipo de planta, determinando sus áreas y calculando el costo del cercado según los criterios de cada parte. El código de la primera parte explora el mapa con una búsqueda en amplitud para identificar regiones conectadas, calcula el área contando las parcelas en cada región y el perímetro como las aristas externas. Luego, multiplica el área por el perímetro para calcular el costo total. En la segunda parte, se modifica el enfoque para incluir el número de lados del cercado en lugar del perímetro, contando las secciones rectas del cercado al recorrer el mapa en filas y columnas. Esto requiere asignar identificadores únicos a cada región, rastrear las áreas y los lados, y finalmente multiplicar estas propiedades para obtener el costo total actualizado. Ambos códigos usan estructuras eficientes como conjuntos, colas y diccionarios para realizar el cálculo en mapas de distintas dimensiones.


