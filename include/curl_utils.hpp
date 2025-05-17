#ifndef CURL_UTILS_HPP
#define CURL_UTILS_HPP

#include <string>
#include <curl/curl.h>
#include <iostream>




/**
 * @brief Callback para escribir los datos recibidos por libcurl en una cadena.
 *
 * @param contents Puntero al bloque de datos recibido. [IN]
 * @param size Tamaño de cada bloque de datos. [IN]
 * @param nmemb Número de bloques recibidos. [IN]
 * @param userp Puntero a la cadena donde se acumulan los datos. [IN/OUT]
 * @return Número de bytes procesados. [OUT]
 */
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);


/**
 * @brief Realiza una solicitud HTTP GET a una URL y devuelve la respuesta como string.
 *
 * @param url URL del recurso al que se desea acceder. [IN]
 * @return Cadena con el contenido de la respuesta. Vacía si ocurre un error. [OUT]
 */
std::string hacerPeticionGET(const std::string& url);

/**
 * @brief Construye la url para contactar con la api
 * 
 * @param ciudad El nombre de la ciiudad a consultar
 * @param apikey Token secreto para poder hacer peticiones al servicio
 * @return Cadena con la url ya formada lista para ser usada
 */
std::string construirURL(const std::string& ciudad, const std::string& apiKey);

#endif