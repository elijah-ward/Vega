#include <iostream>
#include <stdio.h>
#include <QApplication>
#include <QTreeView>

#include "gui/mainwindow.h"
#include "database/TestCSVReader.h"

#include "tests/tests.h"
using namespace std;

int main(int argc, char *argv[]) {
    int test = 1;   /* test on */

    if (test) {
        TestQString *test_obj = new TestQString();
        QTest::qExec(test_obj);
    }

    QApplication app(argc, argv);
    MainWindow w;
    w.show();

    return app.exec();
}
