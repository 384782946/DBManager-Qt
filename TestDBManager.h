#ifndef TESTDBMANAGER_H
#define TESTDBMANAGER_H

#include <QObject>

class TestDBManager : public QObject
{
    Q_OBJECT

public:
    TestDBManager(QObject *parent=0);
    ~TestDBManager();

private slots:
    void test_create();

    void test_add();

    void test_update();

    void test_query();

    void test_remove();

    void initTestCase();

    void cleanupTestCase();

    void init();

    void cleanup();
};

#endif // TESTDBMANAGER_H
