namespace AdventOfCode.Puzzles._2024._12.Parte2;

public partial class Parte2 : IPuzzleSolution
{
    private int _ancho;
    private int _alto;

    private char[,] _mapa;
    private int[,] _formas;
    Dictionary<int, int> _areasForma = new();
    Dictionary<int, int> _ladosForma = new();
    Dictionary<int, char> _nombresForma = new();

    private int _idForma;

    public async Task<string> ResolverAsync(StreamReader lectorEntrada)
    {
        var lineas = await lectorEntrada.ReadAllLinesAsync();
        _ancho = lineas[0].Length;
        _alto = lineas.Count;

        _mapa = new char[_ancho, _alto];
        _formas = new int[_ancho, _alto];

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
                if (_formas[x, y] == 0)
                {
                    var (area, perimetro) = EncontrarGrupo((x, y));
                    _areasForma[_formas[x, y]] = area;
                }
            }
        }

        ContarLados();

        foreach (var forma in _areasForma.Keys)
        {
            total += _ladosForma[forma] * _areasForma[forma];
        }

        return total.ToString();
    }

    private void ContarLados()
    {
        // Similar al original
    }

    private (int area, int perimetro) EncontrarGrupo(Punto puntoInicial)
    {
        // Similar al original
    }

    private bool EsValido(Punto punto) => punto.X >= 0 && punto.X < _ancho && punto.Y >= 0 && punto.Y < _alto;
}
