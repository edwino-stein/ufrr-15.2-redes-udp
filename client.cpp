#include "Common/Common.hpp"
#include "UDP/UDP.hpp"

int Application::main(){

	console->clear();

	String host;
	int port;

	host = (String) in->put("Informe o servidor [127.0.0.1]: ");

	if(host.empty()){
		host.append("127.0.0.1");
	}

	port = in->put("Informe a porta: ");

	UdpClient connection(host, port);

	out->put("Conectando...", true);
	if(!connection.openSocket()){
		out->put("Falha ao conectar.", true);
		return 0;
	}

	if(!connection.send("help")){
		out->put("Falha ao conectar.", true);
		return 0;
	}

	String input;
	String output;	

	while(true){

		output.clear();
		input.clear();

		connection.recieve(output);
		out->put(" -> ")->put(output, true);

		input = (String) in->put("Comando: ");

		if(input.compare("exit") == 0){
			break;
		}
		else{
			connection.send(input);
		}
	}

	connection.closeSocket();
	return 0;
}