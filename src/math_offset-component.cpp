#include "math_offset-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Math_offset::Math_offset(std::string const& name) : TaskContext(name){
  this->ports()->addEventPort( "evPort", _evPort ).doc( "Input Port that raises an event." );
  this->ports()->addPort( "outPort", _outPort ).doc( "Output Port, here write our data to." );
  this->addOperation( "changeParameter", &Math_offset::ChangeOffset, this, RTT::OwnThread)
                                   .doc("Change a parameter, return the old value.")
                                   .arg("New Value", "The new value for the parameter."); 
  this->addAttribute( "Value", a);
  a=0;
  std::cout << "Math_offset constructed !" <<std::endl;
}

bool Math_offset::configureHook(){
  std::cout << "Math_offset configured !" <<std::endl;
  return true;
}

bool Math_offset::startHook(){
  std::cout << "Math_offset started !" <<std::endl;
  return true;
}

void Math_offset::updateHook(){
  double val = 0.0; 
  if ( _evPort.read(val) == RTT::NewData ) {
         // update val...
         _outPort.write( val+a );
       }
  std::cout << "Math_offset executes updateHook !" <<std::endl;
}

void Math_offset::stopHook() {
  std::cout << "Math_offset executes stopping !" <<std::endl;
}

void Math_offset::cleanupHook() {
  std::cout << "Math_offset cleaning up !" <<std::endl;
}
void Math_offset::ChangeOffset(double in) {
  a=in;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Math_offset)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Math_offset)
