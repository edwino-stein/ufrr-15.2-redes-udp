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
		int port;
		unsigned int bufferSize;
		int descriptor;

		virtual void updateAddress()=0;

	public:

		virtual bool send(String message)=0;

		virtual bool recieve(String &response)=0;

		bool openSocket();

		bool closeSocket();

		bool isOpen();

		virtual Udp* setIp(String ip);

		virtual String getIp();

		virtual Udp* setPort(int port);

		virtual int getPort();

		virtual Udp* setBufferSize(unsigned int bufferSize);

		virtual unsigned int getBufferSize();
};

#endif