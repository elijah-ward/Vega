#include <QtTest>
#include "tests.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    TestSuite1 testSuite1;
    // multiple test suites can be ran like this
    return QTest::qExec(&testSuite1, argc, argv);
}
