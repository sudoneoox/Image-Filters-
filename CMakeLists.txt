cmake_minimum_required(VERSION 3.14)
project(FILTERS)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)

# Include directories for header files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/helpers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TestImages)

# Glob source files
file(GLOB SOURCES 
     "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc"
     "${CMAKE_CURRENT_SOURCE_DIR}/src/filters/*.cc")

# Glob header files (optional, for IDEs to show headers)
file(GLOB HEADERS 
     "${CMAKE_CURRENT_SOURCE_DIR}/helpers/filters/*.h"
     "${CMAKE_CURRENT_SOURCE_DIR}/helpers/*.h")

# Define the executable target
add_executable(FILTERS ${SOURCES} ${HEADERS})

# Output directory path for .exe file /bin
set_target_properties(FILTERS PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)

# Uncomment and update this when you link libraries
# target_link_libraries(FILTERS PUBLIC PNG::PNG ${ZLIB_LIBRARY})
