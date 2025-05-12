cmake_minimum_required(VERSION 3.10)

# Obtener nombre de la carpeta actual para usarlo como nombre del proyecto
get_filename_component(ProjectName ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${ProjectName} LANGUAGES CXX)

# Estándar de C++
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

# Buscar automáticamente todos los archivos fuente .cpp dentro de src/
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# Crear el ejecutable con los archivos encontrados
add_executable(${ProjectName} ${SRC_FILES})

# Agregar libreria json
target_include_directories(${ProjectName} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Agregar libreria Curl
find_package(CURL REQUIRED)
target_include_directories(${ProjectName} PRIVATE ${CURL_INCLUDE_DIR})
target_link_libraries(${ProjectName} PRIVATE ${CURL_LIBRARIES}) 