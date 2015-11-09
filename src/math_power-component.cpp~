#include "math_power-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Math_power::Math_power(std::string const& name) : TaskContext(name){
  this->ports()->addEventPort( "evPort", _evPort ).doc( "Input Port that raises an event." );
  this->ports()->addPort( "outPort", _outPort ).doc( "Output Port, here write our data to." );
  std::cout << "Math_power constructed !" <<std::endl;
}

bool Math_power::configureHook(){
  std::cout << "Math_power configured !" <<std::endl;
  return true;
}

bool Math_power::startHook(){
  std::cout << "Math_power started !" <<std::endl;
  return true;
}

void Math_power::updateHook(){
  double val = 0.0; 
  if ( _evPort.read(val) == RTT::NewData ) {
         // update val...
         _outPort.write( val*val );
       }
  std::cout << "Math_power executes updateHook !" <<std::endl;
}

void Math_power::stopHook() {
  std::cout << "Math_power executes stopping !" <<std::endl;
}

void Math_power::cleanupHook() {
  std::cout << "Math_power cleaning up !" <<std::endl;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Math_power)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Math_power)
