#ifndef OROCOS_MATH_SUM_COMPONENT_HPP
#define OROCOS_MATH_SUM_COMPONENT_HPP

#include <rtt/RTT.hpp>

class Math_sum : public RTT::TaskContext{
  public:
    Math_sum(std::string const& name);
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
