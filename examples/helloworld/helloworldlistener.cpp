#include "helloworldlistener.h"

HelloWorldListener::HelloWorldListener(QObject *parent) : RESTRequestListener("/", parent)
{

}

void HelloWorldListener::http_get_(RESTRequest *request)
{
    request->result()->setData( "Hello World" );
    request->result()->setStatusCode( 200 );
}

