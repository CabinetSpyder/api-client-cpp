#include <iostream>
#include <string>

#include "../include/json.hpp"
#include "../include/historial.hpp"
#include "../include/curl_utils.hpp"
#include "../include/tiempo.hpp"

using json = nlohmann::json;



int main() {
    // Tu API key de OpenWeatherMap
    std::ifstream configFile("../config.json");
    json config;
    configFile >> config;
    std::string apiKey = config["api_key"];


    // Ciudad a consultar
    std::string ciudad;
    std::cout << "Introduce el nombre de la ciudad(ingles): ";
    std::getline(std::cin, ciudad);

    // URL de la API
    const std::string url = "https://api.openweathermap.org/data/2.5/weather?q=" + ciudad + "&appid=" + apiKey + "&units=metric";
    
    json jsonResponse = json::parse(hacerPeticionGET(url));

    // Obtener y mostrar la temperatura
    double temperatura = jsonResponse["main"]["temp"];
    std::string description = jsonResponse["weather"][0]["description"];
    double feels_like = jsonResponse["main"]["feels_like"];

    std::cout << "El clima en " << ciudad << " es: " << description << std::endl;
    std::cout << "Temperatura: " << temperatura << "°C" << std::endl;
    std::cout << "Sensacion termica: " << feels_like << "°C" << std::endl;

    guardarEnHistorialJSON(ciudad, temperatura, description, obtenerFechaHoraActual());
    guardarEnHistorialCSV(ciudad, temperatura, description, obtenerFechaHoraActual());
    return 0;
}