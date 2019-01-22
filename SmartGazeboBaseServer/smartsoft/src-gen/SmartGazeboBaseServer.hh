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
#ifndef _SMARTGAZEBOBASESERVER_HH
#define _SMARTGAZEBOBASESERVER_HH

#include <map>
#include <iostream>
#include "aceSmartSoft.hh"
#include "smartQueryServerTaskTrigger_T.h"
#include "SmartGazeboBaseServerCore.hh"

#include "SmartGazeboBaseServerPortFactoryInterface.hh"
#include "SmartGazeboBaseServerExtension.hh"

// forward declarations
class SmartGazeboBaseServerPortFactoryInterface;
class SmartGazeboBaseServerExtension;

// includes for SeRoNetSDKComponentGeneratorExtension

// includes for PlainOpcUaSmartGazeboBaseServerExtension
// include plain OPC UA device clients
// include plain OPC UA status servers


// include communication objects
#include <CommBasicObjects/CommBasePositionUpdate.hh>
#include <CommBasicObjects/CommBasePositionUpdateACE.hh>
#include <CommBasicObjects/CommBaseState.hh>
#include <CommBasicObjects/CommBaseStateACE.hh>
#include <CommBasicObjects/CommMobileLaserScan.hh>
#include <CommBasicObjects/CommMobileLaserScanACE.hh>
#include <CommBasicObjects/CommNavigationVelocity.hh>
#include <CommBasicObjects/CommNavigationVelocityACE.hh>
#include <CommBasicObjects/CommVoid.hh>
#include <CommBasicObjects/CommVoidACE.hh>

// include tasks
#include "BaseStateTask.hh"
#include "LaserTask.hh"
#include "PollForGazeboConnection.hh"
// include UpcallManagers
#include "LocalizationUpdateServiceInUpcallManager.hh"
#include "NavVelServiceInUpcallManager.hh"

// include input-handler
#include "LocalizationUpdateHandler.hh"
#include "VelocityInpuHandler.hh"
// include input-handler
#include "BaseStateQueryHandler.hh"

// include handler
#include "CompHandler.hh"

#include "ParameterStateStruct.hh"
#include "ParameterUpdateHandler.hh"

#include "SmartStateChangeHandler.hh"

#define COMP SmartGazeboBaseServer::instance()

class SmartGazeboBaseServer : public SmartGazeboBaseServerCore {
private:
	static SmartGazeboBaseServer *_smartGazeboBaseServer;
	
	// constructor
	SmartGazeboBaseServer();
	
	// copy-constructor
	SmartGazeboBaseServer(const SmartGazeboBaseServer& cc);
	
	// destructor
	~SmartGazeboBaseServer() { };
	
	// load parameter from ini file
	void loadParameter(int argc, char* argv[]);
	
	// instantiate comp-handler
	CompHandler compHandler;
	
	// helper method that maps a string-name to an according TaskTriggerSubject
	Smart::TaskTriggerSubject* getInputTaskTriggerFromString(const std::string &client);
	
	// internal map storing the different port-creation factories (that internally map to specific middleware implementations)
	std::map<std::string, SmartGazeboBaseServerPortFactoryInterface*> portFactoryRegistry;
	
	// internal map storing various extensions of this component class
	std::map<std::string, SmartGazeboBaseServerExtension*> componentExtensionRegistry;
	
public:
	ParameterStateStruct getGlobalState() const
	{
		return paramHandler.getGlobalState();
	}
	
	// define tasks
	Smart::TaskTriggerSubject* baseStateTaskTrigger;
	BaseStateTask *baseStateTask;
	Smart::TaskTriggerSubject* laserTaskTrigger;
	LaserTask *laserTask;
	Smart::TaskTriggerSubject* pollForGazeboConnectionTrigger;
	PollForGazeboConnection *pollForGazeboConnection;
	
