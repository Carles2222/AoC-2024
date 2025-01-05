#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool verificarXMAS(const vector<string> &matriz, int fila, int columna) {
    int filas = matriz.size();
    int columnas = matriz[0].size();

    vector<pair<int, int>> arribaIzquierda = {{0, 0}, {1, 1}, {2, 2}};
    vector<pair<int, int>> abajoDerecha = {{0, 2}, {1, 1}, {2, 0}};

    for (auto &mas : {arribaIzquierda, abajoDerecha}) {
        string palabra = "";
        for (auto &coord : mas) {
            int nuevaFila = fila + coord.first;
            int nuevaColumna = columna + coord.second;
            if (nuevaFila < 0 || nuevaFila >= filas || nuevaColumna < 0 || nuevaColumna >= columnas) {
                return false;
            }
            palabra += matriz[nuevaFila][nuevaColumna];
        }
        if (palabra != "MAS" && palabra != "SAM") {
            return false;
        }
    }

    return true;
}

int contarXMAS(const vector<string> &matriz) {
    int contador = 0;

    for (int fila = 0; fila < matriz.size() - 2; ++fila) {
        for (int columna = 0; columna < matriz[0].size() - 2; ++columna) {
            if (verificarXMAS(matriz, fila, columna)) {
                ++contador;
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
    cout << "Total de apariciones de X-MAS: " << resultado << endl;

    return 0;
}
