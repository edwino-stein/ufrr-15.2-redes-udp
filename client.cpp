#include "Common/Common.hpp"
#include "UDP/UDP.hpp"

int Application::main(){

	UdpClient connection("127.0.0.1", 5555);

	
	String response;
	// Udp connection("127.0.0.1", 5555);
	connection.send("Olá marielene");
	connection.recieve(response);
	out->put(response, true);
	connection.closeSocket();

	// connection.send("Tainha, vinho...");
	// connection.recieve(response);
	// out->put(response, true);
	return 0;
}