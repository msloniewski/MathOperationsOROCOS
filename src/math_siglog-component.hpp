#ifndef OROCOS_MATH_SIGLOG_COMPONENT_HPP
#define OROCOS_MATH_SIGLOG_COMPONENT_HPP

#include <rtt/RTT.hpp>
#include <vector>
#include <string>
class Math_siglog : public RTT::TaskContext{
  public:
    Math_siglog(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
  private:
    RTT::InputPort<double> _evPort;
    double Value;
    std::vector<double> log;
    std::string Filename;
    void changeFilename(std::string in);
};
#endif
