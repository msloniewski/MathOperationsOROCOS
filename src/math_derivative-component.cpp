#include "math_derivative-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Math_derivative::Math_derivative(std::string const& name) : TaskContext(name){
  std::cout << "Math_derivative constructed !" <<std::endl;
}

bool Math_derivative::configureHook(){
  std::cout << "Math_derivative configured !" <<std::endl;
  return true;
}

bool Math_derivative::startHook(){
  std::cout << "Math_derivative started !" <<std::endl;
  return true;
}

void Math_derivative::updateHook(){
  std::cout << "Math_derivative executes updateHook !" <<std::endl;
}

void Math_derivative::stopHook() {
  std::cout << "Math_derivative executes stopping !" <<std::endl;
}

void Math_derivative::cleanupHook() {
  std::cout << "Math_derivative cleaning up !" <<std::endl;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Math_derivative)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Math_derivative)
