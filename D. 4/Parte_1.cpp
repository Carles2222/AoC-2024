#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool verificarDireccion(const vector<string> &matriz, int fila, int columna, int dFila, int dColumna) {
    string objetivo = "XMAS";
    for (int i = 0; i < 4; ++i) {
        int nuevaFila = fila + i * dFila;
        int nuevaColumna = columna + i * dColumna;
        if (nuevaFila < 0 || nuevaFila >= matriz.size() || nuevaColumna < 0 || nuevaColumna >= matriz[0].size() ||
            matriz[nuevaFila][nuevaColumna] != objetivo[i]) {
            return false;
        }
    }
    return true;
}

int contarXMAS(const vector<string> &matriz) {
    int contador = 0;
    int direcciones[8][2] = {
        {0, 1},  {1, 0},   {1, 1},   {1, -1}, 
        {0, -1}, {-1, 0},  {-1, -1}, {-1, 1} 
    };

    for (int fila = 0; fila < matriz.size(); ++fila) {
        for (int columna = 0; columna < matriz[0].size(); ++columna) {
            for (auto &dir : direcciones) {
                if (verificarDireccion(matriz, fila, columna, dir[0], dir[1])) {
                    ++contador;
                }
            }
        }
    }
    return contador;
}

int main() {
    ifstream archivoEntrada("entrada.txt");
    if (!archivoEntrada) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    vector<string> matriz;
    string linea;

    while (getline(archivoEntrada, linea)) {
        matriz.push_back(linea);
    }

    archivoEntrada.close();

    int resultado = contarXMAS(matriz);
    cout << "Total de apariciones de XMAS: " << resultado << endl;

    return 0;
}
