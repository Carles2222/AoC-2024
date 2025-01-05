namespace AdventOfCode.Puzzles._2024._19.Parte2;

public partial class Parte2 : ISolucionPuzzle
{
    private HashSet<string> _patrones;

    public async Task<string> ResolverAsync(StreamReader lectorEntrada)
    {
        _patrones = new HashSet<string>((await lectorEntrada.ReadLineAsync()).Split(", "));
        await lectorEntrada.ReadLineAsync(); // Saltar línea en blanco
        ulong conteoTotal = 0;

        while (await lectorEntrada.ReadLineAsync() is { } toalla)
        {
            conteoTotal += ContarPosibles(toalla);
        }

        return conteoTotal.ToString();
    }

    private ulong ContarPosibles(string toalla)
    {
        ulong[] maneras = new ulong[toalla.Length + 1];
        maneras[0] = 1;

        for (var longitud = 1; longitud <= toalla.Length; longitud++)
        {
            for (int longitudAnterior = 0; longitudAnterior < longitud; longitudAnterior++)
            {
                if (maneras[longitudAnterior] == 0)
                {
                    continue;
                }

                var actual = toalla.Substring(longitudAnterior, longitud - longitudAnterior);
                if (_patrones.Contains(actual))
                {
                    maneras[longitud] += maneras[longitudAnterior];
                }
            }
        }

        return maneras[toalla.Length];
    }
}
