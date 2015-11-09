#include "math_amplification-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Math_amplification::Math_amplification(std::string const& name) : TaskContext(name){
  this->ports()->addEventPort( "evPort", _evPort ).doc( "Input Port that raises an event." );
  this->ports()->addPort( "outPort", _outPort ).doc( "Output Port, here write our data to." );
  this->addOperation( "changeParameter", &Math_amplification::ChangeCoefficient, this, RTT::OwnThread)
                                   .doc("Change a parameter, return the old value.")
                                   .arg("New Value", "The new value for the parameter."); 
  this->addAttribute( "Value", k );
  k=1;
  std::cout << "Math_amplification constructed !" <<std::endl;
}

bool Math_amplification::configureHook(){
  std::cout << "Math_amplification configured !" <<std::endl;
  return true;
}

bool Math_amplification::startHook(){
  std::cout << "Math_amplification started !" <<std::endl;
  return true;
}

void Math_amplification::updateHook(){
  double val = 0.0; 
  if ( _evPort.read(val) == RTT::NewData ) {
         // update val...
         _outPort.write( k*val );
       }
  //std::cout << "Math_amplification executes updateHook !" <<std::endl;
}

void Math_amplification::stopHook() {
  std::cout << "Math_amplification executes stopping !" <<std::endl;
}

void Math_amplification::cleanupHook() {
  std::cout << "Math_amplification cleaning up !" <<std::endl;
}

void Math_amplification::ChangeCoefficient(double in) {
  k=in;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Math_amplification)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Math_amplification)
