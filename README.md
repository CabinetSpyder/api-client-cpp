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

El historial (guardado en historial.json) tiene el siguiente formato en JSON:

```json 
{
  "historial": [
    {
      "ciudad": "Madrid",
      "temperatura": 19.4,
      "descripcion": "clear sky",
      "fecha": "2025-05-11 18:30:22"
    }
  ]
}

```



🧩 Mejoras progresivas al proyecto actual

1. Historial de consultas
Guardar en un archivo (CSV o JSON) las consultas realizadas con sus respuestas y fecha/hora.

2. Un menú interactivo
Usar un bucle de menú en consola para permitir al usuario repetir consultas, cambiar ciudad, ver historial, etc.