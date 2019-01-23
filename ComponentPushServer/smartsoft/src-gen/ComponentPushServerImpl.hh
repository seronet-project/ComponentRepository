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
#ifndef _COMPONENTPUSHSERVERIMPL_HH
#define _COMPONENTPUSHSERVERIMPL_HH

#include <chrono>
#include "aceSmartSoft.hh"

class ComponentPushServerImpl : public SmartACE::SmartComponent {
public:
	ComponentPushServerImpl(const std::string &componentName, int & argc, char ** argv);
	ComponentPushServerImpl(const std::string &componentName, int & argc, char ** argv, const ACE_Sched_Params &sched_params);
	virtual ~ComponentPushServerImpl();

	int startComponentInfrastructure();
	void stopComponentInfrastructure(const std::chrono::steady_clock::duration &timeoutTime=std::chrono::seconds(2));
	void cleanUpComponentResources();
};

#endif
