#include "Common/Common.hpp"
#include "UDP/UDP.hpp"

String exec(String cmd, int bufferSize = 1024){

	FILE *fp = popen(cmd.c_str(), "r");
	char buffer[bufferSize];
	fgets(buffer, bufferSize, fp);
	pclose(fp);

	String output(buffer);
	return output;
}

int Application::main(){

	String cmdAvaible[] = {"uname", "date", "hostname", "whoami"};
	int total = (int)(sizeof(cmdAvaible)/sizeof(cmdAvaible[0])), i;
	String input;
	String output;
	bool cmdFound;
	
	UdpServer connection("0.0.0.0", 5555);
	connection.bind();

	console->clear();
	out->put("******** Rodando o servidor ")
	   ->put(connection.getIp())
	   ->put(':')
	   ->put(connection.getPort())
	   ->put(" ********", true)
	   ->putNewLine();

	while(true){

		output.clear();
		input.clear();

		connection.recieve(input);

		out->put('[')
		   ->put(connection.getClientIp())
		   ->put(':')
		   ->put(connection.getClientPort())
		   ->put("]: ")
		   ->put(input);

		if(input.compare("help") == 0){

			output.append("Comandos: ");

			for(i = 0; i < total; i++){
				output.append(cmdAvaible[i]);
				output.append(", ");
			}
		}

		else{

			cmdFound = false;

			for(i = 0; i < total; i++){
				if(input.compare(cmdAvaible[i]) == 0){
					output.append(exec(cmdAvaible[i]));
					cmdFound = true;
					break;
				}
			}

			if(!cmdFound){
				output.append("Comando inválido. Tente \"help\".");
			}
		}

		out->put(" -> ")->put(output, true);
		connection.send(output);
	}

	return 0;
}