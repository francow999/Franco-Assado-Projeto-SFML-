cmake_minimum_required(VERSION 3.16)
project(FrancoAssado LANGUAGES CXX)
 
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
 
# Baixa e compila o SFML 2.6.1 automaticamente.
# Garante que todo mundo (Linux, Windows, Mac) usa exatamente a mesma versao,
# sem depender do que cada um instalou manualmente na maquina.
include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.1
)
FetchContent_MakeAvailable(SFML)
 
# Pega automaticamente todos os .cpp dentro de SourceFiles (src)
file(GLOB SOURCES "src/*.cpp")
 
add_executable(sfml-app ${SOURCES})
 
target_include_directories(sfml-app PRIVATE include)
target_link_libraries(sfml-app PRIVATE sfml-graphics sfml-window sfml-system)

# cmake -S . -B build
# cmake --build build
# ./build/sfml-app