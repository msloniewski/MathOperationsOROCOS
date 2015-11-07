#ifndef OROCOS_MATH_OFFSET_COMPONENT_HPP
#define OROCOS_MATH_OFFSET_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Math_offset : public RTT::TaskContext{
  public:
    Math_offset(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
};
#endif
