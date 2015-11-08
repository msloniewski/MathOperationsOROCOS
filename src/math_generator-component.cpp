#include "math_generator-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>
#include <cmath>

Math_generator::Math_generator(std::string const& name) : TaskContext(name){
  Omega=0;
  Phase=0;
  this->ports()->addPort( "outPort", _outPort ).doc( "Output Port, here write our data to." );
  this->addOperation( "changeFrequency", &Math_generator::ChangeFrequency, this, RTT::OwnThread)
                                   .doc("Change a parameter, return the old value.")
                                   .arg("New Value", "The new value for the parameter."); 
  this->addOperation( "changePhase", &Math_generator::ChangePhase, this, RTT::OwnThread)
                                   .doc("Change a parameter, return the old value.")
                                   .arg("New Value", "The new value for the parameter."); 
  this->addAttribute( "Omega", Omega );
  this->addAttribute( "Phase", Phase );
  std::cout << "Math_generator constructed !" <<std::endl;
}

bool Math_generator::configureHook(){
  // Set component activitiy
  if(setActivity(new RTT::Activity(ORO_SCHED_RT,
                 1,//_priority,
                 0.01,//_period,
                 1,//_cpu_affinity,
                 0,
                 getName())) == false){
    std::cout << "Unable to set activity!" << std::endl;
    return false;
  }
  std::cout << "Math_generator configured !" <<std::endl;
  return true;
}

bool Math_generator::startHook(){
  FirstMoment= RTT::os::TimeService::Instance()->getTicks();
  std::cout << "Math_generator started !" <<std::endl;
  return true;
}

void Math_generator::updateHook(){
  _outPort.write( this->MakeSine() );
  //std::cout << "Math_generator executes updateHook !" <<std::endl;
}

void Math_generator::stopHook() {
  std::cout << "Math_generator executes stopping !" <<std::endl;
}

void Math_generator::cleanupHook() {
  std::cout << "Math_generator cleaning up !" <<std::endl;
}

double Math_generator::MakeSine()
{
  return sin(Omega*RTT::os::TimeService::Instance()->secondsSince(FirstMoment) + Phase);
} 
void Math_generator::ChangeFrequency(double in)
{
  Omega=in;
} 
void Math_generator::ChangePhase(double in)
{
  Phase=in;
} 

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Math_generator)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Math_generator)
