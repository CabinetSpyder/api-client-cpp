#include "../include/leer_utils.hpp"

int leerEnteroDesdeEntrada() {
    std::string linea;
    int numero;

    std::getline(std::cin, linea);
    std::stringstream ss(linea);
    if ((ss >> numero) && ss.eof()) {
        return numero;
    }
    
    
}