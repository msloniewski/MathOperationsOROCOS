#include "math_integration-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Math_integration::Math_integration(std::string const& name) : TaskContext(name){
  this->ports()->addEventPort( "evPort", _evPort ).doc( "Input Port that raises an event." );
  this->ports()->addPort( "outPort", _outPort ).doc( "Output Port, here write our data to." );
  this->addOperation( "changeSum", &Math_integration::ChangeSum, this, RTT::OwnThread)
                                   .doc("Change a parameter, return the old value.")
                                   .arg("New Value", "The new value for the parameter."); 
  this->addAttribute( "Value", Sum );
  Sum=0;
  std::cout << "Math_integration constructed !" <<std::endl;
}

bool Math_integration::configureHook(){
  std::cout << "Math_integration configured !" <<std::endl;
  return true;
}

bool Math_integration::startHook(){
  std::cout << "Math_integration started !" <<std::endl;
  return true;
}

void Math_integration::updateHook(){
  double val = 0.0; 
  if ( _evPort.read(val) == RTT::NewData ) {
         // update val...
         Sum+=val;
         _outPort.write(Sum);
       }
  std::cout << "Math_integration executes updateHook !" <<std::endl;
}

void Math_integration::stopHook() {
  std::cout << "Math_integration executes stopping !" <<std::endl;
}

void Math_integration::cleanupHook() {
  std::cout << "Math_integration cleaning up !" <<std::endl;
}
void Math_integration::ChangeSum(double in) {
  Sum=in;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Math_integration)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Math_integration)
