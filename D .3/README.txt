1. ¿Por qué habéis elegido ese problema?
Elegimos este problema porque combina la interpretación de datos corruptos con el análisis de patrones, lo que resulta
interesante y desafiante, además de permitir aplicar técnicas básicas de programación que ya conocemos.

2. ¿Qué técnica o estructura de datos se emplea?
Se utiliza divide y vencerás, ya que el programa analiza línea por línea y, dentro de cada línea, busca 
instrucciones específicas para procesarlas de manera separada.

3. ¿Cómo se ha abordado la resolución del problema?
Parte 1:
Primero, buscamos las instrucciones mul(X,Y) dentro del archivo usando un patrón, realizamos las multiplicaciones y 
sumamos los resultados.

Parte 2:
Se agregaron las instrucciones do() y don't(). Un indicador activa o desactiva las multiplicaciones según el último 
comando encontrado. El programa repite este proceso línea por línea y solo suma los resultados habilitados.