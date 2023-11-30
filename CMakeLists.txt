cmake_minimum_required(VERSION 3.14)
project(FILTERS)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)


# FetchContent for dependencies
include(FetchContent)


FetchContent_Declare(
  zlib
  GIT_REPOSITORY https://github.com/madler/zlib.git
  GIT_TAG v1.2.11
)
FetchContent_MakeAvailable(zlib)

# After zlib is made available, set the ZLIB variables
set(ZLIB_LIBRARY ${zlib_BINARY_DIR}/${CMAKE_STATIC_LIBRARY_PREFIX}zlib${CMAKE_STATIC_LIBRARY_SUFFIX})
set(ZLIB_INCLUDE_DIR ${zlib_SOURCE_DIR} ${zlib_BINARY_DIR})

# Fetch libpng
FetchContent_Declare(
  libpng
  GIT_REPOSITORY https://github.com/glennrp/libpng.git
  GIT_TAG v1.6.37
)
# Before making libpng available, let's tell it where to find zlib
set(PNG_BUILD_ZLIB ON CACHE BOOL "Custom zlib Location, else find_package is used")
FetchContent_MakeAvailable(libpng)

# include directory for header files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/helpers) 


# all the source files
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc)

# define the executable target
add_executable(FILTERS ${SOURCES})

# output directory path for .exe file /bin
set_target_properties(FILTERS PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin 
)


# Link libraries
target_link_libraries(FILTERS PUBLIC PNG::PNG ${ZLIB_LIBRARY})
