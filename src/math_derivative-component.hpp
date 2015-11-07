#ifndef OROCOS_MATH_DERIVATIVE_COMPONENT_HPP
#define OROCOS_MATH_DERIVATIVE_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Math_derivative : public RTT::TaskContext{
  public:
    Math_derivative(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
};
#endif
