1. ¿Por qué se eligió este problema?
Este problema fue escogido porque es interesante predecir el movimiento de un personaje (el guardia) en un entorno y 
manipularlo para cumplir un objetivo.

2. ¿Qué técnica o estructura de datos se emplea?
Se utilizan tablas hash mediante std::set, que permite rastrear las posiciones visitadas de manera eficiente. Esto 
ayuda a determinar si el guardia está atrapado en un ciclo al detectar repeticiones.

3. ¿Cómo se abordó la resolución?
Primera parte: Se analizó el mapa, identificando la posición inicial del guardia y definiendo cómo se mueve según 
reglas fijas.

Segunda parte: Aunque no hayamos conseguido que funcione la idea era que para cada posible posición vacía, se simule 
qué pasaría al colocar una obstrucción, verificando si el guardia quedaba atrapado en un ciclo mediante el seguimiento
de las posiciones visitadas.