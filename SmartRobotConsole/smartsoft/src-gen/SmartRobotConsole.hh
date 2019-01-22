//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain
// The SmartSoft Toolchain has been developed by:
//  
// Service Robotics Research Center
// University of Applied Sciences Ulm
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// www.servicerobotik-ulm.de
//
// Please do not modify this file. It will be re-generated
// running the code generator.
//--------------------------------------------------------------------------
#ifndef _SMARTROBOTCONSOLE_HH
#define _SMARTROBOTCONSOLE_HH

#include <map>
#include <iostream>
#include "aceSmartSoft.hh"
#include "smartQueryServerTaskTrigger_T.h"
#include "SmartRobotConsoleCore.hh"

#include "SmartRobotConsolePortFactoryInterface.hh"
#include "SmartRobotConsoleExtension.hh"

// forward declarations
class SmartRobotConsolePortFactoryInterface;
class SmartRobotConsoleExtension;

// includes for SeRoNetSDKComponentGeneratorExtension

// includes for PlainOpcUaSmartRobotConsoleExtension
// include plain OPC UA device clients
// include plain OPC UA status servers


// include communication objects

// include tasks
#include "ConsoleTask.hh"
// include UpcallManagers

// include input-handler
// include input-handler

// include handler
#include "CompHandler.hh"


#include "SmartStateChangeHandler.hh"

#define COMP SmartRobotConsole::instance()

class SmartRobotConsole : public SmartRobotConsoleCore {
private:
	static SmartRobotConsole *_smartRobotConsole;
	
	// constructor
	SmartRobotConsole();
	
	// copy-constructor
	SmartRobotConsole(const SmartRobotConsole& cc);
	
	// destructor
	~SmartRobotConsole() { };
	
	// load parameter from ini file
	void loadParameter(int argc, char* argv[]);
	
	// instantiate comp-handler
	CompHandler compHandler;
	
	// helper method that maps a string-name to an according TaskTriggerSubject
	Smart::TaskTriggerSubject* getInputTaskTriggerFromString(const std::string &client);
	
	// internal map storing the different port-creation factories (that internally map to specific middleware implementations)
	std::map<std::string, SmartRobotConsolePortFactoryInterface*> portFactoryRegistry;
	
	// internal map storing various extensions of this component class
	std::map<std::string, SmartRobotConsoleExtension*> componentExtensionRegistry;
	
public:
	
	// define tasks
	Smart::TaskTriggerSubject* consoleTaskTrigger;
	ConsoleTask *consoleTask;
	
	// define input-ports
	
	// define request-ports
	
	// define input-handler
	
	// define output-ports
	
	// define answer-ports
	
	// define request-handlers
	
	// definitions of SeRoNetSDKComponentGeneratorExtension
	
	// definitions of PlainOpcUaSmartRobotConsoleExtension
	
	
	// define default slave ports
	SmartACE::StateSlave *stateSlave;
	SmartStateChangeHandler *stateChangeHandler;
	SmartACE::WiringSlave *wiringSlave;
	
	// define master ports
	SmartACE::StateMaster *stateMaster;
	SmartACE::ParameterMaster *paramMaster;
	SmartACE::WiringMaster *wiringMaster;
	
	/// this method is used to register different PortFactory classes (one for each supported middleware framework)
	void addPortFactory(const std::string &name, SmartRobotConsolePortFactoryInterface *portFactory);
	
	/// this method is used to register different component-extension classes
	void addExtension(SmartRobotConsoleExtension *extension);
	
	/// this method allows to access the registered component-extensions (automatically converting to the actuall implementation type)
	template <typename T>
	T* getExtension(const std::string &name) {
		auto it = componentExtensionRegistry.find(name);
		if(it != componentExtensionRegistry.end()) {
			return dynamic_cast<T*>(it->second);
		}
		return 0;
	}
	
	/// initialize component's internal members
	void init(int argc, char *argv[]);
	
	/// execute the component's infrastructure
	void run();
	
	/// clean-up component's resources
	void fini();
	
	/// call this method to set the overall component into the Alive state (i.e. component is then ready to operate)
	void setStartupFinished();
	
	/// connect all component's client ports
	Smart::StatusCode connectAndStartAllServices();
	
	/// start all assocuated Activities
	void startAllTasks();
	
	/// start all associated timers
	void startAllTimers();
	

	// return singleton instance
	static SmartRobotConsole* instance()
	{
		if(_smartRobotConsole == 0) {
			_smartRobotConsole = new SmartRobotConsole();
		}
		return _smartRobotConsole;
	}
	
	static void deleteInstance() {
		if(_smartRobotConsole != 0) {
			delete _smartRobotConsole;
		}
	}
	
	// connections parameter
	struct connections_struct
	{
		// component struct
		struct component_struct
		{
			// the name of the component
			std::string name;
			std::string initialComponentMode;
			std::string defaultScheduler;
			bool useLogger;
		} component;
		
		//--- task parameter ---
		struct ConsoleTask_struct {
			double minActFreq;
			double maxActFreq;
			std::string trigger;
			// only one of the following two params is 
			// actually used at run-time according 
			// to the system config model
			double periodicActFreq;
			// or
			std::string inPortRef;
			int prescale;
			// scheduling parameters
			std::string scheduler;
			int priority;
			int cpuAffinity;
		} consoleTask;
		
		//--- upcall parameter ---
		
		//--- server port parameter ---
	
		//--- client port parameter ---
		
		// -- parameters for SeRoNetSDKComponentGeneratorExtension
		
		// -- parameters for PlainOpcUaSmartRobotConsoleExtension
		
	} connections;
};
#endif
