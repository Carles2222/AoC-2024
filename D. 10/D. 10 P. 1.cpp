using System.Text;
using System.Transactions;
using AdventOfCode.Puzzles.Tools;

namespace AdventOfCode.Puzzles._2024._10.Parte1;

public partial class Parte1 : ISolucionPuzzle
{
    private int _ancho;
    private int _alto;
    private int[,] _mapa;

    public async Task<string> ResolverAsync(StreamReader lectorEntrada)
    {
        var lineas = await lectorEntrada.ReadAllLinesAsync();
        _ancho = lineas[0].Length;
        _alto = lineas.Count;

        List<Point> ceros = new List<Point>();

        _mapa = new int[_ancho, _alto];
        for (int y = 0; y < _alto; y++)
        {
            for (int x = 0; x < _ancho; x++)
            {
                _mapa[x, y] = lineas[y][x] - '0';

                if (_mapa[x, y] == 0)
                {
                    ceros.Add(new Point(x, y));
                }
            }
        }

        var total = 0;
        foreach (var cero in ceros)
        {
            total += ObtenerPuntaje(cero);
        }

        return total.ToString();
    }

    private int ObtenerPuntaje(Point inicio)
    {
        var puntaje = 0;
        HashSet<Point> visitados = new HashSet<Point>();
        Queue<Point> cola = new Queue<Point>();
        visitados.Add(inicio);
        cola.Enqueue(inicio);
        while (cola.Count > 0)
        {
            var actual = cola.Dequeue();
            var valor = _mapa[actual.X, actual.Y];
            if (valor == 9)
            {
                puntaje++;
                continue;
            }

            foreach (var direccion en Direcciones.SinDiagonales)
            {
                var siguiente = actual + direccion;
                if ((siguiente.X >= 0 && siguiente.X < _ancho && siguiente.Y >= 0 && siguiente.Y < _alto) &&
                    !visitados.Contains(siguiente) &&
                    _mapa[siguiente.X, siguiente.Y] == (valor + 1))
                {
                    visitados.Add(siguiente);
                    cola.Enqueue(siguiente);
                }
            }
        }

        return puntaje;
    }
}
