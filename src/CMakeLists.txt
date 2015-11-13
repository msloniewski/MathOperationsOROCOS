
#
# Components, types and plugins.
#
# The CMake 'target' names are identical to the first argument of the
# macros below, except for orocos_typegen_headers, where the target is fully
# controlled by generated code of 'typegen'.
#

# Creates a component library libmathops-<target>.so
# and installs in the directory lib/orocos/mathops/
#
orocos_component(mathops mathops-component.hpp mathops-component.cpp)
orocos_component(math_power math_power-component.hpp math_power-component.cpp) 
orocos_component(math_offset math_offset-component.hpp math_offset-component.cpp) 
orocos_component(math_amplification math_amplification-component.hpp math_amplification-component.cpp) 
orocos_component(math_absolute math_absolute-component.hpp math_absolute-component.cpp) 
orocos_component(math_integration math_integration-component.hpp math_integration-component.cpp) 
orocos_component(math_derivative math_derivative-component.hpp math_derivative-component.cpp) 
orocos_component(math_sum math_sum-component.hpp math_sum-component.cpp) 
orocos_component(math_generator math_generator-component.hpp math_generator-component.cpp) 
orocos_component(math_siglog math_siglog-component.hpp math_siglog-component.cpp) 
orocos_component(math_mult math_mult-component.hpp math_mult-component.cpp)
# ...you may add multiple source files
#
# You may add multiple orocos_component statements.

#
# Additional headers:
#
# Installs in the include/orocos/mathops/ directory
#
orocos_install_headers(mathops-component.hpp math_power-component.hpp math_offset-component.hpp math_amplification-component.hpp math_absolute-component.hpp math_integration-component.hpp math_derivative-component.hpp math_sum-component.hpp math_generator-component.hpp math_siglog-component.hpp math_mult-component.hpp) # ...you may add multiple header files
#
# You may add multiple orocos_install_headers statements.

