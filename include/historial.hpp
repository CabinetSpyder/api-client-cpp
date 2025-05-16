#ifndef HISTORIAL_HPP
#define HISTORIAL_HPP

#include <string>
#include <fstream>
#include <filesystem>
#include "../include/json.hpp"

/**
 * @brief Guarda una entrada en el historial de consultas meteorológicas en formato JSON.
 *
 * @param ciudad Nombre de la ciudad consultada. [IN]
 * @param temperatura Temperatura en grados Celsius. [IN]
 * @param descripcion Descripción del estado del clima. [IN]
 * @param fechaHora Fecha y hora de la consulta. [IN]
 * @param rutaArchivo Ruta del archivo JSON donde guardar el historial. [IN]
 */
void guardarEnHistorialJSON(const std::string& ciudad,
                             double temperatura,
                             const std::string& descripcion,
                             const std::string& fechaHora,
                             const std::string& rutaArchivo = "historial.json");



/**
 * @brief Guarda una entrada en el historial de consultas meteorológicas en formato CSV.
 *
 * @param ciudad Nombre de la ciudad consultada. [IN]
 * @param temperatura Temperatura en grados Celsius. [IN]
 * @param descripcion Descripción del estado del clima. [IN]
 * @param fechaHora Fecha y hora de la consulta. [IN]
 * @param rutaArchivo Ruta del archivo JSON donde guardar el historial. [IN]
 */
void guardarEnHistorialCSV(const std::string& ciudad, 
                            double temperatura, 
                            const std::string& descripcion, 
                            const std::string& fechaHora, 
                            const std::string& rutaArchivo = "historial.csv");


/**
 * @brief Borra los archivos historial.json e historial.csv
 */
void borrarHistorial();

#endif