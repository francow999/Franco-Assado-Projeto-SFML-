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
set(BUILD_SHARED_LIBS OFF)   # SFML estático: o .exe não depende das DLLs sfml-*.dll
FetchContent_MakeAvailable(SFML)
 
# Pega automaticamente todos os .cpp dentro de SourceFiles (src)
file(GLOB SOURCES "src/*.cpp")
 
add_executable(sfml-app ${SOURCES})
 
target_include_directories(sfml-app PRIVATE include)
target_link_libraries(sfml-app PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)

# Copia os assets para a pasta do executável
add_custom_command(TARGET sfml-app POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:sfml-app>/assets)

# Windows: o módulo de áudio precisa da openal32.dll
if(WIN32)
    add_custom_command(TARGET sfml-app POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${sfml_SOURCE_DIR}/extlibs/bin/x64/openal32.dll
                $<TARGET_FILE_DIR:sfml-app>)
endif()

# cmake -S . -B build
# cmake --build build
# ./build/sfml-app