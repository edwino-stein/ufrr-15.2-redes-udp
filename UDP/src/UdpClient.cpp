
/*
	Edwino Stein - 1201324411
*/

/* *************************************************************** */
/* ******************** Implementação UdpClient ****************** */
/* *************************************************************** */

#include "../header/UdpClient.hpp"

/* ******************* CONSTRUTORES ******************* */

UdpClient::UdpClient(){
	this->descriptor = (-1);
}

UdpClient::UdpClient(String ip, int port, unsigned int bufferSize){

	this->descriptor = (-1);
	
	this->setIp(ip)
		->setPort(port)
		->setBufferSize(bufferSize);

	this->updateAddress();
}

UdpClient::~UdpClient(){
	this->closeSocket();
}

void UdpClient::updateAddress(){
	memset(&this->address, 0, sizeof(this->address));
	this->address.sin_addr.s_addr = inet_addr(this->ip.c_str());
	this->address.sin_port = htons(this->port);
	this->address.sin_family = AF_INET;
}

/* ******************* OPERAÇÕES ******************* */

bool UdpClient::send(String message){

	ssize_t result = (-1);
	this->updateAddress();
	this->openSocket();

	result = sendto(
		this->descriptor,
		message.c_str(),
		message.length(),
		0,
		(const struct sockaddr *) &this->address,
		sizeof(sockaddr_in)
	);

	return result >= 0;
}

bool UdpClient::recieve(String &response){

	ssize_t result = (-1);
	char *buffer = new char[this->bufferSize];
	memset(buffer, 0, this->bufferSize);

	this->updateAddress();
	this->openSocket();

	result = recvfrom(
		this->descriptor,
		buffer,
		this->bufferSize,
		0,
		NULL,
		NULL
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


/* ******************* SETTERS ******************* */

UdpClient* UdpClient::setIp(String ip){
	return (UdpClient *) Udp::setIp(ip);
}

UdpClient* UdpClient::setPort(int port){
	return (UdpClient *) Udp::setPort(port);
}

UdpClient* UdpClient::setBufferSize(unsigned int bufferSize){
	return (UdpClient *) Udp::setBufferSize(bufferSize);
}