#ifndef RESTREQUEST_H
#define RESTREQUEST_H

#include <QObject>

#include "http/qhttprequest.h"
#include "http/qhttpresponse.h"
#include "restrequestlistener.h"

#include "restresult.h"

class RESTRequest : public QObject
{
    Q_OBJECT
public:
    explicit RESTRequest(QHttpRequest *request, QHttpResponse *response, RESTRequestListener * listener, QObject *parent = 0);
    ~RESTRequest();

    QMap<QString, QString> params();
    QString path();
    QByteArray postData();
    RESTResult * result(){ return &m_Result; }
    QString host();

signals:

private slots:
    void finished();

private:
    QHttpRequest * m_Request;
    QHttpResponse * m_Response;
    RESTResult m_Result;

    RESTRequestListener * m_Listener;
};

#endif // RESTREQUEST_H
