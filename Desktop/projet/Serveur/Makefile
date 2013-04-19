serveur: sock/sock.o sock/sockdist.o Serveur.o ClientVuServeur/Client.o Table/Table.o main.o
	g++ -o  serveur -L/usr/local/mysql5/lib/mysql -lmysqlclient  sock/sock.o sock/sockdist.o Table/Table.o Serveur.o ClientVuServeur/Client.o main.o 

sock.o: sock/sock.cc
	g++ -o sock.o -c sock/sock.cc

sockdist.o: sock/sockdist.cc
	g++ -o sockdist.o -c sockdist.cc

Table.o: Table/Table.cc
	g++ -o Table.o -c Table/Table.cc

Client.o: ClientVuServeur/Client.cc
	g++ -o Client.o -c ClientVuServeur/Client.cc

Serveur.o: Serveur.cc
	g++ -o Serveur.o -c Serveur.cc 

main.o: main.cc
	g++ -o main.o -c main.cc
