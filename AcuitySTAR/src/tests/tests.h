#ifndef TEST_H_
#define TEST_H_
#include <QtTest/QtTest>
#include "gui/mainwindow.h"

class TestUpload: public QObject
{
    Q_OBJECT
private slots:
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
};

#endif
