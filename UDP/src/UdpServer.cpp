
/*
	Edwino Stein - 1201324411
*/

/* *************************************************************** */
/* ******************** Implementação UdpServer ****************** */
/* *************************************************************** */

#include "../header/UdpServer.hpp"

/* ******************* CONSTRUTORES ******************* */

UdpServer::UdpServer(){
	this->descriptor = (-1);
}

UdpServer::UdpServer(String ip, int port, unsigned int bufferSize){

	this->descriptor = (-1);

	this->setIp(ip)
		->setPort(port)
		->setBufferSize(bufferSize);

	this->updateAddress();
	memset(&this->clientAddress, 0, sizeof(struct sockaddr_in));
}

UdpServer::~UdpServer(){
	this->closeSocket();
}

void UdpServer::updateAddress(){
	memset(&this->serverAddress, 0, sizeof(this->serverAddress));
	this->serverAddress.sin_addr.s_addr = inet_addr(this->ip.c_str());
	this->serverAddress.sin_port = htons(this->port);
	this->serverAddress.sin_family = AF_INET;
}

/* ******************* OPERAÇÕES ******************* */

bool UdpServer::send(String message){

	ssize_t result = (-1);
	this->updateAddress();
	this->openSocket();

	result = sendto(
		this->descriptor,
		message.c_str(),
		message.length(),
		0,
		(const struct sockaddr *) &this->clientAddress,
		sizeof(struct sockaddr_in)
	);

	return result >= 0;
}

bool UdpServer::recieve(String &response){

	ssize_t result = (-1);
	char *buffer = new char[this->bufferSize];
	this->updateAddress();
	this->openSocket();

	socklen_t sizeAddress = sizeof(struct sockaddr_in);
	
	result = recvfrom(
		this->descriptor,
		buffer,
		this->bufferSize,
		0,
		(struct sockaddr *) &this->clientAddress,
		&sizeAddress
	);

	if(result < 0){
		delete [] buffer;
		return false;
	}
	
	response.clear();
	response.append(buffer);
	delete [] buffer;

	return true;
}

bool UdpServer::bind(){

	ssize_t result = (-1);
	this->openSocket();

	result = ::bind(
		this->descriptor,
		(const struct sockaddr *) &this->serverAddress,
		sizeof(struct sockaddr_in)
	);

	return result >= 0;
}


/* ******************* SETTERS ******************* */

UdpServer* UdpServer::setIp(String ip){
	return (UdpServer *) Udp::setIp(ip);
}

UdpServer* UdpServer::setPort(int port){
	return (UdpServer *) Udp::setPort(port);
}

UdpServer* UdpServer::setBufferSize(unsigned int bufferSize){
	return (UdpServer *) Udp::setBufferSize(bufferSize);
}

/* ******************* GETTERS ******************* */

String UdpServer::getClientIp(){
	
	char buffer[INET_ADDRSTRLEN];
	inet_ntop(AF_INET, &this->clientAddress, buffer, INET_ADDRSTRLEN);
	String ip(buffer);

	return ip;
}
		
int UdpServer::getClientPort(){
	return ntohs(this->clientAddress.sin_port);
}