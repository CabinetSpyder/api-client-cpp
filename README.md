# API Client en C++

Este proyecto implementa un cliente HTTP en C++ utilizando la biblioteca `libcurl`. Su objetivo principal es reforzar conocimientos prácticos en:

- Consumo de APIs REST
- Manejo de JSON moderno con `nlohmann/json`
- Diseño modular en C++
- Pruebas unitarias con GoogleTest

## Características

- Realiza solicitudes HTTP **GET** a la API de OpenWeatherMap
- Procesa respuestas en formato JSON
- Guarda un historial de consultas en archivos `JSON` y `CSV`
- Menú interactivo por consola
- Estructura modular y fácilmente extensible
- Pruebas unitarias con **GoogleTest**

## Tecnologías

- **C++20**: El lenguaje principal utilizado para el desarrollo del proyecto.
- **libcurl**: Para realizar solicitudes HTTP GET y POST a la API externa.
- [nlohmann/json](https://github.com/nlohmann/json)
- **GoogleTest**: Para las pruebas unitarias del proyecto, garantizando la calidad y fiabilidad del código.
- **CMake**: Para la configuración y construcción del proyecto.
- **Git**: Utilizado para el control de versiones y gestión del código fuente.


## Instalación

Clona el repositorio y compílalo con CMake:

```bash
git clone https://github.com/CabinetSpyder/api-client-cpp.git
cd api-client-cpp
mkdir build && cd build
cmake ..
make

```

⚠️ Nota: Para que funcione correctamente, necesitas una clave de API válida de OpenWeatherMap, que debe colocarse en el archivo config.json.

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

## Para ejecutar los test

```bash
./tests 
```
