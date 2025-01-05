#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Regla {
    int antes;
    int despues;
};

vector<string> leerArchivo(string archivo) {
    ifstream archivoEntrada(archivo);
    vector<string> lineas;
    string linea;

    if (archivoEntrada.is_open()) {
        while (getline(archivoEntrada, linea)) {
            if (linea != "") {
                lineas.push_back(linea);
            }
        }
        archivoEntrada.close();
    } else {
        cout << "No se pudo abrir el archivo!" << endl;
    }

    return lineas;
}

bool Orden(vector<int> actualizacion, vector<Regla> reglas) {
    for (int i = 0; i < reglas.size(); i++) {
        int posAntes = -1, posDespues = -1;

        for (int j = 0; j < actualizacion.size(); j++) {
            if (actualizacion[j] == reglas[i].antes) {
                posAntes = j;
            }
            if (actualizacion[j] == reglas[i].despues) {
                posDespues = j;
            }
        }

        if (posAntes != -1 && posDespues != -1 && posAntes > posDespues) {
            return false;
        }
    }
    return true;
}

int main() {
    string nombreArchivo = "input.txt";
    vector<string> lineas = leerArchivo(nombreArchivo);

    vector<Regla> reglas;
    vector<vector<int>> actualizaciones;

    for (int i = 0; i < lineas.size(); i++) {
        if (lineas[i].find('|') != string::npos) {
            int pos = lineas[i].find('|');
            int antes = stoi(lineas[i].substr(0, pos));
            int despues = stoi(lineas[i].substr(pos + 1));
            reglas.push_back({antes, despues});
        } else {
            vector<int> actualizacion;
            stringstream ss(lineas[i]);
            string numero;
            while (getline(ss, numero, ',')) {
                actualizacion.push_back(stoi(numero));
            }
            actualizaciones.push_back(actualizacion);
        }
    }

    int sumaMedios = 0;

    for (int i = 0; i < actualizaciones.size(); i++) {
        if (Orden(actualizaciones[i], reglas)) {
            int medio = actualizaciones[i][actualizaciones[i].size() / 2];
            sumaMedios += medio;
        }
    }

    cout << "La suma de los medios es: " << sumaMedios << endl;

    return 0;
}
