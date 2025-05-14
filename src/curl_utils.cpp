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

        }

        curl_easy_cleanup(curl); //Limpiar instancias de curl           
        
    }

    return readBuffer; //Devolvemos la respuesta
}