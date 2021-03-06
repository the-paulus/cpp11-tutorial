# The add_executable command indicates that we want to create an executable 
# program from the supplied source files. Other parameters of the add_executable 
# command are:
# 
# <name>            - The name of the target that will be created by the 
#                     command. The target name is also the name of the 
#                     executable built from source. On Windows, the executable 
#                     will be named "<name>.exe"
# [WIN32]           - Using this parameter will create an additional entry 
#                     called WinMain that makes it a GUI executable.
# [MACOSX_BUNDLE]   - Defining a target as a MACOSX_BUNDLE will create a bundled
#                     application that can be run from the finder.
# [EXCLUDE_FROM_ALL]- Indicates that the target must be specifically built.
# sources           - Define a list of sources that are required in the 
#                     construction of the executable.
add_executable(builtin_types 01_builtin_types.cpp)
add_executable(references 02_references.cpp)
add_executable(pointers 03_pointers.cpp)
add_executable(arrays 04_arrays.cpp)
add_executable(sequential_containers 05_sequential_containers.cpp)
add_executable(vectors 06_vectors.cpp)
add_executable(strings 07_strings.cpp)
add_executable(lists 08_lists.cpp)
add_executable(forward_lists 09_forward_lists.cpp)

set_property(TARGET builtin_types PROPERTY CXX_STANDARD 11)
set_property(TARGET arrays PROPERTY CXX_STANDARD 11)
