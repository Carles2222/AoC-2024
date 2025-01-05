#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

struct Posicion {
    int x, y;
    bool operator<(const Posicion& otra) const {
        if (x != otra.x) return x < otra.x;
        return y < otra.y;
    }
};

int main() {
    ifstream archivo("mapa.txt");
    if (!archivo) {
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }

    vector<string> mapa;
    string linea;
    while (getline(archivo, linea)) {
        mapa.push_back(linea);
    }
    archivo.close();

    int filas = mapa.size();
    int columnas = mapa[0].size();

    // Direcciones: arriba, derecha, abajo, izquierda
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    int direccion = 0; // Comienza mirando hacia arriba

    Posicion guardia;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (mapa[i][j] == '^') {
                guardia = {i, j};
                mapa[i][j] = '.'; // Elimina el guardia del mapa
            }
        }
    }

    set<Posicion> visitadas;
    visitadas.insert(guardia);

    while (true) {
        int nx = guardia.x + dx[direccion];
        int ny = guardia.y + dy[direccion];

        if (nx < 0 || nx >= filas || ny < 0 || ny >= columnas) {
            // El guardia sale del mapa
            break;
        }

        if (mapa[nx][ny] == '#') {
            // Obstáculo, gira a la derecha
            direccion = (direccion + 1) % 4;
        } else {
            // Avanza
            guardia.x = nx;
            guardia.y = ny;
            visitadas.insert(guardia);
        }
    }

    cout << "Cantidad de posiciones visitadas: " << visitadas.size() << endl;
    return 0;
}
