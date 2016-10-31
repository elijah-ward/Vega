#include "tests/tests.h"
#include "gui/mainwindow.h"
#include "ui_mainwindow.h"
#include <string>

using namespace std;

/*****************************************************************************
 *
 * Save Session State Tests
 *
 *****************************************************************************/


void TestSuite::readWriteState()
{
    MainWindow w(0,true);

    int yearStartBefore = 1960;
    int yearEndBefore = 1984;
    QSize screenSizeBefore = QSize(1200,800);
    QPoint positionBefore = QPoint(500,500);

    QString teachPath = "../Project Information/Sample Data/Teaching_sample.csv";
    QString pubPath = "../Project Information/Sample Data/Publications_sample.csv";
    QString presPath = "../Project Information/Sample Data/Presentations_sample.csv";
    QString fundPath = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";

    w.resize(screenSizeBefore);
    w.move(positionBefore);

    w.yearStart = yearStartBefore;
    w.yearEnd = yearEndBefore;

    w.load_teach(teachPath);
    w.load_pub(pubPath);
    w.load_pres(presPath);
    w.load_fund(fundPath);

    w.close();

    //We need to simulate user interaction here with key presses.


    QVERIFY(w.load_teach(teachPath));



}

/******************************************************************************
 *
 * Functions below are for uploading files that are supposed to PASS
 *
 *****************************************************************************/

void TestSuite::uploadTeachCSV()
{
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w(0,false);
    QVERIFY(w.load_teach(path));
}

void TestSuite::uploadPubCSV(){
    QString path = "../Project Information/Sample Data/Publications_sample.csv";
    MainWindow w(0,false);
    QVERIFY(w.load_pub(path));
}

void TestSuite::uploadPresCSV(){
    QString path = "../Project Information/Sample Data/Presentations_sample.csv";
    MainWindow w(0,false);
    QVERIFY(w.load_pres(path));
}

void TestSuite::uploadFundCSV(){
    QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    MainWindow w(0,false);
    QVERIFY(w.load_fund(path));
}

/******************************************************************************
 *
 * Functions below are for uploading files that are supposed to FAIL
 * These functions upload .csv files
 *
 *****************************************************************************/

void TestSuite::uploadTeachCSVFail()
{
    QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    MainWindow w(0,false);
    QVERIFY(!(w.load_teach(path)));
}

void TestSuite::uploadPubCSVFail(){
    QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    MainWindow w(0,false);
    QVERIFY(!(w.load_pub(path)));
}

void TestSuite::uploadPresCSVFail(){
    QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    MainWindow w(0,false);
    QVERIFY(!(w.load_pres(path)));
}

void TestSuite::uploadFundCSVFail(){
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w(0,false);
    QVERIFY(!(w.load_fund(path)));
}

/******************************************************************************
 *
 * Functions below are for uploading files that are supposed to FAIL
 * These functions upload random files
 *
 *****************************************************************************/

void TestSuite::uploadTeachFileFail()
{
    QString path = "../README.md";
    MainWindow w(0,false);
    QVERIFY(!(w.load_teach(path)));
}

void TestSuite::uploadPubFileFail(){
    QString path = "../README.md";
    MainWindow w(0,false);
    QVERIFY(!(w.load_pub(path)));
}

void TestSuite::uploadPresFileFail(){
    QString path = "../README.md";
    MainWindow w(0,false);
    QVERIFY(!(w.load_pres(path)));
}

void TestSuite::uploadFundFileFail(){
    QString path = "../README.md";
    MainWindow w(0,false);
    QVERIFY(!(w.load_fund(path)));
}


/******************************************************************************
 *
 * Print button enabled TC's
 *
 *****************************************************************************/

void TestSuite::teachPrintButtonEnabled()
{
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w(0,false);
    w.load_teach(path);
    QVERIFY(w.checkTeachPrintButton());
}

void TestSuite::fundPrintButtonEnabled()
{
    QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    MainWindow w(0,false);
    w.load_fund(path);
    QVERIFY(w.checkFundPrintButton());
}

void TestSuite::pubPrintButtonEnabled()
{
    QString path = "../Project Information/Sample Data/Publications_sample.csv";
    MainWindow w(0,false);
    w.load_pub(path);
    QVERIFY(w.checkPubPrintButton());
}

void TestSuite::presPrintButtonEnabled()
{
    QString path = "../Project Information/Sample Data/Presentations_sample.csv";
    MainWindow w(0,false);
    w.load_pres(path);
    QVERIFY(w.checkPresPrintButton());
}


/******************************************************************************
 *
 * Print button disabled TC's
 *
 *****************************************************************************/

