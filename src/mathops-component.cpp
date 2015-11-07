#include "mathops-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Mathops::Mathops(std::string const& name) : TaskContext(name){
  std::cout << "Mathops constructed !" <<std::endl;
}

bool Mathops::configureHook(){
  std::cout << "Mathops configured !" <<std::endl;
  return true;
}

bool Mathops::startHook(){
  std::cout << "Mathops started !" <<std::endl;
  return true;
}

void Mathops::updateHook(){
  std::cout << "Mathops executes updateHook !" <<std::endl;
}

void Mathops::stopHook() {
  std::cout << "Mathops executes stopping !" <<std::endl;
}

void Mathops::cleanupHook() {
  std::cout << "Mathops cleaning up !" <<std::endl;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Mathops)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Mathops)
