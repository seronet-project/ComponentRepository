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
// This file is generated once. Modify this file to your needs. 
// If you want the toolchain to re-generate this file, please 
// delete it before running the code generator.
//--------------------------------------------------------------------------
#include "RobotBlockedEventServerEventTestHandler.hh"

bool RobotBlockedEventServerEventTestHandler::testEvent(
	CommNavigationObjects::CommCdlRobotBlockedEventParameter &p,
	CommNavigationObjects::CommCdlRobotBlockedEventResult &r,
	const CommNavigationObjects::CommCdlRobotBlockedState &s
) throw() {
	bool result = false;

	CommNavigationObjects::CdlRobotBlockEventType oldState, newState;

	oldState = p.getOldState();
	newState = s.getNewState();
	if ((oldState!=newState))
	{
		p.setOldState(newState);
		r.setState(newState);
		std::cout<<"Event Testhandel true!"<<std::endl;
		result = true;
	}
	else
	{
		//  p.set(newState);
		result = false;
	}

	return result;
}