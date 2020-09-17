cmake_minimum_required(VERSION 3.10)
project(mode7)

add_definitions(-D SDL2)
set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(sdl)
include_directories(.)

set(SRC_FILES bmp.c mode7.c obj.c render.c sdl/pocadv.c)
set(RESOURCE_FILES res/buildings.gif res/char.gif res/HardVacuum.gif res/pyramid.model res/sky.gif)

# Mac OSX Bundle Properties
set(MACOSX_BUNDLE_NAME "Mode 7")
set(MACOSX_BUNDLE_PACKAGE_NAME "rangeli.mode7")

set_source_files_properties(${RESOURCE_FILES} PROPERTIES MACOSX_PACKAGE_LOCATION Resources)
add_executable(${PROJECT_NAME} ${SRC_FILES} ${RESOURCE_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_NAME ${MACOSX_BUNDLE_NAME}
        MACOSX_BUNDLE ON
        MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/MacOSXBundleInfo.plist.in)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