void TestSuite::teachPrintButtonEnabledFail()
{
    QString path = "../Project Information/Sample Data/Presentations_sample.csv";
    MainWindow w(0,false);
    w.load_teach(path);
    QVERIFY(!(w.checkTeachPrintButton()));
}

void TestSuite::fundPrintButtonEnabledFail()
{
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w(0,false);
    w.load_fund(path);
    QVERIFY(!(w.checkFundPrintButton()));
}

void TestSuite::pubPrintButtonEnabledFail()
{
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w(0,false);
    w.load_pub(path);
    QVERIFY(!(w.checkPubPrintButton()));
}

void TestSuite::presPrintButtonEnabledFail()
{
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w(0,false);
    w.load_pres(path);
    QVERIFY(!(w.checkPresPrintButton()));
}

/******************************************************************************
 *
 * Pdf Export button enabled TC's
 *
 *****************************************************************************/

void TestSuite::teachExportButtonEnabled()
{
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w(0,false);
    w.load_teach(path);
    QVERIFY(w.checkTeachExportButton());
}

void TestSuite::fundExportButtonEnabled()
{
    QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    MainWindow w(0,false);
    w.load_fund(path);
    QVERIFY(w.checkFundExportButton());
}

void TestSuite::pubExportButtonEnabled()
{
    QString path = "../Project Information/Sample Data/Publications_sample.csv";
    MainWindow w(0,false);
    w.load_pub(path);
    QVERIFY(w.checkPubExportButton());
}

void TestSuite::presExportButtonEnabled()
{
    QString path = "../Project Information/Sample Data/Presentations_sample.csv";
    MainWindow w(0,false);
    w.load_pres(path);
    QVERIFY(w.checkPresExportButton());
}

/******************************************************************************
 *
 * Pdf Export button Fail Functions
 *
 *****************************************************************************/

void TestSuite::teachExportButtonEnabledFail()
{
    QString path = "../Project Information/Sample Data/Presentations_sample.csv";
    MainWindow w(0,false);
    w.load_teach(path);
    QVERIFY(!(w.checkTeachExportButton()));
}

void TestSuite::fundExportButtonEnabledFail()
{
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w(0,false);
    w.load_fund(path);
    QVERIFY(!(w.checkFundExportButton()));
}

void TestSuite::pubExportButtonEnabledFail()
{
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w(0,false);
    w.load_pub(path);
    QVERIFY(!(w.checkPubExportButton()));
}

void TestSuite::presExportButtonEnabledFail()
{
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w(0,false);
    w.load_pres(path);
    QVERIFY(!(w.checkPresExportButton()));
}

/******************************************************************************
 *
 * Tooltip hover tests
 *
 *****************************************************************************/

void TestSuite::checkTeachHover(){
    MainWindow w(0,false);
    QString string1 = w.returnTeachHover();
    QCOMPARE(string1, QString("Teaching"));
}

void TestSuite::checkPubHover(){
    MainWindow w(0,false);
    QString string1 = w.returnPubHover();
    QCOMPARE(string1, QString("Publications"));
}

void TestSuite::checkPresHover(){
    MainWindow w(0,false);
    QString string1 = w.returnPresHover();
    QCOMPARE(string1, QString("Presentations"));
}

void TestSuite::checkGranAndClinHover(){
    MainWindow w(0,false);
    QString string1 = w.returnGranAndClinHover();
    QCOMPARE(string1, QString("Grants and Clinical Funding"));
}

/******************************************************************************
 *
 * Print dialog after button press test
 *
 *****************************************************************************/

void TestSuite::teachPrintButtonPress(){
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w(0,false);
    w.load_teach(path);
    QVERIFY(w.on_teachPrintButton_clicked());
}

void TestSuite::fundPrintButtonPress(){
    QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    MainWindow w(0,false);
    w.load_fund(path);
    QVERIFY(w.on_fundPrintButton_clicked());
}

void TestSuite::pubPrintButtonPress(){
    QString path = "../Project Information/Sample Data/Publications_sample.csv";
    MainWindow w(0,false);
    w.load_pub(path);
    QVERIFY(w.on_pubPrintButton_clicked());
}

void TestSuite::presPrintButtonPress(){
    QString path = "../Project Information/Sample Data/Presentations_sample.csv";
    MainWindow w(0,false);
    w.load_pres(path);
    QVERIFY(w.on_presPrintButton_clicked());
}

/******************************************************************************
 *
 * Export to pdf dialog after button press test
 *
 *****************************************************************************/

void TestSuite::teachExportButtonPress(){
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w(0,false);
    w.load_teach(path);
    QVERIFY(w.on_teachExportButton_clicked());
}

