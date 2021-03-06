#ifndef ERROREDITDIALOG_H
#define ERROREDITDIALOG_H

#include <QMessageBox>
#include <QDialog>
#include <vector>
#include <string>
#include <QQueue>
#include <QTableWidgetItem>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class QAbstractButton;

namespace Ui {
    class ErrorEditDialog;
}

class ErrorEditDialog : public QDialog
{
    Q_OBJECT

    friend class TestSuite;

public:
     ErrorEditDialog(QWidget *parent,
                     std::vector<std::vector<std::string>*>& errors,
                     std::vector<std::string>& headers,
                     std::vector<std::string>& mandatory);
    ~ErrorEditDialog();

private slots:
     void on_next_clicked();
     void on_prev_clicked();
     void on_save_clicked();
     void on_cancel_clicked();

private:
    std::vector<QPoint> pointList;
    std::vector<std::vector<std::string>*> errorList;
    std::vector<std::string> headerList;
    std::vector<std::string> mandatoryList;
    Ui::ErrorEditDialog *ui;
    void saveData();
    void writeCSV(std::vector<std::vector<std::string>> csvData);
};

#endif // ERROREDITDIALOG_H
