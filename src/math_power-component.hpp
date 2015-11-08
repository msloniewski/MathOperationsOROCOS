#ifndef OROCOS_MATH_POWER_COMPONENT_HPP
#define OROCOS_MATH_POWER_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Math_power : public RTT::TaskContext{
  public:
    Math_power(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
  private:
    RTT::InputPort<double> _evPort;
    RTT::OutputPort<double> _outPort;
};
#endif
