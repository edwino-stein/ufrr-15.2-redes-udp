 #!/bin/sh

#
#  Edwino Stien - 1201324411
#

# ************** Variaveis globais **************

dirBuild="./build/";
compileTool="./tools/compileOSX.sh";
compileInvokation="UDP/src/UdpInterface.cpp UDP/src/UdpClient.cpp UDP/src/UdpServer.cpp";
clientSrc="client.cpp"
serverSrc="server.cpp"
mainProgram="";

# ************** Programa principal **************

#Cria o diretorio onde ficaram os binarios, caso nao exista
if [ ! -d "$dirBuild" ]; then
  echo -n "Criando diretorio \"$dirBuild\"...";
  mkdir "$dirBuild";
  echo " OK"
fi

case $1 in

	"client")
 		mainProgram=$clientSrc;
 	;;

	"client.cpp")
 		mainProgram=$clientSrc;
 	;;

	"server")
 		mainProgram=$serverSrc;
 	;;

	"server.cpp")
 		mainProgram=$serverSrc;
 	;;

 	*)
 		echo "Opções: server ou client."
 		exit 0
 	;;
esac

echo
echo -e "\t   ######################################################"
echo -e "\t   ################ Compilando Aplicativo ###############"
echo -e "\t   ######################################################"
echo
chmod +x "$compileTool";
bash -c "$compileTool $mainProgram $compileInvokation";

if [ $? -ne 0 ];  then
	echo
	echo " ***** Algo errado ocorreu durante a compilação do aplicativo *****"
	exit 1;
fi
echo

exit 0;