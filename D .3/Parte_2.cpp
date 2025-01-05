#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int main() {
    std::ifstream inputFile("entrada.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return 1;
    }

    std::string line;
    std::regex mulRegex(R"(\bmul\((\d+),(\d+)\))"); 
    std::regex doRegex(R"(\bdo\(\))");             
    std::regex dontRegex(R"(\bdon't\(\))");         
    std::smatch match;
    long long sum = 0;
    bool isEnabled = true; 

    while (std::getline(inputFile, line)) {
        auto start = line.cbegin();
        auto end = line.cend();

        while (start != end) {
            if (std::regex_search(start, end, match, mulRegex)) {
                if (isEnabled) {
                    int x = std::stoi(match[1]);
                    int y = std::stoi(match[2]);
                    sum += x * y;
                }
                start = match.suffix().first;
            } else if (std::regex_search(start, end, match, doRegex)) {
                isEnabled = true;
                start = match.suffix().first;
            } else if (std::regex_search(start, end, match, dontRegex)) {
                isEnabled = false;
                start = match.suffix().first;
            } else {
                break; 
            }
        }
    }

    inputFile.close();

    std::cout << "La suma total de las multiplicaciones válidas habilitadas es: " << sum << std::endl;

    return 0;
}
