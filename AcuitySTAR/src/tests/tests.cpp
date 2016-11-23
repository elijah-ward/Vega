#include "tests/tests.h"
#include "gui/mainwindow.h"
#include "gui/ErrorEditDialog.h"
#include <string>

using namespace std;

/*****************************
 * id: column-sort-test      *
 *****************************/

void TestSuite::teachColumnSortTest(){
    MainWindow w(0,false);
    QString teachPath = "../Project Information/Sample Data/Teaching_sample.csv";
    w.load_teach(teachPath);
    QVERIFY(w.checkTeachColumnSortable());
}

void TestSuite::pubColumnSortTest(){
    MainWindow w(0,false);
    QString pubPath = "../Project Information/Sample Data/Publications_sample.csv";
    w.load_pub(pubPath);
    QVERIFY(w.checkPubColumnSortable());
}

void TestSuite::presColumnSortTest(){
    MainWindow w(0,false);
    QString presPath = "../Project Information/Sample Data/Presentations_sample.csv";
    w.load_pres(presPath);
    QVERIFY(w.checkPresColumnSortable());
}

void TestSuite::fundColumnSortTest(){
    MainWindow w(0,false);
    QString fundPath = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    w.load_fund(fundPath);
    QVERIFY(w.checkFundColumnSortable());
}
