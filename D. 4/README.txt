1. ¿Por qué habéis elegido ese problema?
Aunque hemos elegido los problemas en función de si sabíamos hacerlos o no, este nos parecía una buena opción,nos 
parecía desafiante pero divertido, ya que se parecía a las antiguas sopas de letras que todos hacíamos de pequeños.

2. ¿Qué técnica o estructura de datos se emplea?
La técnica utilizada es divide y vencerás, ya que descompone el problema en pequeñas sub-búsquedas independientes 
dentro de la matriz, evaluando cada posición y dirección como una unidad separada. Esto permite manejar la complejidad
al explorar la sopa de letras sistemáticamente.

3. Descripción de cómo se ha abordado la resolución del problema (por partes):
Parte 1: Para encontrar "XMAS", se recorre toda la matriz y se verifican todas las direcciones posibles desde cada 
posición (horizontal, vertical y diagonal, incluyendo reversos). Contamos cuántas veces se forma la palabra completa.
Parte 2: Para encontrar "X-MAS", se verifica si un grupo de 3x3 celdas contiene las diagonales necesarias que formen 
dos palabras "MAS" (forwards o backwards). El recorrido también abarca toda la matriz buscando coincidencias en cada 
posición 