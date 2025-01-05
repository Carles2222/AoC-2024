Día 10




Parte 1: Este programa procesa un mapa topográfico representado como una matriz de números, donde cada valor indica una altura. Busca todas las posiciones con valor 0 (trailheads o puntos de partida) y calcula un puntaje basado en cuántos caminos de senderismo válidos llegan a posiciones con valor 9. Un camino válido sube gradualmente, sumando exactamente 1 en cada paso y moviéndose en direcciones cardinales (sin diagonales).
Parte 2: Extiende la lógica de la primera parte para calcular la "calificación" de un trailhead, que corresponde al número total de caminos únicos que comienzan desde ese punto. Los caminos se cuentan como distintos incluso si llegan al mismo destino 9, siempre que sigan rutas diferentes.
