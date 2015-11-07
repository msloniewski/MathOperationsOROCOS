#include "math_generator-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Math_generator::Math_generator(std::string const& name) : TaskContext(name){
  std::cout << "Math_generator constructed !" <<std::endl;
}

bool Math_generator::configureHook(){
  std::cout << "Math_generator configured !" <<std::endl;
  return true;
}

bool Math_generator::startHook(){
  std::cout << "Math_generator started !" <<std::endl;
  return true;
}

void Math_generator::updateHook(){
  std::cout << "Math_generator executes updateHook !" <<std::endl;
}

void Math_generator::stopHook() {
  std::cout << "Math_generator executes stopping !" <<std::endl;
}

void Math_generator::cleanupHook() {
  std::cout << "Math_generator cleaning up !" <<std::endl;
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
