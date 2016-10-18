#ifndef TEST_H_
#define TEST_H_
#include <QtTest/QtTest>
#include "gui/mainwindow.h"

class TestTeachUpload: public QObject
{
    Q_OBJECT
private slots:
    void uploadCSV();
};

#endif
