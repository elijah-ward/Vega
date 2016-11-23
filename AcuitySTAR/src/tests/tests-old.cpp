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

/*****************************
 * id: session-state-1       *
 *****************************/

void TestSuite::readWriteState()
{
    MainWindow w(0,true);

    bool settingsCorrect = true;

    QSize screenSizeBefore = QSize(1200,800);
    QPoint positionBefore = QPoint(500,500);

    QString teachPath = "../Project Information/Sample Data/Teaching_sample.csv";
    QString pubPath = "../Project Information/Sample Data/Publications_sample.csv";
    QString presPath = "../Project Information/Sample Data/Presentations_sample.csv";
    QString fundPath = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";

    w.resize(screenSizeBefore);
    w.move(positionBefore);


    w.load_teach(teachPath);
    w.load_pub(pubPath);
    w.load_pres(presPath);
    w.load_fund(fundPath);

    int yearStartBefore = w.yearStart;
    int yearEndBefore = w.yearEnd;

    w.close();

    MainWindow x(0,true);

    //Tester must click 'Yes' when asked to restore the last session

    for(;;){
        if(x.appReady){

            //Check yearStart

            if(x.yearStart ==yearStartBefore){
                printf("\nyearStart is OK\n");
            }
            else{
                printf("\nyearStart FAILED\n");
                settingsCorrect = false;
            }

            //Check yearEnd

            if(x.yearEnd ==yearEndBefore){
                printf("\nyearEnd is OK\n");
            }
            else{
                printf("\nyearEnd FAILED\n");
                settingsCorrect = false;
            }

            //Check Window Size

            if(x.size() == screenSizeBefore){
                printf("\nwindow size is OK\n");
            }
            else{
                printf("\n window size FAILED\n");
                settingsCorrect = false;
            }

            //Check window Position

            if(x.pos() ==positionBefore){
                printf("\nPosition is OK\n");
            }
            else{
                printf("\nPosition FAILED\n");
                settingsCorrect = false;
            }

            //Check teachPath

            if(x.teachPath ==teachPath){
                printf("\nteachPath is OK\n");
            }
            else{
                printf("\nteachPath FAILED\n");
                settingsCorrect = false;
            }

            //Check pubPath

            if(x.pubPath ==pubPath){
                printf("\npubPath is OK\n");
            }
            else{
                printf("\npubPath FAILED\n");
                settingsCorrect = false;
            }

            //Check presPath

            if(x.presPath ==presPath){
                printf("\npresPath is OK\n");
            }
            else{
                printf("\npresPath FAILED\n");
                settingsCorrect = false;
            }

            //Check fundPath

            if(x.fundPath ==fundPath){
                printf("\nfundPath is OK\n");
            }
            else{
                printf("\nfundPath FAILED\n");
                settingsCorrect = false;
            }




    QVERIFY(settingsCorrect);
    break;
    }
    }

}

/******************************************************************************
 *
 * Functions below are for uploading files that are supposed to PASS
 *
 *****************************************************************************/

/*****************************
 * id: file-upload-1       *
 *****************************/

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

/*****************************
 * id: file-upload-2       *
 *****************************/

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

/*****************************
 * id: file-upload-3       *
 *****************************/

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

/*****************************
 * id: print-button-enabled-1*
 *****************************/

void TestSuite::teachPrintButtonEnabled()
{
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w(0,false);
    w.load_teach(path);
    QVERIFY(w.checkTeachPrintButton());
}

/*****************************
 * id: print-button-enabled-2*
 *****************************/

void TestSuite::fundPrintButtonEnabled()
{
    QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    MainWindow w(0,false);
    w.load_fund(path);
    QVERIFY(w.checkFundPrintButton());
}

/*****************************
 * id: print-button-enabled-3*
 *****************************/

void TestSuite::pubPrintButtonEnabled()
{
    QString path = "../Project Information/Sample Data/Publications_sample.csv";
    MainWindow w(0,false);
    w.load_pub(path);
    QVERIFY(w.checkPubPrintButton());
}

/*****************************
 * id: print-button-enabled-4*
 *****************************/

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

/******************************
 * id: print-button-disabled-1*
 ******************************/

