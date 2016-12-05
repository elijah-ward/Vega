#include <iostream>
#include <stdio.h>
#include <QApplication>
#include <QTreeView>

#include "gui/mainwindow.h"
#include "database/TestCSVReader.h"

#include "tests/tests.h"
using namespace std;

int main(int argc, char *argv[]) {
    int test = 0;

    QApplication app(argc, argv);
    if (test) {
        QStringList testCmd;
        QDir testLogDir;
        testLogDir.mkdir("testlogs");
        testCmd << " " << "-o " << "testlogs/qtTestLog.txt";
        TestSuite *test_obj = new TestSuite();
        QTest::qExec(test_obj);
    }

    MainWindow w(0,true);

    w.show();





    return app.exec();
}
