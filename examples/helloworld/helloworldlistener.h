#ifndef HELLOWORLDLISTENER_H
#define HELLOWORLDLISTENER_H

#include <QObject>
#include "restrequestlistener.h"
#include "restrequest.h"

class HelloWorldListener : public RESTRequestListener
{
    Q_OBJECT
public:
    explicit HelloWorldListener(QObject *parent = 0);

signals:

public slots:
    void http_get_( RESTRequest * request );
};

#endif // HELLOWORLDLISTENER_H
