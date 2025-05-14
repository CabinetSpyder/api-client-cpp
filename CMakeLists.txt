# CMake mínimo requerido
cmake_minimum_required(VERSION 3.10)

# Obtener nombre de la carpeta actual para usarlo como nombre del proyecto
get_filename_component(ProjectName ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${ProjectName} LANGUAGES CXX)

# Establecer el estándar de C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Establecer el tipo de build como Release por defecto si no se define
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Flags para compiladores GNU y Clang en modo Release
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -DNDEBUG -Wall -Wextra -Wpedantic")
endif()

# Buscar todos los archivos fuente .cpp en la carpeta src
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# Crear la librería core, donde agruparemos los archivos fuente de la implementación
add_library(core STATIC ${SRC_FILES})

# Crear el ejecutable principal api-client-cpp y vincularlo con la librería core
add_executable(api-client-cpp
    src/main.cpp
)

# Vincular la librería core al ejecutable
target_link_libraries(api-client-cpp PRIVATE core)

# Agregar librerías externas necesarias (Curl y JSON)
find_package(CURL REQUIRED)
target_include_directories(api-client-cpp PRIVATE ${CURL_INCLUDE_DIR})
target_link_libraries(api-client-cpp PRIVATE ${CURL_LIBRARIES})

# Agregar la librería JSON
target_include_directories(api-client-cpp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# --- Testing ---

# Habilitar la funcionalidad de testing en CMake
enable_testing()

# Incluir GoogleTest como una dependencia externa
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

# Esto es para evitar conflictos de compilación en Windows (no afecta en Linux)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Descarga y configura GoogleTest
FetchContent_MakeAvailable(googletest)

# Detecta todos los archivos de test en la carpeta tests/
file(GLOB TEST_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)

# Crea un ejecutable de tests
add_executable(tests ${TEST_SOURCES})

# Le indicamos que enlace con tu ejecutable principal (por si usas funciones tuyas) y con GoogleTest
target_link_libraries(tests
    PRIVATE
        core
        GTest::gtest_main
)

# Esto le dice a CMake que descubra los tests y permita correrlos con `ctest`
include(GoogleTest)
gtest_discover_tests(tests)
