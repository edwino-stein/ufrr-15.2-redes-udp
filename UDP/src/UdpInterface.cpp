
/*
	Edwino Stein - 1201324411
*/

/* *************************************************************** */
/* *********************** Implementação Udp ********************* */
/* *************************************************************** */

#include "../header/UdpInterface.hpp"

/* ******************* SOCKET ******************* */

bool Udp::openSocket(){

	if(this->isOpen()) return true;

	struct protoent *proto;
	proto = getprotobyname("udp");
	this->descriptor = socket(PF_INET, SOCK_DGRAM, proto->p_proto);

	return this->descriptor >= 0;
}

bool Udp::closeSocket(){

	if(!this->isOpen()) return true;

	close(this->descriptor);
	this->descriptor = (-1);

	return true;
}

bool Udp::isOpen(){
	return this->descriptor >= 0;
}


/* ******************* SETTERS ******************* */

Udp* Udp::setIp(String ip){
	this->ip = ip;
	return this;
}

Udp* Udp::setPort(int port){
	this->port = port;
	return this;
}

Udp* Udp::setBufferSize(unsigned int bufferSize){
	this->bufferSize = bufferSize;
	return this;
}

/* ******************* GETTERS ******************* */

String Udp::getIp(){
	return this->ip;
}

int Udp::getPort(){
	return this->port;
}

unsigned int Udp::getBufferSize(){
	return this->bufferSize;
}

