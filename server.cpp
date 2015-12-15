#include "Common/Common.hpp"
#include "UDP/UDP.hpp"

int Application::main(){

	UdpServer connection("127.0.0.1", 5555);
	String response;

	connection.bind();
	connection.recieve(response);
	out->put(response, true);
	connection.send("Hoje a noite...");
	
	return 0;
}