cmake_minimum_required(VERSION 3.23)
project(ProjectLab)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)


set(SOURCE_FILES Observer.h Subject.h ListaSpesa.h ListaSpesa.cpp Utente.h Utente.cpp Prodotto.h Prodotto.cpp)
add_executable(ProjectLab main.cpp )
add_library(core ${SOURCE_FILES})
target_link_libraries(ProjectLab core)
