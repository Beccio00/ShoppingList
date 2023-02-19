cmake_minimum_required(VERSION 3.23)
project(ProjectLab)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES class.h)
add_executable(ProjectLab main.cpp listaSpesa.h listaSpesa.cpp Observer.h Subject.h)
