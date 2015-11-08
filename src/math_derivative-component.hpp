#ifndef OROCOS_MATH_DERIVATIVE_COMPONENT_HPP
#define OROCOS_MATH_DERIVATIVE_COMPONENT_HPP

#include <rtt/RTT.hpp>
#include <rtt/os/TimeService.hpp>
#include <rtt/Time.hpp>

class Math_derivative : public RTT::TaskContext{
  public:
    Math_derivative(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
  private:
    RTT::OutputPort<double> _outPort;
    RTT::InputPort<double> _evPort;
    RTT::os::TimeService::ticks LastMoment;
    double LastValue;
};
#endif
