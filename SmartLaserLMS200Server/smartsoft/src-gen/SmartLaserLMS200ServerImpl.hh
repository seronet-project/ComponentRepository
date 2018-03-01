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
#ifndef _SMARTLASERLMS200SERVERIMPL_HH
#define _SMARTLASERLMS200SERVERIMPL_HH

#include "aceSmartSoft.hh"

class SmartLaserLMS200ServerImpl : public SmartACE::SmartComponent {
public:
	SmartLaserLMS200ServerImpl(const std::string &componentName, int & argc, char ** argv);
	SmartLaserLMS200ServerImpl(const std::string &componentName, int & argc, char ** argv, const ACE_Sched_Params &sched_params);
	virtual ~SmartLaserLMS200ServerImpl();

	Smart::StatusCode run(void);
	void closeAllAssociatedTasks(const int &taskShutdownTimeLimit);
	void cleanUpComponentResources();
};

#endif