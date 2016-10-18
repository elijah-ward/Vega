#include "tests/tests.h"
#include "gui/mainwindow.h"
#include <string>

using namespace std;

void TestTeachUpload::uploadCSV()
{
    // This is general template of that each test case for uploading CSVs will be

    QString path = "../Project Information/Sample Data/Teaching_sample.csv";
    MainWindow w;
    QVERIFY(w.load_teach(path));
}
