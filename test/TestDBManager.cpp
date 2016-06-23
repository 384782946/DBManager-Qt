#include "TestDBManager.h"
#include "DBManager.h"
#include <QDebug>
#include <QVariant>

DBManager* g_DBManager = nullptr;

TestDBManager::TestDBManager(QObject *parent)
    : QObject(parent)
{
	g_DBManager = new DBManager("QOCI");
}

TestDBManager::~TestDBManager()
{
    
}

void TestDBManager::test_create()
{
    //����
    //ɾ����
	Q_ASSERT_X(g_DBManager->execSql("DROP TABLE test"), "drop table", "faild");

    //������
	Q_ASSERT_X(g_DBManager->execSql("CREATE TABLE test(id NUMBER(2),name VARCHAR2(20),info VARCHAR2(20))"), "create table", "faild");
   
}

void TestDBManager::test_add()
{
    //����
    QMap<QString,QVariant> datas;
    datas.insert("id",1);
    datas.insert("name","'zxj'");
    datas.insert("info","'hello'");
	Q_ASSERT_X(g_DBManager->add("test", datas), "insert table", "faild");
}

void TestDBManager::test_update()
{
    //����
    QMap<QString,QVariant> udatas;
    udatas.insert("info","'changed information'");
	Q_ASSERT_X(g_DBManager->update("test", udatas, "name='zxj'"), "update table", "faild");
}

void TestDBManager::test_query()
{
    //��ѯ
    QStringList colums;
	qDebug() << g_DBManager->query("test", colums);
    qDebug()<<colums;
}

void TestDBManager::test_remove()
{
    //ɾ��
	Q_ASSERT_X(g_DBManager->remove("test", "name='zxj'"), "delete table", "faild");
}

void TestDBManager::initTestCase()
{
	if (g_DBManager->open("orcl","scott", "zxj","localhost",1521)){
        qDebug()<<"database open success.";
    }else{
        qDebug()<<"database open fail.";
    }
}

void TestDBManager::cleanupTestCase()
{
	g_DBManager->close();
}

void TestDBManager::init()
{

}

void TestDBManager::cleanup()
{

}

#include "moc_TestDBManager.cpp"