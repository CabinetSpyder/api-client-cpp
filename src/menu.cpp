#include "../include/menu.hpp"

void imprimirMenuPrincipal(){
    std::cout << "Por favor elija una de las siguientes opciones:" << std::endl;
    std::cout << "[1] Introducir ciudad a consultar(ingles)" << std::endl;
    std::cout << "[2] Abrir menu del historial" << std::endl;
    std::cout << "[3] Repetir consulta anterior" << std::endl;
    std::cout << "[4] Salir" << std::endl;
}

void imprimirMenuHistorial(){
    std::cout << "Elija una de las siguientes opciones: " << std::endl;
    std::cout << "[1] Historial en un archivo JSON" << std::endl;
    std::cout << "[2] Historial en un archivo CSV" << std::endl;
    std::cout << "[3] Borrar historial" << std::endl;
}