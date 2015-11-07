#include "math_amplification-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Math_amplification::Math_amplification(std::string const& name) : TaskContext(name){
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
  std::cout << "Math_amplification executes updateHook !" <<std::endl;
}

void Math_amplification::stopHook() {
  std::cout << "Math_amplification executes stopping !" <<std::endl;
}

void Math_amplification::cleanupHook() {
  std::cout << "Math_amplification cleaning up !" <<std::endl;
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
