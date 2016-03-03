#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "taskmanager_global.h"
#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QMap>
#include <QStringList>
#include <QList>
#include <QVariant>

class TASKMANAGER_EXPORT DBManager : public QObject
{
public:
    
    ~DBManager();

    static DBManager* getInstance(){
        static DBManager dbManager;
        return &dbManager;
    }

    inline bool isOpened() const;

    bool open(const QString& user,const QString& psw,const QString& address = "localhost",const QString& dbName = "orcl");

    bool execSql(const QString& sql);

    bool update(const QString& table,const QMap<QString,QVariant>& values,const QString& _where = "");

    bool remove(const QString& table,const QString& _where = "");

    bool add(const QString& table,const QMap<QString,QVariant>& values);

    QList<QList<QVariant>> query(const QString& table,/*[Output]*/QStringList& columns=QStringList(),const QString& _where = "");

    void close();

private:
    DBManager(QObject *parent = 0);

private:
    QSqlDatabase mDB;
};

#endif // DBMANAGER_H
