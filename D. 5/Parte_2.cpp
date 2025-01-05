#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <set>
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
        cout << "Leyendo archivo: " << archivo << endl;
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

bool checarOrden(vector<int> actualizacion, vector<Regla> reglas) {
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

vector<int> ordenarActualizacion(vector<int> actualizacion, vector<Regla> reglas) {
    unordered_map<int, set<int>> dependencias;
    unordered_map<int, int> conteoDependencias;

    for (const auto& regla : reglas) {
        dependencias[regla.antes].insert(regla.despues);
        conteoDependencias[regla.despues]++;
        if (conteoDependencias.find(regla.antes) == conteoDependencias.end()) {
            conteoDependencias[regla.antes] = 0;
        }
    }

    queue<int> listaSinDependencias;
    for (int pagina : actualizacion) {
        if (conteoDependencias[pagina] == 0) {
            listaSinDependencias.push(pagina);
        }
    }

    vector<int> ordenCorrecto;
    while (!listaSinDependencias.empty()) {
        int actual = listaSinDependencias.front();
        listaSinDependencias.pop();
        ordenCorrecto.push_back(actual);

        for (int dependiente : dependencias[actual]) {
            if (--conteoDependencias[dependiente] == 0) {
                listaSinDependencias.push(dependiente);
            }
        }
    }

    if (ordenCorrecto.size() != actualizacion.size()) {
        cout << "Advertencia: No se pudieron ordenar todas las paginas correctamente." << endl;
    }

    return ordenCorrecto;
}

int main() {
    string nombreArchivo = "input.txt";
    vector<string> lineas = leerArchivo(nombreArchivo);

    if (lineas.empty()) {
        cout << "El archivo esta vacio o no se pudo leer correctamente." << endl;
        return 1;
    }

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

    cout << "Se leyeron " << reglas.size() << " reglas y " << actualizaciones.size() << " actualizaciones." << endl;

    int sumaMediosCorrectos = 0;
    int sumaMediosCorregidos = 0;

    for (int i = 0; i < actualizaciones.size(); i++) {
        cout << "Procesando actualizacion " << i + 1 << "..." << endl;
        cout << "Contenido de la actualizacion: ";
        for (int pagina : actualizaciones[i]) {
            cout << pagina << " ";
        }
        cout << endl;

        if (checarOrden(actualizaciones[i], reglas)) {
            int medio = actualizaciones[i][actualizaciones[i].size() / 2];
            sumaMediosCorrectos += medio;
            cout << "Actualizacion " << i + 1 << " esta en orden. Medio: " << medio << endl;
        } else {
            vector<int> ordenada = ordenarActualizacion(actualizaciones[i], reglas);
            int medioCorregido = ordenada[ordenada.size() / 2];
            sumaMediosCorregidos += medioCorregido;
            cout << "Actualizacion " << i + 1 << " corregida. Orden: ";
            for (int pagina : ordenada) {
                cout << pagina << " ";
            }
            cout << "\nMedio corregido: " << medioCorregido << endl;
        }
    }

    cout << "La suma de los medios correctamente ordenados es: " << sumaMediosCorrectos << endl;
    cout << "La suma de los medios corregidos es: " << sumaMediosCorregidos << endl;

    return 0;
}
