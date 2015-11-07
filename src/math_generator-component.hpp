#ifndef OROCOS_MATH_GENERATOR_COMPONENT_HPP
#define OROCOS_MATH_GENERATOR_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Math_generator : public RTT::TaskContext{
  public:
    Math_generator(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
};
#endif
