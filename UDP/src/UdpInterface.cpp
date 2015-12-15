
/*
	Edwino Stein - 1201324411
*/

/* *************************************************************** */
/* *********************** Implementação Udp ********************* */
/* *************************************************************** */

#include "../header/UdpInterface.hpp"

/* ******************* CONSTRUTORES ******************* */

Udp::Udp(){
	this->descriptor = (-1);
}

Udp::Udp(String ip, unsigned int port, unsigned int bufferSize){
	this->Udp();

	this->setIp(ip)
		->setPort(port)
		->setBufferSize(bufferSize);
}

/* ******************* ESTATICOS ******************* */


socklen_t Udp::getSockAddrInSize(){
	return sizeof(struct sockaddr_in);
}

struct sockaddr_in *Udp::getAddress(){

	sockaddr_in * addr = new sockaddr_in();
	memset(addr, 0, sizeof(*addr));

	return addr;
}

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

	close(this->socketOpened);
	this->descriptor = (-1);
}

bool Udp::isOpen(){
	return this->descriptor >= 0;
}


/* ******************* SETTERS ******************* */

Udp* Udp::setIp(String ip){
	this->ip = ip;
	return this;
}

Udp* Udp::setPort(unsigned int port){
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

unsigned int Udp::getPort(){
	return this->port;
}

unsigned int Udp::getBufferSize(){
	return this->bufferSize;
}