void TestSuite::fundExportButtonPress(){
    QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    MainWindow w(0,false);
    w.load_fund(path);
    QVERIFY(w.on_fundExportButton_clicked());
}

void TestSuite::pubExportButtonPress(){
    QString path = "../Project Information/Sample Data/Publications_sample.csv";
    MainWindow w(0,false);
    w.load_pub(path);
    QVERIFY(w.on_pubExportButton_clicked());
}

void TestSuite::presExportButtonPress(){
    QString path = "../Project Information/Sample Data/Presentations_sample.csv";
    MainWindow w(0,false);
    w.load_pres(path);
    QVERIFY(w.on_presExportButton_clicked());
}

/******************************************************************************
 *
 * Pie chart test cases
 *
 *****************************************************************************/

void TestSuite::checkTeachPieButton(){
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w(0,false);
    w.load_teach(path);
    w.on_teach_pie_button_toggled();
    QCOMPARE(w.checkTeachPieBarButton(), 0);
}

void TestSuite::checkFundPieButton(){
    QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    MainWindow w(0,false);
    w.load_fund(path);
    w.on_fund_pie_button_toggled();
    QCOMPARE(w.checkFundPieBarButton(), 0);
}

void TestSuite::checkPubPieButton(){
    QString path = "../Project Information/Sample Data/Publications_sample.csv";
    MainWindow w(0,false);
    w.load_pub(path);
    w.on_pub_pie_button_toggled();
    QCOMPARE(w.checkPubPieBarButton(), 0);
}

void TestSuite::checkPresPieButton(){
    QString path = "../Project Information/Sample Data/Presentations_sample.csv";
    MainWindow w(0,false);
    w.load_pres(path);
    w.on_pres_pie_button_toggled();
    QCOMPARE(w.checkPresPieBarButton(), 0);
}

/******************************************************************************
 *
 * Bar graph test cases
 *
 *****************************************************************************/

void TestSuite::checkTeachBarButton(){
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w(0,false);
    w.load_teach(path);
    w.on_teach_bar_button_toggled();
    QCOMPARE(w.checkTeachPieBarButton(), 1);
}

void TestSuite::checkFundBarButton(){
    QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    MainWindow w(0,false);
    w.load_fund(path);
    w.on_fund_bar_button_toggled();
    QCOMPARE(w.checkFundPieBarButton(), 1);
}

void TestSuite::checkPubBarButton(){
    QString path = "../Project Information/Sample Data/Publications_sample.csv";
    MainWindow w(0,false);
    w.load_pub(path);
    w.on_pub_bar_button_toggled();
    QCOMPARE(w.checkPubPieBarButton(), 1);
}

void TestSuite::checkPresBarButton(){
    QString path = "../Project Information/Sample Data/Presentations_sample.csv";
    MainWindow w(0,false);
    w.load_pres(path);
    w.on_pres_bar_button_toggled();
    QCOMPARE(w.checkPresPieBarButton(), 1);
}

/******************************************************************************
 *
 * Load files test
 *
 *****************************************************************************/

void TestSuite::teachLoadFile()
{
     QString path = "../Project Information/Sample Data/Teaching_sample.csv";
     MainWindow w(0,false);
     QCOMPARE(path, w.load_file());
}

void TestSuite::fundLoadFile()
{
     QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
     MainWindow w(0,false);
     QCOMPARE(path, w.load_file());
}

void TestSuite::pubLoadFile()
{
     QString path = "../Project Information/Sample Data/Publications_sample.csv";
     MainWindow w(0,false);
     QCOMPARE(path, w.load_file());
}

void TestSuite::presLoadFile()
{
     QString path = "../Project Information/Sample Data/Presentations_sample.csv";
     MainWindow w(0,false);
     QCOMPARE(path, w.load_file());
}

/******************************************************************************
 *
 * File Ribbon multiple files upload and uploading non-CSV file
 *
 *****************************************************************************/

void TestSuite::multipleFileUploadTest1(){
    MainWindow w(0,false);
    QVERIFY(w.on_actionLoad_file_triggered());
}

void TestSuite::multipleFileUploadTest2(){
    MainWindow w(0,false);
    QVERIFY(w.on_actionLoad_file_triggered());
}

/******************************************************************************
 *
 * File Extension Tests
 *
 *****************************************************************************/

void TestSuite::randomTwoLetterExtLoadFile()
{
     QString path = "../README.md";
     MainWindow w(0,false);
     QCOMPARE((w.checkFile(0, path)), 1);
}

void TestSuite::randomOneLetterExtLoadFile()
{
     QString path = "../gui/CustomSort.h";
     MainWindow w(0,false);
     QCOMPARE((w.checkFile(0, path)), 1);
}
