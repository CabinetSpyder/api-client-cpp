#include <gtest/gtest.h>
#include "../include/historial.hpp"
#include "../include/json.hpp"

using json = nlohmann::json;


TEST(HistorialTest, ArchivoCreadoCorrectamenteJSON){

    std::string rutaArchivo = "../tests/temp/historial_test.json";

    // Asegurarse de que no exista antes del test
    std::filesystem::remove(rutaArchivo);

    guardarEnHistorialJSON("Madrid", 2.3, "Nublado", "2025-05-14 12:34:56", rutaArchivo);

    //Comprobamos que el archivo existe
    ASSERT_TRUE(std::filesystem::exists(rutaArchivo)) << "El archivo JSON no fue creado correctamente.";

    std::filesystem::remove(rutaArchivo);//Limpieza
}

TEST(HistorialTest, ContenidoCorrectoJSON){
    std::string rutaArchivo = "../tests/temp/historial_test.json";

    // Asegurarse de que no exista antes del test
    std::filesystem::remove(rutaArchivo);

    //Generamos una entrada
    guardarEnHistorialJSON("Madrid", 2.3, "Nublado", "2025-05-14 12:34:56", rutaArchivo);

    //Abrimos el fichero y volvamos los datos
    std::ifstream archivo(rutaArchivo);
    ASSERT_TRUE(archivo.is_open()) << "No se pudo abrir el Json correctamente";

    json contenido;
    archivo >> contenido;

    ASSERT_TRUE(contenido.contains("historial")) << "El archivo no contiene el campo historial";
    ASSERT_EQ(contenido["historial"].size(), 1) << "El tamano del campo historial no es 1, es " + contenido["historial"].size();

    //Nos quedamos con la primera (y unica) entrada del historial
    auto entrada1 = contenido["historial"][0];

    //Comprobamos que cada valor es el que esperamos
    EXPECT_EQ(entrada1["ciudad"], "Madrid"); //Si falla seguimos ejecutando el test
    EXPECT_EQ(entrada1["temperatura"], 2.3);
    EXPECT_EQ(entrada1["descripcion"], "Nublado");
    EXPECT_EQ(entrada1["fecha"], "2025-05-14 12:34:56");

    //Cerramos el archivo
    archivo.close();
    //Elminamos el archivo
    std::filesystem::remove(rutaArchivo);
}

TEST(HistorialTest, VariasEntradasJSON){
    std::string rutaArchivo = "../tests/temp/historial_test.json";

    // Asegurarse de que no exista antes del test
    std::filesystem::remove(rutaArchivo);

    //Primera entrada
    guardarEnHistorialJSON("Madrid", 20.3, "Despejado", "2025-05-14 12:34:56", rutaArchivo);
    //Segunda entrada
    guardarEnHistorialJSON("Barcelona", 27.6, "Parcialmente nublado", "2025-05-14 14:34:56", rutaArchivo);
    

    //Abrimos el fichero y volvamos los datos
    std::ifstream archivo(rutaArchivo);
    ASSERT_TRUE(archivo.is_open()) << "No se pudo abrir el Json correctamente";

    json contenido;
    archivo >> contenido;

    ASSERT_TRUE(contenido.contains("historial")) << "El archivo no contiene el campo historial";
    ASSERT_EQ(contenido["historial"].size(), 2) << "El tamano del campo historial no es 2, es " + contenido["historial"].size();

    //Nos quedamos con la segunda entrada del historial
    auto entrada1 = contenido["historial"][1];

    //Comprobamos que cada valor es el que esperamos
    EXPECT_EQ(entrada1["ciudad"], "Barcelona"); //Si falla seguimos ejecutando el test
    EXPECT_EQ(entrada1["temperatura"], 27.6);
    EXPECT_EQ(entrada1["descripcion"], "Parcialmente nublado");
    EXPECT_EQ(entrada1["fecha"], "2025-05-14 14:34:56");

    //Cerramos el archivo
    archivo.close();
    //Elminamos el archivo
    std::filesystem::remove(rutaArchivo);
}


TEST(HistorialTest, ArchivoCreadoCorrectamenteCSV){

    std::string rutaArchivo = "../tests/temp/historial_test.csv";

    // Asegurarse de que no exista antes del test
    std::filesystem::remove(rutaArchivo);

    guardarEnHistorialCSV("Madrid", 2.3, "Nublado", "2025-05-14 12:34:56", rutaArchivo);

    //Comprobamos que el archivo existe
    ASSERT_TRUE(std::filesystem::exists(rutaArchivo)) << "El archivo CSV no fue creado correctamente.";

    std::filesystem::remove(rutaArchivo);//Limpieza
}

TEST(HistorialTest, CabeceraCSVCorrecta){
    std::string rutaArchivo = "../tests/temp/historial_test.csv";

    // Asegurarse de que no exista antes del test
    std::filesystem::remove(rutaArchivo);

    guardarEnHistorialCSV("Madrid", 2.3, "Nublado", "2025-05-14 12:34:56", rutaArchivo);

    //Abrimos el archivo
    std::ifstream archivo(rutaArchivo);
    ASSERT_TRUE(archivo.is_open()) << "No se pudo abrir el historial CSV";

    std::string cabecera;
    std::getline(archivo, cabecera);

    //Comprobar que la cabecera es la correcta
    EXPECT_EQ(cabecera, "ciudad,temperatura,descripcion,fecha");

    //Cerramos el archivo
    archivo.close();
    //Borramos el archivo
    std::filesystem::remove(rutaArchivo);


}

TEST(HistorialTest, PrimeraEntradaCSVCorrecta) {
    std::string rutaArchivo = "../tests/temp/historial_test.csv";
    std::filesystem::remove(rutaArchivo);

    guardarEnHistorialCSV("Madrid", 22.5, "Soleado", "2025-05-14 15:00:00", rutaArchivo);

    std::ifstream archivo(rutaArchivo);
    ASSERT_TRUE(archivo.is_open()) << "No se pudo abrir el archivo CSV";

    std::string linea;
    std::getline(archivo, linea); // Cabecera, ignoramos
    std::getline(archivo, linea); // Primera entrada

    EXPECT_EQ(linea, "Madrid,22.5,Soleado,2025-05-14 15:00:00");

    archivo.close();
    std::filesystem::remove(rutaArchivo);
}

TEST(HistorialTest, VariasEntradasCSVCorrectas) {
    std::string rutaArchivo = "../tests/temp/historial_test.csv";
    std::filesystem::remove(rutaArchivo);
    
    guardarEnHistorialCSV("Barcelona", 27.0, "Nubaldo", "2025-05-14 16:00:00", rutaArchivo);
    guardarEnHistorialCSV("Madrid", 22.5, "Soleado", "2025-05-14 15:00:00", rutaArchivo);
    

    std::ifstream archivo(rutaArchivo);
    ASSERT_TRUE(archivo.is_open()) << "No se pudo abrir el archivo CSV";

    std::string linea;
    std::getline(archivo, linea); // Cabecera, ignoramos
    std::getline(archivo, linea); // Primera entrada, ignoramos
    std::getline(archivo, linea); //Segunda entrada

    EXPECT_EQ(linea, "Madrid,22.5,Soleado,2025-05-14 15:00:00");

    archivo.close();
    std::filesystem::remove(rutaArchivo);
    
}