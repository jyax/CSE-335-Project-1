# Declare the minimum required CMake version
cmake_minimum_required(VERSION 3.23)
project(project1)

set(CMAKE_CXX_STANDARD 14)

set(APPLICATION_LIBRARY GameLib)

# Request the required wxWidgets libs
# Turn off wxWidgets own precompiled header system, since
# it doesn't seem to work. The CMake version works much better.
set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

# Include the wxWidgets use file to initialize various settings
include(${wxWidgets_USE_FILE})

add_subdirectory(${APPLICATION_LIBRARY})
include_directories(${APPLICATION_LIBRARY})

set(SOURCE_FILES main.cpp pch.h GameApp.cpp GameApp.h)

# Define the build target for the executable
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCE_FILES})

# Link required libraries to the executable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES} ${APPLICATION_LIBRARY})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)

add_subdirectory(Tests)

# Copy images into output directory
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/images/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/images/)


# Copy images into output directory
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/data/)
