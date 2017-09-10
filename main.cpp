#include <QCoreApplication>
#include "gwentserver.h"
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

#ifdef DEBUG
	GwentServer server;
	server.startServer();
#endif
	return a.exec();
}
