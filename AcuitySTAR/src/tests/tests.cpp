#include "tests/tests.h"
#include "gui/mainwindow.h"
#include "ui_mainwindow.h"
#include <string>

using namespace std;



// This is general template of that each test case for uploading CSVs will be
// DON'T FORGET TO ADD THE FUNCTION PROTOTYPE INTO THE HEADER FILE AS WELL KTHX



/******************************************************************************
 *
 * Functions below are for uploading files that are supposed to PASS
 *
 *****************************************************************************/
/*
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
}*/

/******************************************************************************
 *
 * Functions below are for uploading files that are supposed to FAIL
 * These functions upload .csv files
 *
 *****************************************************************************/
/*
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
*/
/******************************************************************************
 *
 * Functions below are for uploading files that are supposed to FAIL
 * These functions upload random files
 *
 *****************************************************************************/
/*
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
*/

/******************************************************************************
 *
 * Print button enabled TC's
 *
 *****************************************************************************/

/*
void TestUpload::teachPrintButtonEnabled()
{
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w;
    w.load_teach(path);
    QVERIFY(w.checkTeachPrintButton());
}

void TestUpload::fundPrintButtonEnabled()
{
    QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    MainWindow w;
    w.load_fund(path);
    QVERIFY(w.checkFundPrintButton());
}

void TestUpload::pubPrintButtonEnabled()
{
    QString path = "../Project Information/Sample Data/Publications_sample.csv";
    MainWindow w;
    w.load_pub(path);
    QVERIFY(w.checkPubPrintButton());
}

void TestUpload::presPrintButtonEnabled()
{
    QString path = "../Project Information/Sample Data/Presentations_sample.csv";
    MainWindow w;
    w.load_pres(path);
    QVERIFY(w.checkPresPrintButton());
}
*/

/******************************************************************************
 *
 * Print button disabled TC's
 *
 *****************************************************************************/

/*
void TestUpload::teachPrintButtonEnabledFail()
{
    QString path = "../Project Information/Sample Data/Presentations_sample.csv";
    MainWindow w;
    w.load_teach(path);
    QVERIFY(!(w.checkTeachPrintButton()));
}

void TestUpload::fundPrintButtonEnabledFail()
{
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w;
    w.load_fund(path);
    QVERIFY(!(w.checkFundPrintButton()));
}

void TestUpload::pubPrintButtonEnabledFail()
{
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w;
    w.load_pub(path);
    QVERIFY(!(w.checkPubPrintButton()));
}

void TestUpload::presPrintButtonEnabledFail()
{
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w;
    w.load_pres(path);
    QVERIFY(!(w.checkPresPrintButton()));
}
*/

/******************************************************************************
 *
 * Pdf Export button enabled TC's
 *
 *****************************************************************************/

/*
void TestUpload::teachExportButtonEnabled()
{
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w;
    w.load_teach(path);
    QVERIFY(w.checkTeachExportButton());
}

void TestUpload::fundExportButtonEnabled()
{
    QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    MainWindow w;
    w.load_fund(path);
    QVERIFY(w.checkFundExportButton());
}

void TestUpload::pubExportButtonEnabled()
{
    QString path = "../Project Information/Sample Data/Publications_sample.csv";
    MainWindow w;
    w.load_pub(path);
    QVERIFY(w.checkPubExportButton());
}

void TestUpload::presExportButtonEnabled()
{
    QString path = "../Project Information/Sample Data/Presentations_sample.csv";
    MainWindow w;
    w.load_pres(path);
    QVERIFY(w.checkPresExportButton());
}
*/

/******************************************************************************
 *
 * Export button disabled TC's
 *
 *****************************************************************************/

/*
void TestUpload::teachExportButtonEnabledFail()
{
    QString path = "../Project Information/Sample Data/Presentations_sample.csv";
    MainWindow w;
    w.load_teach(path);
    QVERIFY(!(w.checkTeachExportButton()));
}

void TestUpload::fundExportButtonEnabledFail()
{
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w;
    w.load_fund(path);
    QVERIFY(!(w.checkFundExportButton()));
}

void TestUpload::pubExportButtonEnabledFail()
{
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w;
    w.load_pub(path);
    QVERIFY(!(w.checkPubExportButton()));
}

void TestUpload::presExportButtonEnabledFail()
{
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w;
    w.load_pres(path);
    QVERIFY(!(w.checkPresExportButton()));
}
*/

/******************************************************************************
 *
 * Print dialog after button press test
 *
 *****************************************************************************/

void TestUpload::teachPrintButtonPress(){
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w;
    w.load_teach(path);
    QVERIFY(w.on_teachPrintButton_clicked());
}

void TestUpload::fundPrintButtonPress(){
    QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    MainWindow w;
    w.load_fund(path);
    QVERIFY(w.on_fundPrintButton_clicked());
}

void TestUpload::pubPrintButtonPress(){
    QString path = "../Project Information/Sample Data/Publications_sample.csv";
    MainWindow w;
    w.load_pub(path);
    QVERIFY(w.on_pubPrintButton_clicked());
}

void TestUpload::presPrintButtonPress(){
    QString path = "../Project Information/Sample Data/Presentations_sample.csv";
    MainWindow w;
    w.load_pres(path);
    QVERIFY(w.on_presPrintButton_clicked());
}

/******************************************************************************
 *
 * Export to pdf dialog after button press test
 *
 *****************************************************************************/

void TestUpload::teachExportButtonPress(){
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w;
    w.load_teach(path);
    QVERIFY(w.on_teachExportButton_clicked());
}

void TestUpload::fundExportButtonPress(){
    QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    MainWindow w;
    w.load_fund(path);
    QVERIFY(w.on_fundExportButton_clicked());
}

void TestUpload::pubExportButtonPress(){
    QString path = "../Project Information/Sample Data/Publications_sample.csv";
    MainWindow w;
    w.load_pub(path);
    QVERIFY(w.on_pubExportButton_clicked());
}

void TestUpload::presExportButtonPress(){
    QString path = "../Project Information/Sample Data/Presentations_sample.csv";
    MainWindow w;
    w.load_pres(path);
    QVERIFY(w.on_presExportButton_clicked());
}


