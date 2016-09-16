#include <QCoreApplication>

#include "restserver.h"

#include "helloworldlistener.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    RESTServer server;

    printf( "Add Hello World listener.\n" );
    server.addRequestListener( new HelloWorldListener() );

    printf( "Server listen on Port 8081.\n" );
    server.listen( 8081 );

    printf( "You can now open http://127.0.0.1:8081/ in your browser.\n" );
    return a.exec();
}

