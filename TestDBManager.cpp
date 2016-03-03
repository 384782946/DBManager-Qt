#include "TestDBManager.h"
#include "DBManager.h"
#include <QDebug>
#include <QVariant>

TestDBManager::TestDBManager(QObject *parent)
    : QObject(parent)
{
   
}

TestDBManager::~TestDBManager()
{
    
}

void TestDBManager::test_create()
{
    //����
    //ɾ����
    Q_ASSERT_X(DBManager::getInstance()->execSql("DROP TABLE test"),"drop table","faild");

    //������
    Q_ASSERT_X(DBManager::getInstance()->execSql("CREATE TABLE test(id NUMBER(2),name VARCHAR2(20),info VARCHAR2(20))"),"create table","faild");
   
}

void TestDBManager::test_add()
{
    //����
    QMap<QString,QVariant> datas;
    datas.insert("id",1);
    datas.insert("name","'zxj'");
    datas.insert("info","'hello'");
    Q_ASSERT_X(DBManager::getInstance()->add("test",datas),"insert table","faild");
}

void TestDBManager::test_update()
{
    //����
    QMap<QString,QVariant> udatas;
    udatas.insert("info","'changed information'");
    Q_ASSERT_X(DBManager::getInstance()->update("test",udatas,"name='zxj'"),"update table","faild");
}

void TestDBManager::test_query()
{
    //��ѯ
    QStringList colums;
    qDebug()<<DBManager::getInstance()->query("test",colums);
    qDebug()<<colums;
}

void TestDBManager::test_remove()
{
    //ɾ��
    Q_ASSERT_X(DBManager::getInstance()->remove("test","name='zxj'"),"delete table","faild");
}

void TestDBManager::initTestCase()
{
    if(DBManager::getInstance()->open("scott","zxj")){
        qDebug()<<"database open success.";
    }else{
        qDebug()<<"database open fail.";
    }
}

void TestDBManager::cleanupTestCase()
{
    DBManager::getInstance()->close();
}

void TestDBManager::init()
{

}

void TestDBManager::cleanup()
{

}

