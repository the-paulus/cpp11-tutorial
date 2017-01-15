
add_executable(simple_functions 01_simple_functions.cpp simple_main.cpp)
add_executable(overloaded_functions 02_overloaded_functions.cpp overloaded_main.cpp)
add_executable(recursive_functions 03_recursive_functions.cpp 
recursive_main.cpp)
add_executable(refret_functions 04_refret_functions.cpp refret_main.cpp)
add_executable(retarr_functions 05_retarr_functions.cpp retarr_main.cpp)

set_property(TARGET simple_functions PROPERTY CXX_STANDARD 11)
set_property(TARGET overloaded_functions PROPERTY CXX_STANDARD 11)
set_property(TARGET recursive_functions PROPERTY CXX_STANDARD 11)
set_property(TARGET refret_functions PROPERTY CXX_STANDARD 11)
set_property(TARGET retarr_functions PROPERTY CXX_STANDARD 11)
