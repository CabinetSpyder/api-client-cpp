#include <iostream>
#include <string>

#include "../include/json.hpp"
#include "../include/historial.hpp"
#include "../include/curl_utils.hpp"
#include "../include/tiempo.hpp"
#include "../include/menu.hpp"
#include "../include/leer_utils.hpp"

using json = nlohmann::json;



int main() {

    // Tu API key de OpenWeatherMap
    std::ifstream configFile("../config.json");
    if (!configFile) {
        std::cerr << "No se pudo abrir el archivo config.json\n";
        return 1;
    }
    json config;
    configFile >> config;
    std::string apiKey = config["api_key"];

    // Ciudad a consultar
    std::string ciudad;
    int opcion;
    int opcionHistorial;

    std::string url;

    //Variables para saber si guardamos un historial
    bool JsonHistorial = false;
    bool CSVHistorial = false;



    while(true){
        imprimirMenuPrincipal();
        opcion = leerEnteroDesdeEntrada();
        if(opcion<1 || opcion>4){
            std::cout << "Entrada no valida" << std::endl;
            
        }else{
    
            //TODO ir haciendo las opciones
            if(opcion == 1){ //Introducir ciudad y hacer consulta
                std::cout << "Introduce el nombre de la ciudad(ingles): ";
                std::getline(std::cin, ciudad);
                
                // URL de la API
                url = "https://api.openweathermap.org/data/2.5/weather?q=" + ciudad + "&appid=" + apiKey + "&units=metric";

                json jsonResponse = json::parse(hacerPeticionGET(url));
                
                std::cout << std::endl;
                std::cout << "El clima en " << ciudad << " es: " << jsonResponse["weather"][0]["description"] << std::endl;
                std::cout << "Temperatura: " << jsonResponse["main"]["temp"] << "°C" << std::endl;
                std::cout << std::endl;

                //Comprobar si se guarda ene el historial
                if(JsonHistorial) guardarEnHistorialJSON(ciudad, jsonResponse["main"]["temp"],jsonResponse["weather"][0]["description"], obtenerFechaHoraActual());
                
                if(CSVHistorial) guardarEnHistorialCSV(ciudad, jsonResponse["main"]["temp"],jsonResponse["weather"][0]["description"], obtenerFechaHoraActual());

            }else if(opcion == 2){
                while(true){
                    imprimirMenuHistorial();
                    opcionHistorial = leerEnteroDesdeEntrada();
                    if(opcionHistorial<1 || opcionHistorial>4){
                        std::cout << "Entrada no valida" << std::endl;

                    }else{
                        if(opcionHistorial == 1){
                            JsonHistorial = true;
                            std::cout << "El historial se guardara en historial.json" << std::endl;
                            break;

                        }else if(opcionHistorial == 2){
                            CSVHistorial = true;
                            std::cout << "El historial se guardar en historial.csv" << std::endl;
                            break;

                        }else if(opcionHistorial == 3){
                            borrarHistorial();
                            std::cout << "Historial borrado" << std::endl;
                            break;
                        }

                    }

                }

            }else if(opcion == 3){
                
                if(!ciudad.empty()){ //Se ha hecho una consulta previa
                    // URL de la API
                    url = "https://api.openweathermap.org/data/2.5/weather?q=" + ciudad + "&appid=" + apiKey + "&units=metric";
                    json jsonResponse = json::parse(hacerPeticionGET(url));
                    
                    std::cout << std::endl;
                    std::cout << "El clima en " << ciudad << " es: " << jsonResponse["weather"][0]["description"] << std::endl;
                    std::cout << "Temperatura: " << jsonResponse["main"]["temp"] << "°C" << std::endl;
                    std::cout << std::endl;

                    //Comprobar si se guarda ene el historial
                    if(JsonHistorial) guardarEnHistorialJSON(ciudad, jsonResponse["main"]["temp"],jsonResponse["weather"][0]["description"], obtenerFechaHoraActual());
                    
                    if(CSVHistorial) guardarEnHistorialCSV(ciudad, jsonResponse["main"]["temp"],jsonResponse["weather"][0]["description"], obtenerFechaHoraActual());

                }else{
                    std::cout << "Primero debes realizar una consulta con una ciudad.\n";
                    continue;
                }

                
            }else if(opcion == 4){
                std::cout << "Gracias por usar el cliente. Nos vemos pronto :D" << std::endl;
                break;
            }

        }
        
        

    }


    return 0;
}