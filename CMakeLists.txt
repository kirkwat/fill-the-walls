cmake_minimum_required(VERSION 3.16)
project(21s_pa01_watson)
set(CMAKE_CXX_STANDARD 17)

set(CIMG_Path ${PROJECT_SOURCE_DIR} CImg.h) # Set your CIMG_Path to where you extracted CIMG
add_executable(${PROJECT_NAME} main.cpp WallFiller.cpp WallFiller.h Stats.cpp Stats.h FillerAlgos.cpp FillerAlgos.h Image.cpp Image.h)
# ADDING COOL IMAGE
target_include_directories(${PROJECT_NAME} PRIVATE ${CIMG_Path})
# ADDING THREADS fixes pthread_lock
find_package(Threads)
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
# ADDING X11
find_package(X11 REQUIRED)
include_directories( ${X11_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${X11_LIBRARIES})
# ADDING JPEG
find_package(JPEG REQUIRED)
include_directories(${JPEG_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${JPEG_LIBRARY})
target_compile_definitions(${PROJECT_NAME} PRIVATE cimg_use_jpeg=1)
# ADDING PNG
find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${PNG_LIBRARY})
target_compile_definitions(${PROJECT_NAME} PRIVATE cimg_use_png=1)