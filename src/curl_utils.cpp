#include "../include/curl_utils.hpp"

// Función para manejar la respuesta de la API
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    
    ((std::string*)userp)->append((char*)contents, size * nmemb);


    return size * nmemb;
}

std::string hacerPeticionGET(const std::string& url){

    // Inicializar cURL
    CURL *curl = curl_easy_init();
    std::string readBuffer;

    if(curl) {
        // Hacer la solicitud
        
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        
        // Ejecutar la solicitud
        CURLcode res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            std::cerr << "Error en la solicitud: " << curl_easy_strerror(res) << std::endl;
            std::string error_msg = "Error en la solicitud CURL: ";
            error_msg += curl_easy_strerror(res);
            curl_easy_cleanup(curl);
            throw std::runtime_error(error_msg);

        }

        long http_code = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

        curl_easy_cleanup(curl); //Limpiar instancias de curl           
        if (http_code != 200) {
            throw std::runtime_error("Respuesta HTTP no válida. Código: " + std::to_string(http_code));
        }
    }

    return readBuffer; //Devolvemos la respuesta
}


std::string construirURL(const std::string& ciudad, const std::string& apiKey) {
    return "https://api.openweathermap.org/data/2.5/weather?q=" + ciudad + 
           "&appid=" + apiKey + "&units=metric";
}