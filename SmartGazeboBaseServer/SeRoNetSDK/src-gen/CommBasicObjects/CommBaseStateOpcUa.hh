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

#include "CommBasicObjects/CommBaseState.hh"

#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescription.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#pragma once

#include "CommBasicObjects/CommTimeStampOpcUa.hh"
#include "CommBasicObjects/CommBasePoseOpcUa.hh"
#include "CommBasicObjects/CommBasePoseOpcUa.hh"
#include "CommBasicObjects/CommBaseVelocityOpcUa.hh"
#include "CommBasicObjects/CommBaseVelocityOpcUa.hh"
#include "CommBasicObjects/CommBatteryLevelOpcUa.hh"

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommBasicObjectsIDL::CommBaseState
template <>
inline IDescription::shp_t SelfDescription(CommBasicObjectsIDL::CommBaseState *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add timeStamp
	ret->add(
		SelfDescription(&(obj->timeStamp), "TimeStamp")
	);
	// add basePose
	ret->add(
		SelfDescription(&(obj->basePose), "BasePose")
	);
	// add baseOdomPose
	ret->add(
		SelfDescription(&(obj->baseOdomPose), "BaseOdomPose")
	);
	// add baseVelocity
	ret->add(
		SelfDescription(&(obj->baseVelocity), "BaseVelocity")
	);
	// add baseOdomVelocity
	ret->add(
		SelfDescription(&(obj->baseOdomVelocity), "BaseOdomVelocity")
	);
	// add batteryState
	ret->add(
		SelfDescription(&(obj->batteryState), "BatteryState")
	);
	return ret;
} // end SelfDescription


// serialization for CommBaseState
template <>
inline IDescription::shp_t SelfDescription(CommBasicObjects::CommBaseState *obj, std::string name)
{
	return SelfDescription(&(obj->set()),name); 
} // end SelfDescription


} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
