using System.Numerics;

namespace AdventOfCode.Puzzles._2024._11.Parte2;

public partial class Parte2 : ISolucionPuzzle
{
    public async Task<string> ResolverAsync(StreamReader lectorEntrada)
    {
        var entrada = await lectorEntrada.ReadToEndAsync();
        var numeros = entrada.Trim().Split(' ', StringSplitOptions.RemoveEmptyEntries);

        Dictionary<string, long> estadoActual = new();
        numeros.GroupBy(x => x).ToList().ForEach(x => estadoActual.Add(x.Key, x.Count()));

        for (int i = 0; i < 75; i++)
        {
            var nuevoEstado = new Dictionary<string, long>();
            foreach (var (numero, cantidad) in estadoActual)
            {
                AplicarReglas(numero, cantidad, nuevoEstado);
            }
            estadoActual = nuevoEstado;
        }

        return estadoActual.Sum(n => n.Value).ToString();
    }

    private void AplicarReglas(string numero, long cantidad, Dictionary<string, long> siguiente)
    {
        void AgregarOActualizar(string clave, long valor)
        {
            if (siguiente.ContainsKey(clave))
            {
                siguiente[clave] += valor;
            }
            else
            {
                siguiente.Add(clave, valor);
            }
        }

        if (numero == "0")
        {
            AgregarOActualizar("1", cantidad);
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

            AgregarOActualizar(izquierda, cantidad);
            AgregarOActualizar(derecha, cantidad);
        }
        else
        {
            var numeroGrande = BigInteger.Parse(numero);
            var multiplicado = numeroGrande * 2024;
            AgregarOActualizar(multiplicado.ToString(), cantidad);
        }
    }
}
