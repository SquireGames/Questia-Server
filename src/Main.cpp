#ifdef _WIN32
#if !(__GNUC__ == 6 && \
		  __GNUC_MINOR__ == 1 && \
		  __GNUC_PATCHLEVEL__ == 0)
#warning Compiler version may be incompatible with pre-built SFML dlls. Use g++ 6.1.0 (DW2).
#endif // __GNUC__
#elif linux
#if !(__GNUC__ == 6 && \
		  __GNUC_MINOR__ == 2 && \
		  __GNUC_PATCHLEVEL__ == 0)
#warning Compiler version may be incompatible with pre-built SFML dlls. Use g++ 6.2.0.
#endif // __GNUC__
#else
#warning Your operating system was not yet tested with the prebuilt SFML dlls.
#endif

#include <iostream>
#include <stdexcept>
#include <unistd.h> //getopt

#include "QuestiaEng/Server/Server.h"

int main(int argc, char** argv)
{
	std::string serverName = "Questia Server";
	int tickRate = 32;
	int threads = 4;
	unsigned short udpPort = 7777;
	unsigned short tcpPort = 7778;

	int opt;

	while((opt = getopt(argc, argv, "n:r:c:u:t:")) != -1)
	{
		switch(opt)
		{
		case 'n':
			serverName = optarg;
			break;
		case 'r':
			tickRate = atoi(optarg);
			break;
		case 'c':
			threads = atoi(optarg);
			break;
		case 'u':
			udpPort = atoi(optarg);
			break;
		case 't':
			tcpPort = atoi(optarg);
			break;
		default:
			break;
		}
	}

	try
	{
		Server server(serverName, tickRate, threads, udpPort, tcpPort);
		server.startServer();
	}
	catch(std::exception& exc)
	{
		std::cout << std::endl << "Runtime exception: " << exc.what() <<std::endl;
	}
	return 0;
}
