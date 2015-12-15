 #!/bin/sh

#
#  Edwino Stien - 1201324411
#

# ************** Variaveis globais **************


# ************** Programa principal **************

#Cria o diretorio onde ficaram os binarios, caso nao exista
if [ ! -d "$dirBuild" ]; then
  echo -n "Criando diretorio \"$dirBuild\"...";
  mkdir "$dirBuild";
  echo " OK"
fi

exit 0;