cmake_minimum_required(VERSION 3.23)
project(ProjectLab)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES class.h)
add_executable(ProjectLab main.cpp Observer.h Subject.h ListaSpesa.h ListaSpesa.cpp Utente.h Utente.cpp Prodotto.h)
