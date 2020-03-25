#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "dbmanager_global.h"
#include <QObject>
#include <QMap>
#include <QStringList>
#include <QList>
#include <QVariant>
#include <QSqlQuery>

class QSqlDatabase;

struct DBConfig{
    QString dbName;
    QString user;
    QString password;
    QString host;
    int port;
};

class DBMANAGER_EXPORT DBManager : public QObject
{
public:
    DBManager(const QString& driver,QObject *parent = 0);
    ~DBManager();

    DBConfig config() const;
    void setConfig(const DBConfig &config);

    bool isOpen() const;

    bool open();

    void close();

    //增
    bool add(const QString& table,const QMap<QString,QVariant>& values);

    //删
    bool remove(const QString& table,const QString& where = "");

    //查
    QList<QVariantList> query(const QString& table,/*[Output]*/QStringList& columns=QStringList(),const QString& where = "");

    //改
    bool update(const QString& table,const QMap<QString,QVariant>& values,const QString& where = "");

    bool execSql(const QString& sql);

    QStringList tables();

protected:
    bool queryExec(QSqlQuery& query,const QString& sql = "");

private:
    QSqlDatabase* mDB;

    DBConfig m_config;
};

#endif // DBMANAGER_H
