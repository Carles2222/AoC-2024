namespace AdventOfCode.Puzzles._2024._12.Parte1;

public partial class Parte1 : IPuzzleSolution
{
    private int _ancho;
    private int _alto;

    private char[,] _mapa;
    private HashSet<Punto> _visitados = new();

    public async Task<string> ResolverAsync(StreamReader lectorEntrada)
    {
        var lineas = await lectorEntrada.ReadAllLinesAsync();
        _ancho = lineas[0].Length;
        _alto = lineas.Count;

        _mapa = new char[_ancho, _alto];
        for (int x = 0; x < _ancho; x++)
        {
            for (int y = 0; y < _alto; y++)
            {
                _mapa[x, y] = lineas[y][x];
            }
        }

        int total = 0;
        for (int x = 0; x < _ancho; x++)
        {
            for (int y = 0; y < _alto; y++)
            {
                if (!_visitados.Contains(new Punto(x, y)))
                {
                    var (area, perimetro) = EncontrarGrupo((x, y));
                    total += area * perimetro;
                }
            }
        }

        return total.ToString();
    }

    private (int area, int perimetro) EncontrarGrupo(Punto puntoInicial)
    {
        var perimetroTotal = 0;
        HashSet<Punto> puntosForma = new();

        Queue<Punto> cola = new();
        _visitados.Add(puntoInicial);
        cola.Enqueue(puntoInicial);

        while (cola.Count > 0)
        {
            var punto = cola.Dequeue();
            puntosForma.Add(punto);
            int perimetroPunto = 0;

            foreach (var direccion en Direcciones.SinDiagonales)
            {
                var vecino = punto + direccion;
                if (EsValido(vecino))
                {
                    var tipo = _mapa[vecino.X, vecino.Y];
                    if (tipo == _mapa[punto.X, punto.Y])
                    {
                        if (!_visitados.Contains(vecino))
                        {
                            _visitados.Add(vecino);
                            cola.Enqueue(vecino);
                        }
                    }
                    else
                    {
                        perimetroPunto++;
                    }
                }
                else
                {
                    perimetroPunto++;
                }
            }

            perimetroTotal += perimetroPunto;
        }

        return (puntosForma.Count, perimetroTotal);
    }

    private bool EsValido(Punto punto) => punto.X >= 0 && punto.X < _ancho && punto.Y >= 0 && punto.Y < _alto;
}
