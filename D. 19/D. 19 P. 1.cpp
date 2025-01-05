namespace AdventOfCode.Puzzles._2024._19.Parte1;

public partial class Parte1 : ISolucionPuzzle
{
    private string[] _patrones;

    public async Task<string> ResolverAsync(StreamReader lectorEntrada)
    {
        _patrones = (await lectorEntrada.ReadLineAsync()).Split(", ");
        await lectorEntrada.ReadLineAsync(); // Saltar línea en blanco
        int conteoPosible = 0;

        while (await lectorEntrada.ReadLineAsync() is { } toalla)
        {
            if (EsPosible("", toalla))
            {
                conteoPosible++;
            }
        }

        return conteoPosible.ToString();
    }

    private bool EsPosible(string actual, string toalla)
    {
        if (actual == toalla)
        {
            return true;
        }

        for (int i = 0; i < _patrones.Length; i++)
        {
            var nuevoInicio = actual + _patrones[i];
            if (toalla.StartsWith(nuevoInicio) && EsPosible(nuevoInicio, toalla))
            {
                return true;
            }
        }

        return false;
    }
}
