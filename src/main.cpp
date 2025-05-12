#include <iostream>
#include <string>
#include <curl/curl.h>
#include "../include/json.hpp"
#include <fstream>

// Función para manejar la respuesta de la API
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    // Tu API key de OpenWeatherMap
    std::ifstream configFile("../config.json");
    nlohmann::json config;
    configFile >> config;
    std::string apiKey = config["api_key"];


    // Ciudad a consultar
    std::string city;
    std::cout << "Introduce el nombre de la ciudad(ingles): ";
    std::getline(std::cin, city);

    // URL de la API
    const std::string url = "https://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + apiKey + "&units=metric";
    
    // Inicializar cURL
    CURL *curl = curl_easy_init();
    if(curl) {
        // Hacer la solicitud
        std::string readBuffer;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        
        // Ejecutar la solicitud
        CURLcode res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            std::cerr << "Error en la solicitud: " << curl_easy_strerror(res) << std::endl;
        } else {

            
            // Convertir la respuesta a JSON
            nlohmann::json jsonResponse = nlohmann::json::parse(readBuffer);
            // Imprimir el JSON bien indentado
            //std::cout << jsonResponse.dump(4) << std::endl;  // El "4" es para usar una indentación de 4 espacios
            

            // Obtener y mostrar la temperatura
            double temperature = jsonResponse["main"]["temp"];
            std::string description = jsonResponse["weather"][0]["description"];
            double feels_like = jsonResponse["main"]["feels_like"];

            std::cout << "El clima en " << city << " es: " << description << std::endl;
            std::cout << "Temperatura: " << temperature << "°C" << std::endl;
            std::cout << "Sensacion termica: " << feels_like << "°C" << std::endl;
        }
        curl_easy_cleanup(curl);
    }

    return 0;
}