void TestSuite::teachPrintButtonEnabledFail()
{
    QString path = "../Project Information/Sample Data/Presentations_sample.csv";
    MainWindow w(0,false);
    w.load_teach(path);
    QVERIFY(!(w.checkTeachPrintButton()));
}

/******************************
 * id: print-button-disabled-2*
 ******************************/

void TestSuite::fundPrintButtonEnabledFail()
{
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w(0,false);
    w.load_fund(path);
    QVERIFY(!(w.checkFundPrintButton()));
}

/******************************
 * id: print-button-disabled-3*
 ******************************/

void TestSuite::pubPrintButtonEnabledFail()
{
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w(0,false);
    w.load_pub(path);
    QVERIFY(!(w.checkPubPrintButton()));
}

/******************************
 * id: print-button-disabled-4*
 ******************************/

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

/******************************
 * id: pdf-button-enabled-1   *
 ******************************/

void TestSuite::teachExportButtonEnabled()
{
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w(0,false);
    w.load_teach(path);
    QVERIFY(w.checkTeachExportButton());
}

/******************************
 * id: pdf-button-enabled-2   *
 ******************************/

void TestSuite::fundExportButtonEnabled()
{
    QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    MainWindow w(0,false);
    w.load_fund(path);
    QVERIFY(w.checkFundExportButton());
}

/******************************
 * id: pdf-button-enabled-3   *
 ******************************/

void TestSuite::pubExportButtonEnabled()
{
    QString path = "../Project Information/Sample Data/Publications_sample.csv";
    MainWindow w(0,false);
    w.load_pub(path);
    QVERIFY(w.checkPubExportButton());
}

/******************************
 * id: pdf-button-enabled-4   *
 ******************************/

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

/******************************
 * id: pdf-button-disabled-1  *
 ******************************/

void TestSuite::teachExportButtonEnabledFail()
{
    QString path = "../Project Information/Sample Data/Presentations_sample.csv";
    MainWindow w(0,false);
    w.load_teach(path);
    QVERIFY(!(w.checkTeachExportButton()));
}

/******************************
 * id: pdf-button-disabled-2  *
 ******************************/

void TestSuite::fundExportButtonEnabledFail()
{
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w(0,false);
    w.load_fund(path);
    QVERIFY(!(w.checkFundExportButton()));
}

/******************************
 * id: pdf-button-disabled-3  *
 ******************************/

void TestSuite::pubExportButtonEnabledFail()
{
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w(0,false);
    w.load_pub(path);
    QVERIFY(!(w.checkPubExportButton()));
}

/******************************
 * id: pdf-button-disabled-4  *
 ******************************/

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

/*****************************
 * id: hover-check-1         *
 *****************************/

void TestSuite::checkTeachHover(){
    MainWindow w(0,false);
    QString string1 = w.returnTeachHover();
    QCOMPARE(string1, QString("Teaching"));
}

/*****************************
 * id: hover-check-2         *
 *****************************/

void TestSuite::checkPubHover(){
    MainWindow w(0,false);
    QString string1 = w.returnPubHover();
    QCOMPARE(string1, QString("Publications"));
}

/*****************************
 * id: hover-check-3         *
 *****************************/

void TestSuite::checkPresHover(){
    MainWindow w(0,false);
    QString string1 = w.returnPresHover();
    QCOMPARE(string1, QString("Presentations"));
}

/*****************************
 * id: hover-check-4         *
 *****************************/

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

/*****************************
 * id: print-dialog-appears-1*
 *****************************/

void TestSuite::teachPrintButtonPress(){
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w(0,false);
    w.load_teach(path);
    QVERIFY(w.on_teachPrintButton_clicked());
}

/*****************************
 * id: print-dialog-appears-2*
 *****************************/

void TestSuite::fundPrintButtonPress(){
    QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    MainWindow w(0,false);
    w.load_fund(path);
    QVERIFY(w.on_fundPrintButton_clicked());
}

/*****************************
 * id: print-dialog-appears-3*
 *****************************/

void TestSuite::pubPrintButtonPress(){
    QString path = "../Project Information/Sample Data/Publications_sample.csv";
    MainWindow w(0,false);
    w.load_pub(path);
    QVERIFY(w.on_pubPrintButton_clicked());
}

