cmake_minimum_required(VERSION 3.10)
project(OpenCVProject)

set(OpenCV_DIR "C:/opencv/build")
# Utilisation de C++ 17
set(CMAKE_CXX_STANDARD 17)

# Trouver OpenCV
find_package(OpenCV REQUIRED)
#include_directories("C:/opencv/build/include")
include_directories(${OpenCV_INCLUDE_DIRS})

# Ajouter l'exécutable avec uniquement main.cpp
add_executable(${PROJECT_NAME} main.cpp)

# Lier OpenCV à l'exécutable
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
