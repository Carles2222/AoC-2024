using AdventOfCode.Puzzles.Tools;

namespace AdventOfCode.Puzzles._2024._07.Parte1;

public partial class Parte1 : ISolucionPuzzle
{
    public async Task<string> ResolverAsync(StreamReader lectorEntrada)
    {
        ulong total = 0;

        while (await lectorEntrada.ReadLineAsync() is { } linea)
        {
            var partes = linea.Split(":");
            var esperado = ulong.Parse(partes[0].Trim());
            var ecuacion = partes[1].Split(' ', StringSplitOptions.RemoveEmptyEntries);
            var numeros = ecuacion.Select(ulong.Parse).ToArray();
            if (SePuedeResolver(esperado, numeros))
            {
                total += esperado;
            }
        }

        return total.ToString();
    }

    private bool SePuedeResolver(ulong esperado, ulong[] numeros)
    {
        return Resolver(numeros[0], 0, esperado, numeros);
    }

    private bool Resolver(ulong resultadoActual, int indiceActual, ulong esperado, ulong[] numeros)
    {
        if (resultadoActual > esperado)
        {
            return false;
        }

        if (indiceActual == numeros.Length - 1)
        {
            return resultadoActual == esperado;
        }

        if (Resolver(resultadoActual + numeros[indiceActual + 1], indiceActual + 1, esperado, numeros))
        {
            return true;
        }

        if (Resolver(resultadoActual * numeros[indiceActual + 1], indiceActual + 1, esperado, numeros))
        {
            return true;
        }

        return false;
    }
}
