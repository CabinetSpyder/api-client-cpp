#include "../include/tiempo.hpp"

// Devuelve una cadena con fecha y hora actual en formato "YYYY-MM-DD HH:MM:SS"
std::string obtenerFechaHoraActual() {
    auto now = std::chrono::system_clock::now(); // Obtener fecha del sistema
    std::time_t tiempoActual = std::chrono::system_clock::to_time_t(now); 

    std::stringstream ss;
    ss << std::put_time(std::localtime(&tiempoActual), "%Y-%m-%d %H:%M:%S"); // Pasar la fecha a formato legible
    return ss.str();
}