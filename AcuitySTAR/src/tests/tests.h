#ifndef TESTS_H_
#define TESTS_H_
#include <QtTest/QtTest>
#include "gui/mainwindow.h"

class TestUpload: public QObject
{
    Q_OBJECT
private slots:
    /*
    void uploadTeachCSV();
    void uploadPubCSV();
    void uploadPresCSV();
    void uploadFundCSV();
    void uploadTeachCSVFail();
    void uploadPubCSVFail();
    void uploadPresCSVFail();
    void uploadFundCSVFail();
	void uploadTeachFileFail();
    void uploadPubFileFail();
    void uploadPresFileFail();
    void uploadFundFileFail();
    */

    // this is our shit
    void teachPrintButtonEnabled();
    void fundPrintButtonEnabled();
    void pubPrintButtonEnabled();
    void presPrintButtonEnabled();
    void teachPrintButtonEnabledFail();
    void fundPrintButtonEnabledFail();
    void pubPrintButtonEnabledFail();
    void presPrintButtonEnabledFail();
};

#endif
