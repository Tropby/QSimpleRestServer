#include <QDebug>
#include <QFile>
#include <QUrlQuery>

#include "restrequest.h"
#include "restresult.h"

RESTRequest::RESTRequest(QHttpRequest *request, QHttpResponse *response, RESTRequestListener * listener, QObject *parent) : QObject(parent)
{
    m_Request = request;
    m_Response = response;
    m_Listener = listener;

    m_Request->storeBody();

    connect( m_Request, SIGNAL(end()), this, SLOT(finished()) );
    connect( m_Request, SIGNAL(destroyed(QObject*)), this, SLOT(deleteLater()) );
}

RESTRequest::~RESTRequest()
{
}

QMap<QString, QString> RESTRequest::params()
{
    QMap<QString, QString> params;
    QList<QPair<QString, QString> > q = QUrlQuery( m_Request->url() ).queryItems();
    for( int i = 0; i < q.count(); i++ )
    {
        params[ QUrl::fromPercentEncoding( q[i].first.toLatin1() ) ] = QUrl::fromPercentEncoding( q[i].second.toLatin1() );
    }
    return params;
}

QString RESTRequest::path()
{
    return m_Request->path();
}

QByteArray RESTRequest::postData()
{
    return m_Request->body();
}

QString RESTRequest::host()
{
    return m_Request->remoteAddress();
}

void RESTRequest::finished()
{
    const QMetaObject * meta = m_Listener->metaObject();

    m_Result.setStatusCode( 404 );
    m_Result.setData( "Can not find " + m_Request->path().toLatin1() );

    for(int i = meta->methodOffset();i < meta->methodCount();i++)
    {
        QMetaMethod metamethod = meta->method(i);
        if( metamethod.methodSignature().endsWith( "(RESTRequest*)" ) )
        {
            QString name = metamethod.name();
            QString p = m_Request->path();
            QString path = m_Request->methodString().toLower() + p.replace( "/", "_" ).replace(".", "_").toLower();

            QRegExp exp( name.replace( "STAR", "*" ) );
            exp.setPatternSyntax( QRegExp::Wildcard );


            if( exp.exactMatch( path ) )
            {
                qRegisterMetaType<RESTRequest*>("RESTRequest*");
                RESTRequest* r = this;
                QGenericArgument arg1( "RESTRequest*", &r );
                QGenericArgument a[10];
                QMetaObject::invokeMethod( m_Listener, metamethod.name(), Qt::DirectConnection, arg1, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8] );
                break;
            }
        }
    }
    m_Response->writeHead( m_Result.statusCode() );
    m_Response->end( m_Result.data() );

    this->deleteLater();
}