	// define input-ports
	// InputPort LocalizationUpdateServiceIn
	Smart::ISendServerPattern<CommBasicObjects::CommBasePositionUpdate> *localizationUpdateServiceIn;
	Smart::InputTaskTrigger<CommBasicObjects::CommBasePositionUpdate> *localizationUpdateServiceInInputTaskTrigger;
	LocalizationUpdateServiceInUpcallManager *localizationUpdateServiceInUpcallManager;
	// InputPort NavVelServiceIn
	Smart::ISendServerPattern<CommBasicObjects::CommNavigationVelocity> *navVelServiceIn;
	Smart::InputTaskTrigger<CommBasicObjects::CommNavigationVelocity> *navVelServiceInInputTaskTrigger;
	NavVelServiceInUpcallManager *navVelServiceInUpcallManager;
	
	// define request-ports
	
	// define input-handler
	LocalizationUpdateHandler *localizationUpdateHandler;
	VelocityInpuHandler *velocityInpuHandler;
	
	// define output-ports
	Smart::IPushServerPattern<CommBasicObjects::CommBaseState> *baseStateServiceOut;
	Smart::IPushServerPattern<CommBasicObjects::CommMobileLaserScan> *laserServiceOut;
	
	// define answer-ports
	Smart::IQueryServerPattern<CommBasicObjects::CommVoid, CommBasicObjects::CommBaseState,SmartACE::QueryId> *baseSatateQueryAnsw;
	Smart::QueryServerTaskTrigger<CommBasicObjects::CommVoid, CommBasicObjects::CommBaseState,SmartACE::QueryId> *baseSatateQueryAnswInputTaskTrigger;
	
	// define request-handlers
	BaseStateQueryHandler *baseStateQueryHandler;
	
	// definitions of SeRoNetSDKComponentGeneratorExtension
	
	// definitions of PlainOpcUaSmartGazeboBaseServerExtension
	
	
	// define default slave ports
	SmartACE::StateSlave *stateSlave;
	SmartStateChangeHandler *stateChangeHandler;
	SmartACE::WiringSlave *wiringSlave;
	ParamUpdateHandler paramHandler;
	SmartACE::ParameterSlave *param;
	
	
	/// this method is used to register different PortFactory classes (one for each supported middleware framework)
	void addPortFactory(const std::string &name, SmartGazeboBaseServerPortFactoryInterface *portFactory);
	
	/// this method is used to register different component-extension classes
	void addExtension(SmartGazeboBaseServerExtension *extension);
	
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
	static SmartGazeboBaseServer* instance()
	{
		if(_smartGazeboBaseServer == 0) {
			_smartGazeboBaseServer = new SmartGazeboBaseServer();
		}
		return _smartGazeboBaseServer;
	}
	
	static void deleteInstance() {
		if(_smartGazeboBaseServer != 0) {
			delete _smartGazeboBaseServer;
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
		struct BaseStateTask_struct {
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
		} baseStateTask;
		struct LaserTask_struct {
			// scheduling parameters
			std::string scheduler;
			int priority;
			int cpuAffinity;
		} laserTask;
		struct PollForGazeboConnection_struct {
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
		} pollForGazeboConnection;
		
		//--- upcall parameter ---
		struct LocalizationUpdateHandler_struct {
			int prescale;
		} localizationUpdateHandler;
		struct VelocityInpuHandler_struct {
			int prescale;
		} velocityInpuHandler;
		
		//--- server port parameter ---
		struct BaseSatateQueryAnsw_struct {
				std::string serviceName;
				std::string roboticMiddleware;
		} baseSatateQueryAnsw;
		struct BaseStateServiceOut_struct {
				std::string serviceName;
				std::string roboticMiddleware;
		} baseStateServiceOut;
		struct LaserServiceOut_struct {
				std::string serviceName;
				std::string roboticMiddleware;
		} laserServiceOut;
		struct LocalizationUpdateServiceIn_struct {
				std::string serviceName;
				std::string roboticMiddleware;
		} localizationUpdateServiceIn;
		struct NavVelServiceIn_struct {
				std::string serviceName;
				std::string roboticMiddleware;
		} navVelServiceIn;
	
		//--- client port parameter ---
		
		// -- parameters for SeRoNetSDKComponentGeneratorExtension
		
		// -- parameters for PlainOpcUaSmartGazeboBaseServerExtension
		
	} connections;
};
#endif
