cmake_minimum_required(VERSION 3.10)
project(mode7)

add_definitions(-D SDL2)
set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(sdl)
include_directories(.)

set(SRC_FILES bmp.c mode7.c obj.c render.c sdl/pocadv.c)
set(RESOURCE_FILES res/buildings.gif res/char.gif res/HardVacuum.gif res/pyramid.obj res/sky.gif)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${RESOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
