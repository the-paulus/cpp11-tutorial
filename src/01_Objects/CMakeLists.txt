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

set_property(TARGET builtin_types PROPERTY CXX_STANDARD 11)
