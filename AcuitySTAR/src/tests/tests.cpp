#include "tests/tests.h"
#include "gui/mainwindow.h"
#include <string>

using namespace std;



// This is general template of that each test case for uploading CSVs will be
// DON'T FORGET TO ADD THE FUNCTION PROTOTYPE INTO THE HEADER FILE AS WELL KTHX



/******************************************************************************
 *
 * Functions below are for uploading files that are supposed to PASS
 *
 *****************************************************************************/

void TestUpload::uploadTeachCSV()
{
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

/******************************************************************************
 *
 * Functions below are for uploading files that are supposed to FAIL
 * These functions upload .csv files
 *
 *****************************************************************************/

void TestUpload::uploadTeachCSVFail()
{
    QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    MainWindow w;
    QVERIFY(!(w.load_teach(path)));
}

void TestUpload::uploadPubCSVFail(){
    QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    MainWindow w;
    QVERIFY(!(w.load_pub(path)));
}

void TestUpload::uploadPresCSVFail(){
    QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    MainWindow w;
    QVERIFY(!(w.load_pres(path)));
}

void TestUpload::uploadFundCSVFail(){
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w;
    QVERIFY(!(w.load_fund(path)));
}

/******************************************************************************
 *
 * Functions below are for uploading files that are supposed to FAIL
 * These functions upload random files
 *
 *****************************************************************************/

void TestUpload::uploadTeachFileFail()
{
    QString path = "../README.md";
    MainWindow w;
    QVERIFY(!(w.load_teach(path)));
}

void TestUpload::uploadPubFileFail(){
    QString path = "../README.md";
    MainWindow w;
    QVERIFY(!(w.load_pub(path)));
}

void TestUpload::uploadPresFileFail(){
    QString path = "../README.md";
    MainWindow w;
    QVERIFY(!(w.load_pres(path)));
}

void TestUpload::uploadFundFileFail(){
    QString path = "../README.md";
    MainWindow w;
    QVERIFY(!(w.load_fund(path)));
}

/******************************************************************************
 *
 * Alex testing random
 *
 *****************************************************************************/

void TestUpload::teachPrintButtonEnabled()
{
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w;
    w.load_teach(path);
    QVERIFY(ui->teachPrintButton->setEnabled(true));
}

