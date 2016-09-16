#ifndef RESTREQUESTLISTENER_H
#define RESTREQUESTLISTENER_H

#include <QObject>
#include <QMap>

class RESTRequestListener : public QObject
{
    Q_OBJECT
public:
    explicit RESTRequestListener(QString resource, QObject *parent = 0);
    QString getResource(){ return m_Resource; }

signals:

public slots:

private:
    QString m_Resource;

};

#endif // RESTREQUESTLISTENER_H
