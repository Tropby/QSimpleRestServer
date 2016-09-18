#ifndef RESTRESULT_H
#define RESTRESULT_H

#include <QObject>

class RESTResult : public QObject
{
    Q_OBJECT
public:
    explicit RESTResult(QObject *parent = 0);
    void setStatusCode( int code ){ m_StatusCode = code; }
    void setData( QByteArray data ){  m_Data = data; }
    void setData( QString data ){  m_Data = data.toUtf8(); }
    void setData( char * data ){  m_Data = QString( data ).toUtf8(); }
    void appendData( QByteArray data ){ m_Data.append(data); }
    void appendData( QString data ){ m_Data.append(data.toUtf8()); }
    void appendData( char * data ){ m_Data.append(QString( data )); }
    QByteArray data() { return m_Data; }
    int statusCode(){ return m_StatusCode; }

signals:

public slots:

private:
    int m_StatusCode;
    QByteArray m_Data;

};

#endif // RESTRESULT_H
