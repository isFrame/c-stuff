cmake_minimum_required(VERSION 3.30.7)
project(Magazzino)
include_directories(include)
add_library(Prodotti src/prodotti.cpp)
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} Prodotti)

