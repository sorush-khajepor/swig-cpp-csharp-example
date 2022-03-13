cmake_minimum_required(VERSION 3.16)

project(AnimalWrapperProj VERSION 1.0 LANGUAGES CXX)

if ( MSVC )
  set(SWIG_DIR "C:/Users/sorus/workspace/swigwin-4.0.2/Lib")
  set(SWIG_EXECUTABLE "C:/Users/sorus/workspace/swigwin-4.0.2/swig.exe")  
endif (MSVC)

find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})


# Set .Net project directory
set(NET_PROJECT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../dotNetSample")

# Add swig flags here
set(CMAKE_SWIG_FLAGS "")


set_property(SOURCE animal.i PROPERTY CPLUSPLUS ON)
set_source_files_properties(animal.i PROPERTIES SWIG_FLAGS "-includeall")


swig_add_library(animal
  TYPE SHARED
  LANGUAGE CSharp
  SOURCES animal.i animal.cpp
  OUTPUT_DIR ${NET_PROJECT_DIR}
  OUTFILE_DIR ${NET_PROJECT_DIR}
  )

# for copying animal.dll to .Net project dir dir
set_target_properties( animal
    PROPERTIES
    # These copy animal.dll on Windows to .Net project directory
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${NET_PROJECT_DIR}
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${NET_PROJECT_DIR}
    
    # This copies animal.so on Linux to .Net project directory
    LIBRARY_OUTPUT_DIRECTORY ${NET_PROJECT_DIR}

    # Set address of C++ headers
    INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}
)
