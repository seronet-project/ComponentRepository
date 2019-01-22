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

#ifndef COMPONENTTTSCLIENT_PORTFACTORYINTERFACE_HH_
#define COMPONENTTTSCLIENT_PORTFACTORYINTERFACE_HH_

// include communication objects
#include <CommBasicObjects/CommPropertySet.hh>
#include <CommBasicObjects/CommPropertySetACE.hh>
#include <DomainSpeech/CommSpeechOutputMessage.hh>
#include <DomainSpeech/CommSpeechOutputMessageACE.hh>

#include <chrono>

// include component's main class
#include "ComponentTTSClient.hh"

// forward declaration
class ComponentTTSClient;

class ComponentTTSClientPortFactoryInterface {
public:
	ComponentTTSClientPortFactoryInterface() { };
	virtual ~ComponentTTSClientPortFactoryInterface() { };

	virtual void initialize(ComponentTTSClient *component, int argc, char* argv[]) = 0;
	virtual int onStartup() = 0;

	virtual Smart::IQueryClientPattern<DomainSpeech::CommSpeechOutputMessage, CommBasicObjects::CommPropertySet,SmartACE::QueryId> * createSpeechQueryServiceReq() = 0;
	virtual Smart::ISendClientPattern<DomainSpeech::CommSpeechOutputMessage> * createSpeechSendServiceOut() = 0;
	

	virtual int onShutdown(const std::chrono::steady_clock::duration &timeoutTime=std::chrono::seconds(2)) = 0;
	virtual void destroy() = 0;
};

#endif /* COMPONENTTTSCLIENT_PORTFACTORYINTERFACE_HH_ */
