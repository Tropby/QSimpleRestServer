# QSimpleRestServer

A Qt REST Server.

It uses QHttpServer [Amir Zamani](https://github.com/azadkuh) for HTTP.

QHttpServer uses Joyent's [HTTP Parser](http://github.com/joyent/http-parser) and is asynchronous and does not require any inheritance.

QSimpleRestServer is available under the MIT License.

## Requirements

Requires Qt 5 (maybe Qt 4 works too, not testet jet)

## Usage

Include the headers

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
	explicit HelloWorldListener(QObject *parent = 0);

    signals:

    public slots:
	void http_get_( RESTRequest * request );
    };
```

```c++
    void HelloWorldListener::http_get_(RESTRequest *request)
    {
	request->result()->setData( "Hello World" );
	request->result()->setStatusCode( 200 );
    }
```

The Method "http_get_" will be called for the REST - Resource "/".

## Method naming

Every REST - Method has to start with "http_" followed by the HTTP-Method ("get", "post", "put", "delete", ...). After that the resource path is added (replace all "/" with"_").

### Example
HTTP-Method: GET
REST-Rescouce: /customer/event 

Methodname must be: * http_get_customer_event * 
