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

#ifndef SMARTJOYSTICKSERVER_SERONET_SDK_PORTFACTORY_HH_
#define SMARTJOYSTICKSERVER_SERONET_SDK_PORTFACTORY_HH_

// include the main component-definition class
#include "SmartJoystickServerPortFactoryInterface.hh"

#include <thread>
#include <chrono>

// include SeRoNetSDK library
#include <SeRoNetSDK/SeRoNet/Utils/Task.hpp>
#include <SeRoNetSDK/SeRoNet/Utils/Component.hpp>

class SmartJoystickServerSeRoNetSDKPortFactory: public SmartJoystickServerPortFactoryInterface
{
private:
	// internal component instance
	SeRoNet::Utils::Component *componentImpl;
	
	// component thread
	std::thread component_thread;
	
	// internal component thread method
	int task_execution();
public:
	SmartJoystickServerSeRoNetSDKPortFactory();
	virtual ~SmartJoystickServerSeRoNetSDKPortFactory();

	virtual void initialize(SmartJoystickServer *component, int argc, char* argv[]) override;
	virtual int onStartup() override;

	
	virtual Smart::IPushServerPattern<CommBasicObjects::CommJoystick> * createJoystickServcieOut(const std::string &serviceName) override;
	
	virtual int onShutdown(const std::chrono::steady_clock::duration &timeoutTime=std::chrono::seconds(2)) override;
	virtual void destroy() override;
};

#endif /* SMARTJOYSTICKSERVER_SERONET_SDK_PORTFACTORY_HH_ */
