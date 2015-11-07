#ifndef OROCOS_MATH_GENERATOR_COMPONENT_HPP
#define OROCOS_MATH_GENERATOR_COMPONENT_HPP

#include <rtt/RTT.hpp>
#include <rtt/os/TimeService.hpp>
#include <rtt/Time.hpp>

class Math_generator : public RTT::TaskContext{
  public:
    Math_generator(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
  private:
    RTT::OutputPort<double> _outPort;
    double Omega;
    double Phase;
    RTT::os::TimeService::ticks FirstMoment;
    double MakeSine();
};
#endif
