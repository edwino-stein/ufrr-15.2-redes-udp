#if !defined  _UDP_SERVER
#define _UDP_SERVER

#include "UdpInterface.hpp"

class UdpServer : public Udp{

	protected:

		struct sockaddr_in serverAddress;
		struct sockaddr_in *clientAddress;

		void updateAddress();

	public:

		UdpServer();

		UdpServer(String ip, int port, unsigned int bufferSize = 1024);

		~UdpServer();

		bool bind();

		bool send(String message);

		bool recieve(String &response);

		UdpServer* setIp(String ip);

		UdpServer* setPort(int port);

		UdpServer* setBufferSize(unsigned int bufferSize);
};

#endif