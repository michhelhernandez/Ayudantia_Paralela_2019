#!/bin/bash
echo "Actualizando lista de paquetes disponibles..."
sudo apt update
echo
echo "Instalando paquetes previos..."
sudo apt install apt-transport-https ca-certificates curl software-properties-common
echo -e "\n\n"


echo "###########################  1) INICIO INSTALACION DOCKER  ###########################"
echo "Agregando clave GPG para repositorio Docker..."
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
echo
echo "Agregando el repositorio Docker..."
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu bionic stable"
echo
echo "Actualizando lista con paquetes de Docker ya agregados..."
sudo apt update
echo
echo "Instalando Docker..."
sudo apt install docker-ce
echo "Docker se ha instalado correctamente!"
echo "###########################  FIN INSTALACION DOCKER  ###########################"
echo -e "\n\n\n"


echo "###########################  2) INICIO INSTALACION DOCKER-COMPOSE  ###########################"
echo "Descargando version actual de Docker-Compose..."
sudo curl -L "https://github.com/docker/compose/releases/download/1.24.0/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
echo
echo "Aplicando permisos ejecutables..."
sudo chmod +x /usr/local/bin/docker-compose
echo "Docker-Compose se ha instalado correctamente!"
echo "###########################  FIN INSTALACION DOCKER-COMPOSE  ###########################"
echo -e "\n\n\n"


echo "###########################  3) AGREGAR USUARIO COMO PARTE DEL GRUPO DOCKER  ###########################"
echo "Agregando el nombre de usuario al grupo Docker..."
sudo usermod -aG docker ${USER}
echo -e "Usuario: ${USER} agregado exitosamente!"
echo -e "\n\n\n"


echo "###########################  4) VALIDAR VERSIONES DOCKER/DOCKER-COMPOSE  ###########################"
echo "VERSION INSTALADA DE DOCKER:"
sudo docker -v
echo
echo "VERSION INSTALADA DE DOCKER-COMPOSE:"
sudo docker-compose -v
echo
echo "Finalizando Script y aplicando cambios..."
su - ${USER}
echo

