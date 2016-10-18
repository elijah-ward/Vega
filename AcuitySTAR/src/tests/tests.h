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
};

#endif
