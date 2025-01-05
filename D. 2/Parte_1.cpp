#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

bool esSegura(const vector<int>& informe) {
    if (informe.size() < 2) {
        return true; 
    }

    int diferenciaInicial = informe[1] - informe[0];

    if (diferenciaInicial == 0 || abs(diferenciaInicial) > 3) {
        return false;
    }

    int direccionEsperada = diferenciaInicial > 0 ? 1 : -1;

    for (size_t i = 0; i < informe.size() - 1; ++i) {
        int diferencia = informe[i + 1] - informe[i];

        if (diferencia == 0 || abs(diferencia) > 3) {
            return false;
        }

        int direccionActual = diferencia > 0 ? 1 : -1;
        if (direccionActual != direccionEsperada) {
            return false;
        }
    }

    return true;
}

int main() {
    int cantidadSeguras = 0;
    string linea;

    ifstream archivoEntrada("datos.txt");
    if (!archivoEntrada) {
        cerr << "Error: No se pudo abrir el archivo 'datos.txt'" << endl;
        return 1;
    }

    while (getline(archivoEntrada, linea)) {
        stringstream ss(linea);
        vector<int> informe;
        int nivel;

        while (ss >> nivel) {
            informe.push_back(nivel);
        }

        if (esSegura(informe)) {
            cantidadSeguras++;
        }
    }

    archivoEntrada.close();

    cout << cantidadSeguras << endl;

    return 0;
}
