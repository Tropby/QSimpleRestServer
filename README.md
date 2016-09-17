# QSimpleRestServer

A very simple Qt REST Server.

It uses QHttpServer from [Nikhil Marathe](https://github.com/nikhilm/qhttpserver) for the HTTP-Server.

QHttpServer uses Joyent's [HTTP Parser](http://github.com/joyent/http-parser) and is asynchronous and does not require any inheritance.

QSimpleRestServer is available under the MIT License.

## Requirements

Requires Qt 5 (maybe Qt 4 works too, not testet jet)

## Usage

Include the pri-File into your pro-File

```c++
include(REST.pri)
```

After that you can use the follwing headers to implement your REST-Server.

```c++
#include "restserver.h"
#include "restrequestlistener.h"
#include "restrequest.h"
```

Create a Server and setup some REST - Listener

```c++
RESTServer server;
server.addRequestListener( new HelloWorldListener() );
server.listen( 8081 );
```

The REST - Listener must extent RESTRequestListener. The Qt-Slot System is used to find the right Method.

```c++
class HelloWorldListener : public RESTRequestListener
{
  Q_OBJECT
  public:
    explicit HelloWorldListener(QObject * parent = 0);

  signals:

  public slots:
    void http_get_( RESTRequest * request );
};
```

```c++
void HelloWorldListener::http_get_(RESTRequest * request)
{
  request->result()->setData( "Hello World" );
  request->result()->setStatusCode( 200 );
}
```

The Method "http_get_" will be called for the REST - Resource "/".

## Method naming

Every REST - Method has to start with *http_* followed by the HTTP-Method ( *get*, *post*, *put*, *delete*, ... ). After that the resource path is added ( replace all "/" with "\_" ).

### Example
HTTP-Method: GET
REST-Rescouce: /customer/event

Methodname must be: http_get_customer_event

### Special namings

You can use the keyword "STAR" als a wildcard in your method names.

A litte example:

```c++
  void http_get_customerSTAR(RESTRequest * request);
```

This method will be handled as Method "GET" for resource *customer* and all sub resources like */customer/events* or */customer/bill*.

To get the "path" just call

```c++
    request->path()
```

## Working with parameters

All parameters within the URL will be parsed to `request->params()`. There you get an `QMap<QString, QString>` with all query parameters.

```c++
if( request->params().contains( "echo" ) )
{
  request->result()->setData( request->params()["echo"] );
  request->result()->setStatusCode( 200 );
}
else
{
  request->result()->setData( "echo not set!" );
  request->result()->setStatusCode( 500 );
}
```
