#include "DBManager.h"
#include <QtSql/QSqlDatabase>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>

DBManager::DBManager(const QString& driver,QObject *parent)
    : QObject(parent)
	, mDB(nullptr)
{
    qDebug() << "qt sql drivers:" << QSqlDatabase::drivers();
    mDB = new QSqlDatabase(QSqlDatabase::addDatabase(driver));
}

DBManager::~DBManager()
{
   close();
   QSqlDatabase::removeDatabase(mDB->connectionName());
   delete mDB;
   mDB = nullptr;
}

bool DBManager::isOpen() const
{
    bool b = mDB->isOpen();
    if(!b) {
        qDebug() << "database is not open.";
    }

    return b;
}

bool DBManager::open()
{
    if(mDB->isOpen()){
        return true;
    }

    if(!m_config.host.isEmpty())
        mDB->setHostName(m_config.host);
    if(!m_config.dbName.isEmpty())
        mDB->setDatabaseName(m_config.dbName);
    if(!m_config.user.isEmpty())
        mDB->setUserName(m_config.user);
    if(!m_config.password.isEmpty())
        mDB->setPassword(m_config.password);
    if(m_config.port > 0)
        mDB->setPort(m_config.port);

    bool b = mDB->open();
    if(!b) {
        qDebug() << "DBManager::open" << mDB->lastError();
    }
    return b;
}

void DBManager::close()
{
	if (mDB->isOpen())
    {
		mDB->close();
    }
}

bool DBManager::queryExec(QSqlQuery &query,const QString& sql)
{
    bool b  = false;
    if(sql.isEmpty()){
        b = query.exec();
    }else{
        b = query.exec(sql);
    }

    if(!b) {
        qDebug()  << query.lastQuery() << query.lastError();
    }

    return b;
}

DBConfig DBManager::config() const
{
    return m_config;
}

void DBManager::setConfig(const DBConfig &config)
{
    m_config = config;
}

bool DBManager::execSql( const QString& sql )
{
    if (!isOpen())
        return false;

    QSqlQuery query(*mDB);
    return queryExec(query,sql);
}

QStringList DBManager::tables()
{
    if (!isOpen())
        return QStringList();

    return mDB->tables();
}

bool DBManager::update( const QString& table,const QMap<QString,QVariant>& values ,const QString& _where)
{
    if (!isOpen())
		return false;

    QSqlQuery query(*mDB);
    QString datas;
    QList<QString> keyList = values.keys();
    foreach(QString key,keyList){
        if(!datas.isEmpty())
            datas += ",";
        datas += QString("%1=?").arg(key);
    }

    QString sql;
    if(_where.isEmpty())
        sql = QString("UPDATE %1 SET %2").arg(table).arg(datas);
    else
        sql = QString("UPDATE %1 SET %2 WHERE %3").arg(table).arg(datas).arg(_where);
    if(!query.prepare(sql)) {
        qDebug() << "DBManager::update" << query.lastError();
        return false;
    }

    for(int i=0;i<keyList.count();++i)
    {
        query.bindValue(i,values.value(keyList.at(i)));
    }

    return queryExec(query);
}

bool DBManager::remove( const QString& table,const QString& _where )
{
    if (!isOpen())
		return false;

    QSqlQuery query;
    QString sql = QString("DELETE FROM %1 WHERE %2").arg(table).arg(_where);
    return queryExec(query,sql);
}

bool DBManager::add( const QString& table,const QMap<QString,QVariant>& values )
{
    if (!isOpen())
		return false;

    QSqlQuery query(*mDB);
    QString columns,datas;
    QList<QString> keyList = values.keys();
    foreach(QString key,keyList){
        if(!columns.isEmpty())
            columns += ",";
        columns += key;

        if(!datas.isEmpty())
            datas += ",";
        datas+="?";
    }

    QString sql = QString("INSERT INTO %1 (%2) VALUES (%3)").arg(table).arg(columns).arg(datas);
    query.prepare(sql);

    for(int i=0;i<keyList.count();++i)
    {
        query.bindValue(i,values.value(keyList.at(i)));
    }

    return queryExec(query);
}

QList<QVariantList> DBManager::query( const QString& table,QStringList& columns,const QString& where )
{
    QList<QList<QVariant>> rets;
    if (!isOpen())
		return rets;

    QSqlQuery query(*mDB);
    QString _columns;
    if(columns.count()>0)
        _columns = columns.join(",");
    else
        _columns = "*";

    QString sql;
    if(where.isEmpty())
        sql = QString("SELECT %1 FROM %2").arg(_columns).arg(table);
    else
        sql = QString("SELECT %1 FROM %2 WHERE %3").arg(_columns).arg(table).arg(where);
    if(queryExec(query,sql))
    {
        int colNum = query.record().count();
        
        for(int i=0;i<colNum;++i)
        {
            columns<<query.record().fieldName(i);
        }

        while(query.next())
        {
            QList<QVariant> row;
            for(int i=0;i<colNum;++i)
            {
                row.append(query.value(i));
            }

            rets.append(row);
        }
    }
    return rets;
}
