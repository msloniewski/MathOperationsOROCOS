#ifndef OROCOS_MATH_INTEGRATION_COMPONENT_HPP
#define OROCOS_MATH_INTEGRATION_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Math_integration : public RTT::TaskContext{
  public:
    Math_integration(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
  private:
    RTT::InputPort<double> _evPort;
    RTT::OutputPort<double> _outPort;
    void ChangeSum(double in);
    double Sum;
};
#endif
