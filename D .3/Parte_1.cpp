#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int main() {
    std::ifstream archivoEntrada("entrada.txt");
    if (!archivoEntrada.is_open()) {
        std::cerr << "No se pudo abrir el archivo de entrada." << std::endl;
        return 1;
    }

    std::string linea;
    std::string contenido;
    while (std::getline(archivoEntrada, linea)) {
        contenido += linea;
    }
    archivoEntrada.close();

    std::regex patron("mul\\((\\d{1,3}),(\\d{1,3})\\)");
    std::smatch coincidencias;
    int total = 0;

    auto inicio = contenido.cbegin();
    while (std::regex_search(inicio, contenido.cend(), coincidencias, patron)) {
        int x = std::stoi(coincidencias[1]);
        int y = std::stoi(coincidencias[2]);
        total += x * y;

        inicio = coincidencias.suffix().first;
    }

    std::cout << "Resultado total de las multiplicaciones: " << total << std::endl;
    return 0;
}
