#include <gtest/gtest.h>

// Aquí puedes incluir tus archivos de pruebas
#include "../include/tiempo.hpp"
#include "../include/historial.hpp"
#include "../include/curl_utils.hpp"

// La función main la proporciona GoogleTest automáticamente si usas GTest::gtest_main
// No necesitas definirla, a menos que quieras personalizar el comportamiento
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}