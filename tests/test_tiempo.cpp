#include <gtest/gtest.h>
#include "../include/tiempo.hpp"

TEST(TiempoTest, FormatoFechaCorrecto) {
    std::string fecha = obtenerFechaHoraActual();

    // Comprobamos que tiene al menos 19 caracteres (YYYY-MM-DD HH:MM:SS)
    ASSERT_GE(fecha.size(), 19);

    // Comprobamos que hay un espacio entre fecha y hora
    ASSERT_NE(fecha.find(' '), std::string::npos);

    // Comprobamos que contiene al menos dos puntos ':' para la hora
    int count = std::count(fecha.begin(), fecha.end(), ':');
    ASSERT_GE(count, 2);
}