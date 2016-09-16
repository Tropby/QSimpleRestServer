#include "restrequestlistener.h"

RESTRequestListener::RESTRequestListener(QString resource, QObject *parent) : QObject(parent)
{
    m_Resource = resource;
}

