using System.Numerics;

namespace AdventOfCode.Puzzles._2024._11.Parte1;

public partial class Parte1 : ISolucionPuzzle
{
    public async Task<string> ResolverAsync(StreamReader lectorEntrada)
    {
        var entrada = await lectorEntrada.ReadToEndAsync();
        var numeros = entrada.Trim().Split(' ', StringSplitOptions.RemoveEmptyEntries);
        var estadoActual = numeros.ToList();

        for (int i = 0; i < 25; i++)
        {
            var nuevoEstado = new List<string>();
            foreach (var numero in estadoActual)
            {
                AplicarReglas(numero, nuevoEstado);
            }
            estadoActual = nuevoEstado;
        }

        return estadoActual.Count.ToString();
    }

    private void AplicarReglas(string numero, List<string> siguiente)
    {
        if (numero == "0")
        {
            siguiente.Add("1");
        }
        else if (numero.Length % 2 == 0)
        {
            var mitad = numero.Length / 2;
            var izquierda = numero.Substring(0, mitad);
            var derecha = numero.Substring(mitad).TrimStart('0');

            if (derecha == "")
            {
                derecha = "0";
            }

            siguiente.Add(izquierda);
            siguiente.Add(derecha);
        }
        else
        {
            var numeroGrande = BigInteger.Parse(numero);
            var multiplicado = numeroGrande * 2024;
            siguiente.Add(multiplicado.ToString());
        }
    }
}
