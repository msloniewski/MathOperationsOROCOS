#include "math_offset-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Math_offset::Math_offset(std::string const& name) : TaskContext(name){
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
  std::cout << "Math_offset executes updateHook !" <<std::endl;
}

void Math_offset::stopHook() {
  std::cout << "Math_offset executes stopping !" <<std::endl;
}

void Math_offset::cleanupHook() {
  std::cout << "Math_offset cleaning up !" <<std::endl;
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
