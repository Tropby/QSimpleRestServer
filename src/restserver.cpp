#include <QCoreApplication>

#include "restserver.h"
#include "restrequest.h"

RESTServer::RESTServer(QObject *parent) : QObject(parent)
{
    connect( &m_HttpServer, SIGNAL(newRequest(QHttpRequest*,QHttpResponse*)), this, SLOT( newRequest(QHttpRequest*,QHttpResponse*) ) );
}

bool RESTServer::addRequestListener( RESTRequestListener * listener )
{
    m_Listener.append( listener );
    return true;
}

bool RESTServer::listen(unsigned short port)
{
    return m_HttpServer.listen( port );
}

void RESTServer::newRequest(QHttpRequest *request, QHttpResponse *response)
{
    QString path = request->path();
    bool found = false;
    for( int i = 0; i < m_Listener.count(); i++ )
    {
        if( path.startsWith( m_Listener.at( i )->getResource() ) )
        {
            new RESTRequest( request, response, m_Listener.at(i), this );
            found = true;
            break;
        }
    }

    if( !found )
    {
        response->writeHead(404);
        response->end("Service not avalible!");
    }
}

