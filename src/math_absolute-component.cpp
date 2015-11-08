#include "math_absolute-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Math_absolute::Math_absolute(std::string const& name) : TaskContext(name){
  this->ports()->addEventPort( "evPort", _evPort ).doc( "Input Port that raises an event." );
  this->ports()->addPort( "outPort", _outPort ).doc( "Output Port, here write our data to." );
  
  std::cout << "Math_absolute constructed !" <<std::endl;
}

bool Math_absolute::configureHook(){
  std::cout << "Math_absolute configured !" <<std::endl;
  return true;
}

bool Math_absolute::startHook(){
  std::cout << "Math_absolute started !" <<std::endl;
  return true;
}

void Math_absolute::updateHook(){
  double val = 0.0; 
  if ( _evPort.read(val) == RTT::NewData ) {
         // update val...
         _outPort.write( this->absolute(val) );
       }
  //std::cout << "Math_absolute executes updateHook !" <<std::endl;
}

void Math_absolute::stopHook() {
  std::cout << "Math_absolute executes stopping !" <<std::endl;
}

void Math_absolute::cleanupHook() {
  std::cout << "Math_absolute cleaning up !" <<std::endl;
}
double Math_absolute::absolute(double _in) {
  if (_in<0)
	return -1*_in;
  else
	return _in;
}
/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Math_absolute)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Math_absolute)
