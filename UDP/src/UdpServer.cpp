
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
	this->clientAddress = NULL;
}

UdpServer::UdpServer(String ip, int port, unsigned int bufferSize){

	UdpServer();

	this->setIp(ip)
		->setPort(port)
		->setBufferSize(bufferSize);

	this->updateAddress();
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

	if(this->clientAddress == NULL) return false;

	ssize_t result = (-1);
	this->updateAddress();
	this->openSocket();

	result = sendto(
		this->descriptor,
		message.c_str(),
		message.length(),
		0,
		(const struct sockaddr *) this->clientAddress,
		sizeof(*this->clientAddress)
	);

	return result >= 0;
}

bool UdpServer::recieve(String &response){

	ssize_t result = (-1);
	char *buffer = new char[this->bufferSize];
	this->updateAddress();
	this->openSocket();

	if(this->clientAddress == NULL){
		this->clientAddress = new struct sockaddr_in();
		memset(this->clientAddress, 0, sizeof(*this->clientAddress));
	}

	socklen_t sizeAddress = sizeof(struct sockaddr);
	
	result = recvfrom(
		this->descriptor,
		buffer,
		this->bufferSize,
		0,
		(struct sockaddr *) this->clientAddress,
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