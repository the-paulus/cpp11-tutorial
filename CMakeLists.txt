# State the minimum version of CMake for this project. This should be the first 
# CMake command called.
cmake_minimum_required(VERSION 2.6)

# Declare the name of the project and set the PROJECT_NAME variable
# Other parameters of the project command include
#   [LANGUAGES] [<language-name>...]
#   [VERSION <major>[.<minor>[.<patch>[.tweak]]]] - Requires CMP0048 and can 
#             only use non-negative integers. If omitted, version is an 
#	      empty string.
# 
# This command sets the PROJECT_NAME variable along with PROJECT_SOURCE_DIR, 
# <PROJECT-NAME>_SOURCE_DIR, PROJECT_BINARY_DIR, and <PROJECT-NAME>_BINARY_DIR
#
# If VERSION option is used, then the following variables will also be set:
#   PROJECT_VERSION, <PROJECT-NAME>_VERSION, PROJECT_VERSION_MAJOR, 
#   <PROJECT-NAME>_VERSION_MAJOR, PROJECT_VERSION_MINOR, 
#   <PROJECT-NAME>_VERSION_MINOR, PROJECT_VERSION_PATCH,  
#   <PROJECT-NAME>_VERSION_PATCH, PROJECT_VERSION_TWEAK,  
#   <PROJECT-NAME>_VERSION_TWEAK
#
project(cpp11-tutorial)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# The add_subdirectory command specifies a directory in which a CMakeLists.txt 
# file can be found along with additional code files. The
# only required parameter of the add_subdirectory command is the src_directory:
#
# add_subdirectory(source_dir [binary_dir] [EXCLUDE_FROM_ALL])
#
# The [binary_dir] specifies where to place the compiled files When the
# EXCLUDE_FROM_ALL is defined, the subdirectory targets defined in the
# subdirectory are excluded from the ALL target of the parent directory, this
# directory, as well as being excluded from the IDE project files. The
# EXCLUDE_FROM_ALL is used when the contents of the directory contains a
# completely separate part of the program that isn't necessary to the build,
# such as examples. However, the parent's build target is dependent on a target
# defined within a subdirectory that is marked to be excluded, it will be
# included regardless as the inter-target dependencies supersede the exclusion. 
#
# The subdirectory's CMakeLists.txt typically includes a call to the project 
# command in order to facilitate a full build system to be generated within the
# specified directory. 
add_subdirectory(src/01_Objects)
add_subdirectory(src/02_Statements)
add_subdirectory(src/03_Exceptions)
add_subdirectory(src/04_Functions/06_Pointer_Functions)
add_subdirectory(src/05_Classes/01_Struct)
add_subdirectory(src/05_Classes/02_Class)

add_executable(debugging src/debugging.cpp)

# The set_property command takes three options. The first option is the scope
# in which this property applies to. The scope of the property must be one
# of the following:
#    GLOBAL
#    DIRECTORY [dir] where [dir] is a full or relative path.
#    TARGET [t1, t2, ...] is either an executable or library. Multiple targets 
#                         can be specified.
#    SOURCE [src1, src2, ...] Apply to source files in the same directory as the
#                             CMakeLists.txt file.
#    INSTALL, TEST, and CACHE indicate that the property being set are for those
#                             entries.
# PROPERTY is required and followed by the name of the property that's being
# set followed by one or more values separated by semicolons.
#
# Setting properties of the project. In this case we are setting the 
# CXX_STANDARD property to 11, C++11. This property is applied globally
set_property(GLOBAL PROPERTY CXX_STANDARD 11)


