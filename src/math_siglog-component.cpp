#include "math_siglog-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>
#include <fstream>

Math_siglog::Math_siglog(std::string const& name) : TaskContext(name){
  this->ports()->addEventPort( "evPort", _evPort ).doc( "Input Port that raises an event." );
  this->addAttribute( "Value", Value );
  this->addAttribute( "Filename", Filename );
  this->addOperation( "changeFilename", &Math_siglog::changeFilename, this, RTT::OwnThread)
                                   .doc("Change a parameter, return the old value.")
                                   .arg("New Value", "The new value for the parameter."); 
  Value=0;
  Filename="dat.txt";
  std::cout << "Math_siglog constructed !" <<std::endl;
}

bool Math_siglog::configureHook(){
  std::cout << "Math_siglog configured !" <<std::endl;
  return true;
}

bool Math_siglog::startHook(){
  std::cout << "Math_siglog started !" <<std::endl;
  return true;
}

void Math_siglog::updateHook(){
  double val = 0.0; 
  if ( _evPort.read(val) == RTT::NewData ) {
         // update val...
         log.push_back(val);
         Value=val;
       }
  //std::cout << "Math_siglog executes updateHook !" <<std::endl;
}

void Math_siglog::stopHook() {
  std::cout << "Math_siglog executes stopping !" <<std::endl;
}

void Math_siglog::cleanupHook() {
    std::fstream file;
    std::string path="/home/viki/"+Filename;
    file.open( path.c_str(),std::ios::out );
    if( file.good() == true )
    {
        for(int i=0;i<log.size();i++)
           {
               file<<i<<" "<<log[i]<<" "<<std::endl;
           }
        file.close();
    }
  std::cout << "Math_siglog cleaning up !" <<std::endl;
}
void Math_siglog::changeFilename(std::string in)
{
  Filename=in;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Math_siglog)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Math_siglog)
