# API Client en C++

Este es un proyecto de práctica que implementa un cliente HTTP en C++ utilizando la biblioteca `libcurl`. El objetivo es reforzar mis conocimientos en el consumo de APIs REST, manejo de JSON y desarrollo de utilidades en C++ modernas.

## Características

- Realiza peticiones GET y POST a endpoints RESTful
- Maneja respuestas en formato JSON usando `nlohmann/json`
- Modular y fácilmente extensible
- Pensado como base para futuros proyectos que interactúen con servicios web

## Tecnologías

- C++20
- libcurl
- [nlohmann/json](https://github.com/nlohmann/json)

## Instalación

Clona el repositorio y compílalo con CMake:

```bash
git clone https://github.com/CabinetSpyder/api-client-cpp.git
cd api-client-cpp
mkdir build && cd build
cmake ..
make

```

Nota: La API uysada es la de https://openweathermap.org/api

🧩 Mejoras progresivas al proyecto actual
1. Entrada dinámica del usuario
Permitir al usuario introducir una ciudad desde consola y obtener su clima actual.

2. Parámetros de configuración
Leer la clave de API y parámetros desde un archivo .env o config.json.

3. Historial de consultas
Guardar en un archivo (CSV o JSON) las consultas realizadas con sus respuestas y fecha/hora.

4. Un menú interactivo
Usar un bucle de menú en consola para permitir al usuario repetir consultas, cambiar ciudad, ver historial, etc.