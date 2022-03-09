cmake_minimum_required(VERSION 3.5)

project(ModeloLinealR LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(project_sources
    main.cpp
    Extraccion/extraer.cpp)

set(project_headers
    Extraccion/extraer.h)


add_executable(${PROJECT_NAME}
    ${project_sources}
    ${project_headers})
