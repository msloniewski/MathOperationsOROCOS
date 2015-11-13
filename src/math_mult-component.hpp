#ifndef OROCOS_MATH_MULT_COMPONENT_HPP
#define OROCOS_MATH_MULT_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Math_mult : public RTT::TaskContext{
  public:
    Math_mult(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
  private:
    RTT::InputPort<double> _evPort1;
    RTT::InputPort<double> _evPort2;
    RTT::OutputPort<double> _outPort;
};
#endif
