client: sock/sock.o sock/sockdist.o ClientC.o main.o utilisateur/Info.o
	g++ -o client sock/sock.o sock/sockdist.o ClientC.o utilisateur/Info.o main.o

sock.o: sock/sock.cc
	g++ -o sock.o -c sock/sock.cc

sockdist.o: sock/sockdist.cc
	g++ -o sockdist.o -c sockdist.cc

ClientC.o: ClientC.cc
	g++ -o ClientC.o -c ClientC.cc

Info.o: utilisateur/Info.cc
	g++ -o Info.o -c utilisateur/Info.cc

main.o: main.cc
	g++ -o main.o -c main.cc