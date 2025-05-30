#include "../include/historial.hpp"

using json = nlohmann::json;

void guardarEnHistorialJSON(const std::string& ciudad, double temperatura, const std::string& descripcion, const std::string& fechaHora, const std::string& rutaArchivo) {
    
    json historial;

    // Si el archivo ya existe, lo leemos
    std::ifstream archivoEntrada(rutaArchivo);
    if (archivoEntrada.is_open()) {
        try {
            archivoEntrada >> historial; //Pasamos el contenido del archivo a la variable historial para poder hacer cambios
        } catch (...) {
            // si el JSON es inválido o vacío, empezamos desde cero
            historial = json::object();
        }
        archivoEntrada.close();
    }

    // Asegurarse de que tiene un array llamado "historial"
    if (!historial.contains("historial") || !historial["historial"].is_array()) {
        historial["historial"] = json::array();
    }

    // Crear nuevo registro
    json nuevaEntrada = {
        {"ciudad", ciudad},
        {"temperatura", temperatura},
        {"descripcion", descripcion},
        {"fecha", fechaHora}
    };

    // Añadir entrada al historial
    historial["historial"].push_back(nuevaEntrada);

    // Escribir al archivo
    std::ofstream archivoSalida(rutaArchivo);
    archivoSalida << std::setw(4) << historial << std::endl;  // Metemos la info en la instancia de archivo de salida con indentado bonito, sustityendo todo lo que habia con la nueva info.
    archivoSalida.close();
}

void guardarEnHistorialCSV(const std::string& ciudad, double temperatura, const std::string& descripcion, const std::string& fechaHora, const std::string& rutaArchivo) {
    bool archivoExiste = std::filesystem::exists(rutaArchivo);

    std::ofstream archivoSalida(rutaArchivo, std::ios::app); // abrimos en modo append

    if (!archivoExiste) {
        // Escribimos la cabecera solo si el archivo no existía
        archivoSalida << "ciudad,temperatura,descripcion,fecha\n";
    }

    // Escribimos los datos en una nueva línea
    archivoSalida << ciudad << ","
                  << temperatura << ","
                  << descripcion << ","
                  << fechaHora << "\n";

    archivoSalida.close();
}

void borrarHistorial(){
    std::filesystem::remove("historial.json");
    std::filesystem::remove("historial.csv");
}