/*****************************
 * id: print-dialog-appears-4*
 *****************************/

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

/*****************************
 * id: pdf-dialog-appears-1  *
 *****************************/

void TestSuite::teachExportButtonPress(){
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w(0,false);
    w.load_teach(path);
    QVERIFY(w.on_teachExportButton_clicked());
}

/*****************************
 * id: pdf-dialog-appears-2  *
 *****************************/

void TestSuite::fundExportButtonPress(){
    QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    MainWindow w(0,false);
    w.load_fund(path);
    QVERIFY(w.on_fundExportButton_clicked());
}

/*****************************
 * id: pdf-dialog-appears-3  *
 *****************************/

void TestSuite::pubExportButtonPress(){
    QString path = "../Project Information/Sample Data/Publications_sample.csv";
    MainWindow w(0,false);
    w.load_pub(path);
    QVERIFY(w.on_pubExportButton_clicked());
}

/*****************************
 * id: pdf-dialog-appears-4  *
 *****************************/

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

/*****************************
 * id: pie-chart-toggled-1   *
 *****************************/

void TestSuite::checkTeachPieButton(){
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w(0,false);
    w.load_teach(path);
    w.on_teach_pie_button_toggled();
    QCOMPARE(w.checkTeachPieBarButton(), 0);
}

/*****************************
 * id: pie-chart-toggled-2   *
 *****************************/

void TestSuite::checkFundPieButton(){
    QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    MainWindow w(0,false);
    w.load_fund(path);
    w.on_fund_pie_button_toggled();
    QCOMPARE(w.checkFundPieBarButton(), 0);
}

/*****************************
 * id: pie-chart-toggled-3   *
 *****************************/

void TestSuite::checkPubPieButton(){
    QString path = "../Project Information/Sample Data/Publications_sample.csv";
    MainWindow w(0,false);
    w.load_pub(path);
    w.on_pub_pie_button_toggled();
    QCOMPARE(w.checkPubPieBarButton(), 0);
}

/*****************************
 * id: pie-chart-toggled-4   *
 *****************************/

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

/*****************************
 * id: pie-chart-toggled-1   *
 *****************************/

void TestSuite::checkTeachBarButton(){
    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w(0,false);
    w.load_teach(path);
    w.on_teach_bar_button_toggled();
    QCOMPARE(w.checkTeachPieBarButton(), 1);
}

/*****************************
 * id: pie-chart-toggled-2   *
 *****************************/

void TestSuite::checkFundBarButton(){
    QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
    MainWindow w(0,false);
    w.load_fund(path);
    w.on_fund_bar_button_toggled();
    QCOMPARE(w.checkFundPieBarButton(), 1);
}

/*****************************
 * id: pie-chart-toggled-3   *
 *****************************/

void TestSuite::checkPubBarButton(){
    QString path = "../Project Information/Sample Data/Publications_sample.csv";
    MainWindow w(0,false);
    w.load_pub(path);
    w.on_pub_bar_button_toggled();
    QCOMPARE(w.checkPubPieBarButton(), 1);
}

/*****************************
 * id: pie-chart-toggled-4   *
 *****************************/

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

/*****************************
 * id: file-ribbon-upload-1  *
 *****************************/

void TestSuite::teachLoadFile()
{
     QString path = "../Project Information/Sample Data/Teaching_sample.csv";
     MainWindow w(0,false);
     QCOMPARE(path, w.load_file());
}

/*****************************
 * id: file-ribbon-upload-2  *
 *****************************/

void TestSuite::fundLoadFile()
{
     QString path = "../Project Information/Sample Data/GrantsClinicalFunding_sample.csv";
     MainWindow w(0,false);
     QCOMPARE(path, w.load_file());
}

/*****************************
 * id: file-ribbon-upload-3  *
 *****************************/

void TestSuite::pubLoadFile()
{
     QString path = "../Project Information/Sample Data/Publications_sample.csv";
     MainWindow w(0,false);
     QCOMPARE(path, w.load_file());
}

/*****************************
 * id: file-ribbon-upload-4  *
 *****************************/

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

/*****************************
 * id: file-ribbon-upload-5  *
 *****************************/

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

/*****************************
 * id: session-state-1       *
 *****************************/

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
