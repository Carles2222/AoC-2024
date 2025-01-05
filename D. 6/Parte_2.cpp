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

bool guardiaEnCiclo(const vector<string>& mapa, Posicion inicio, int filas, int columnas) {
    // Direcciones: arriba, derecha, abajo, izquierda
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    int direccion = 0; // Comienza mirando hacia arriba

    set<Posicion> posicionesVisitadas;
    Posicion guardia = inicio;

    while (true) {
        int nx = guardia.x + dx[direccion];
        int ny = guardia.y + dy[direccion];

        if (nx < 0 || nx >= filas || ny < 0 || ny >= columnas) {
            // El guardia sale del mapa
            return false;
        }

        if (mapa[nx][ny] == '#') {
            // Obstáculo, gira a la derecha
            direccion = (direccion + 1) % 4;
        } else {
            // Avanza
            guardia = {nx, ny};
            if (posicionesVisitadas.count(guardia)) {
                // Si ya visitó esta posición, está en un ciclo
                return true;
            }
            posicionesVisitadas.insert(guardia);
        }
    }
}

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

    Posicion inicio;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (mapa[i][j] == '^') {
                inicio = {i, j};
                mapa[i][j] = '.'; // Elimina el guardia del mapa
            }
        }
    }

    int posiblesPosiciones = 0;

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (mapa[i][j] == '.' && (i != inicio.x || j != inicio.y)) {
                // Simula la obstrucción
                vector<string> mapaConObstruccion = mapa;
                mapaConObstruccion[i][j] = '#';

                if (guardiaEnCiclo(mapaConObstruccion, inicio, filas, columnas)) {
                    posiblesPosiciones++;
                }
            }
        }
    }

    cout << "Cantidad de posiciones posibles para obstrucción: " << posiblesPosiciones << endl;
    return 0;
}
