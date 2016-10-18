#include "tests/tests.h"
#include "gui/mainwindow.h"
#include <string>

using namespace std;

void TestUpload::uploadTeachCSV()
{
    // This is general template of that each test case for uploading CSVs will be
    // DON'T FORGET TO ADD THE FUNCTION PROTOTYPE INTO THE HEADER FILE AS WELL KTHX

    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w;
    QVERIFY(w.load_teach(path));
}

void TestUpload::uploadPubCSV(){
    QString path = "../Project Information/Sample Data/Publications_sample.csv";
    MainWindow w;
    QVERIFY(w.load_pub(path));
}

void TestUpload::uploadPresCSV(){
    QString path = "../Project Information/Sample Data/Presentations_sample.csv";
    MainWindow w;
    QVERIFY(w.load_pres(path));
}

void TestUpload::uploadFundCSV(){
    QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    MainWindow w;
    QVERIFY(w.load_fund(path));
}

// HEY VEGA, we should also make test cases for the expanded files as well, please check if they
// are supposed to fail on the main program and make a test case accordingly.
