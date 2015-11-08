#include "math_sum-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Math_sum::Math_sum(std::string const& name) : TaskContext(name){
  this->ports()->addEventPort( "evPort1", _evPort1 ).doc( "Input Port that raises an event." );
  this->ports()->addPort( "evPort2", _evPort2 ).doc( "Input Port that raises an event." );
  this->ports()->addPort( "outPort", _outPort ).doc( "Output Port, here write our data to." );
  std::cout << "Math_sum constructed !" <<std::endl;
}

bool Math_sum::configureHook(){
  std::cout << "Math_sum configured !" <<std::endl;
  return true;
}

bool Math_sum::startHook(){
  std::cout << "Math_sum started !" <<std::endl;
  return true;
}

void Math_sum::updateHook(){
  double val1 = 0.0; 
  double val2 = 0.0;
  _evPort1.read(val1);
  _evPort2.read(val2);
         // update val...
  _outPort.write( val1+val2 );
  std::cout << "Math_sum executes updateHook !" <<std::endl;
}

void Math_sum::stopHook() {
  std::cout << "Math_sum executes stopping !" <<std::endl;
}

void Math_sum::cleanupHook() {
  std::cout << "Math_sum cleaning up !" <<std::endl;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Math_sum)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Math_sum)
