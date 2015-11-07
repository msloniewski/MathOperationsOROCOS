#ifndef OROCOS_MATH_ABSOLUTE_COMPONENT_HPP
#define OROCOS_MATH_ABSOLUTE_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Math_absolute : public RTT::TaskContext{
  public:
    Math_absolute(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
  private:
    RTT::InputPort<double> _evPort;
    RTT::OutputPort<double> _outPort;
    double absolute(double _in);
};
#endif
