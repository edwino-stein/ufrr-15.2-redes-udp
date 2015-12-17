Primeiro Trabalho de Redes II - Cliente e Servidor UDP

Aluno: Edwino Alberto Lopes Stein
Matricula: 1201324411

************** Observações **************

1. A aplicação não é compativel com o Windows;

2. A aplicação foi desenvolvido e testada utilizando apenas o sistema operacional Ubuntu 15.10.

3. É necessário ter o compilador de C++ GNU G++ em sua versão 4.2 ou superior.


************** Compilar e Executar **************

A compilação e a execução é automatizada pelo shellscript "run.sh" presente na raiz do projeto.

Bata da permição de execução ao arquivo run.sh:

	$ chmod +x run.sh

Para compilar e executar a aplicação servidor:

	$ ./run.sh server.cpp

Para compilar e executar o aplicação cliente:
	
	$ ./run.sh client.cpp


************** Utilização **************

Com o servidor em execução, execute a aplicação cliente. Apos a compilação será solicitado o IP co servidor e a
porta configurada (por padrão, o servidor utiliza a porta 5555) e logo após o programa irá esperar um comando.

Lista de comandos:
	- uname		Nome do kernel do sistema operacional que está executando o servidor;
	- date		Data e hora do servidor;
	- hostname	Nome de rede do computador que está executando o servido;
	- whoami	O nome do usuário que está logado no servidor;
	- help		Lista dos comandos disponiveis;
	- exit		Fecha a aplicação cliente;