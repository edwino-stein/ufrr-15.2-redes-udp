#if !defined  _UDP_INTERFACE
#define _UDP_INTERFACE

#include "../../Common/Common.hpp"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>


class Udp : public Object{

	protected:

		String ip;
		unsigned int port;
		unsigned int bufferSize;
		int descriptor;

		static socklen_t getSockAddrInSize();

		static struct sockaddr_in *getAddress();

	public:

		Udp();

		Udp(String ip, unsigned int port, unsigned int bufferSize);

		virtual ~Udp();

		virtual bool send(String message)=0;

		virtual bool recieve(String &response)=0;

		virtual bool openSocket();

		virtual bool closeSocket();

		virtual bool isOpen();

		virtual Udp* setIp(String ip);

		virtual String getIp();

		virtual Udp* setPort(unsigned int port);

		virtual unsigned int getPort();

		virtual Udp* setBufferSize(unsigned int bufferSize);

		virtual unsigned int getBufferSize();
};

#endif