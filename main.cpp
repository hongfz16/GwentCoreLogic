#include <QCoreApplication>
#include "gwentserver.h"
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

#ifdef DEBUG
	GwentServer server;
	server.startServer();

	std::cout<<"input 1 to start";
	int temp=0;
	std::cin>>temp;

	server.myPair();
#endif
	return a.exec();
}
