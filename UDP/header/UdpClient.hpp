#if !defined  _UDP_CLIENT
#define _UDP_CLIENT

#include "UdpInterface.hpp"

class UdpClient : public Udp{

	protected:

		struct sockaddr_in address;
		void updateAddress();

	public:

		UdpClient();

		UdpClient(String ip, int port, unsigned int bufferSize = 1024);

		~UdpClient();

		bool send(String message);

		bool recieve(String &response);

		UdpClient* setIp(String ip);

		UdpClient* setPort(int port);

		UdpClient* setBufferSize(unsigned int bufferSize);
};

#endif