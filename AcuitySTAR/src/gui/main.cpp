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

    QApplication app(argc, argv);
    if (test) {
        TestTeachUpload *test_obj = new TestTeachUpload();
        QTest::qExec(test_obj);
    }

    //MainWindow w;
    //w.show();

    return app.exec();
}
