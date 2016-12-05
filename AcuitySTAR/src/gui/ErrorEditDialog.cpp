#include "ui_ErrorEditDialog.h"
#include "ErrorEditDialog.h"

#include <QStringList>
#include <QDebug>
#include <QBrush>
#include <QColor>
#include <QAbstractButton>
#include <QMessageBox>
#include <QQueue>
#include <iostream>
#include <QString>
#include <QSignalSpy>
#include <QVariant>

/*
 * Load data contained in the errors vector into a QWidgetTable
 * Fields will be marked red and editable if they are a mandatory field
 * and editable.  Otherwise all other fields will not be editable.
 * Clicking Save in the dialog will return the corrected entries to the main
 * program through the errors parameter.  If not all marked fields are edited
 * then a warning message will be displayed.  If cancel is clicked all errors
 * are discarded.
 */




// I MADE IT GLOBAL I'M SORRY TEAM PLEASE FIND A GOOD FIX
static int errorIndex = 0;
static int errorCount;



ErrorEditDialog::ErrorEditDialog(QWidget *parent,
                                 std::vector<std::vector<std::string>*>& errors,
                                 std::vector<std::string>& headers,
                                 std::vector<std::string>& mandatory) :
    QDialog(parent, Qt::WindowTitleHint | Qt::WindowCloseButtonHint),
    errorList(errors),
    headerList(headers),
    mandatoryList(mandatory),
    ui(new Ui::ErrorEditDialog)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount((int) errors.size());
    ui->tableWidget->setColumnCount((int) headers.size());

    QStringList listHeaders;
    for (int i = 0; i < (int) headers.size(); i++) {
        listHeaders << headers[i].c_str();
    }

    ui->tableWidget->setHorizontalHeaderLabels(listHeaders);
    QTableWidgetItem* item;
    QBrush brush(QColor(255, 0, 0, 30));
    QBrush brushFocus(QColor(255, 0, 0, 100));
    std::vector<std::vector<std::string>*>::iterator it;

    //VEGA CODE ADDED
    //I added this for loop so all fields are now editable
    for (int row = 0; row < ui->tableWidget->rowCount(); row++) {
        for (int col = 0; col < ui->tableWidget->columnCount(); col++) {
            item = new QTableWidgetItem();
            Qt::ItemFlags flag = item->flags();
            item->setFlags(Qt::ItemIsSelectable);
            item->setFlags(Qt::ItemIsEditable);

            ui->tableWidget->setItem(row, col, item);
        }
    }

    int row = 0;
    for (it = errors.begin(); it != errors.end(); it++) {
        for (int col = 0; col < (int) headers.size() && col < (int) (*it)->size(); col++) {
            item = new QTableWidgetItem();
            Qt::ItemFlags flag = item->flags();
            item->setText((*it)->at(col).c_str());
            for (int i = 0; i < (int) mandatory.size(); i++) {
                if (mandatory[i].compare(headers.at(col)) == 0
                        && (*it)->at(col).compare("") == 0) {
                    item->setBackground(brush);
                    item->setFlags(flag);
                    QPoint pt(row,col);
                    pointList.push_back(pt);
                }
            }
            ui->tableWidget->setItem(row, col, item);
        }
        row++;
    }




    //shows original number of errors in file
    errorCount = errors.size();
    QString labelText = "Erros remaining: " + QString::number(errorCount);
    ui->errorLabel->setText(labelText);

    //This sets focus to the first error in the queue
    item = ui->tableWidget->item((pointList[errorIndex]).x(), (pointList[errorIndex]).y());
    item->setBackground(brushFocus);
    ui->tableWidget->scrollToItem(item,QAbstractItemView::PositionAtCenter);

    //QString errorCount = "Error: " + QString::number(errorIndex + 1) + "/" + QString::number(pointList.size());
    //ui->errorLabel->setText(errorCount);
}

//Clean up allocated memory for the table items
ErrorEditDialog::~ErrorEditDialog()
{
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        for (int j = 0; j < ui->tableWidget->columnCount(); j++) {
            delete ui->tableWidget->item(i,j);
        }
    }
    delete ui;
}

//Save the new data entered by the user via the error reference var
//Modified by Team Vega: Changed it so it compares ALL values instead of just the errorList values
void ErrorEditDialog::saveData() {
    for (int row = 0; row < ui->tableWidget->rowCount(); row++) {
        //for (int col = 0; col < ui->tableWidget->columnCount() && col < (int) errorList[row]->size(); col++) {
        for (int col = 0; col < ui->tableWidget->columnCount(); col++) {
            std::vector<std::string>::iterator it = errorList[row]->begin()+col;
            if (errorList[row]->at(col).compare("") == 0) {
                it = errorList[row]->erase(it);
                errorList[row]->insert(it, ui->tableWidget->item(row, col)->text().toStdString());
            }
        }
    }
    accept();
}

void ErrorEditDialog::on_next_clicked()

{
    //QString errorCount = ""; //andy's old error counter

    // Initialize the brush colors
    QBrush brush(QColor(255, 0, 0, 30));
    QBrush brushFocus(QColor(255, 0, 0, 100));

    // Change colour of cell currently in focus
    QTableWidgetItem * deFocus = ui->tableWidget->item((pointList[errorIndex]).x(), (pointList[errorIndex]).y());
    deFocus->setBackground(brush);

    //for counting number of errors
    QString currItemText = deFocus->text();
    if(!(currItemText.isEmpty()) && !(currItemText.isNull()))
    {
        errorCount--;
        deFocus->setFlags(deFocus->flags() ^ Qt::ItemIsEditable);
    }
    QString labelText = "Errors remaining: " + QString::number(errorCount);
    ui->errorLabel->setText(labelText);

    // If end of pointList is reached, no. Otherwise, errorIndex++
    if (errorIndex >= pointList.size() - 1){
        QMessageBox msgBox;
        msgBox.setText("End of error list reached.");
        msgBox.exec();
    } else{
        errorIndex++;
    }

    // Change colour of new cell in focus
    QTableWidgetItem * i = ui->tableWidget->item(pointList[errorIndex].x(), pointList[errorIndex].y());
    i->setBackground(brushFocus);
    ui->tableWidget->scrollToItem(i,QAbstractItemView::PositionAtCenter);

    //andy's old error counter
    //errorCount = "Error: " + QString::number(errorIndex + 1) + "/" + QString::number(pointList.size());
    //ui->errorLabel->setText(errorCount);
}

void ErrorEditDialog::on_prev_clicked(){
    //QString errorCount = ""; //andy's old error counter

    // Initialize brush colours
    QBrush brush(QColor(255, 0, 0, 30));
    QBrush brushFocus(QColor(255, 0, 0, 100));

    // Change colour of cell currently focus
    QTableWidgetItem * fixed = ui->tableWidget->item(pointList[errorIndex].x(), pointList[errorIndex].y());
    fixed->setBackground(brush);

    //for counting number of errors
    QString currItemText = fixed->text();
    if(!(currItemText.isEmpty()) && !(currItemText.isNull()))
    {
        errorCount--;
        fixed->setFlags(fixed->flags() ^ Qt::ItemIsEditable);
    }
    QString labelText = "Errors remaining: " + QString::number(errorCount);
    ui->errorLabel->setText(labelText);

    // If beginnng of pointList is reached, no. Otherwise, errorIndex--
    if (errorIndex <= 0){
        QMessageBox msgBox;
        msgBox.setText("Beginning of error list reached.");
        msgBox.exec();
    } else{
        errorIndex--;
    }

    // Change colour of new cell in focus
    QTableWidgetItem * i = ui->tableWidget->item(pointList[errorIndex].x(), pointList[errorIndex].y());
    i->setBackground(brushFocus);
    ui->tableWidget->scrollToItem(i,QAbstractItemView::PositionAtCenter);
    //andy's old error counter
    //errorCount = "Error: " + QString::number(errorIndex + 1) + "/" + QString::number(pointList.size());
    //ui->errorLabel->setText(errorCount);
}


void ErrorEditDialog::on_save_clicked()
{
    bool search = true;
    //check if mandatory fields have been filled
    for (int row = 0; row < ui->tableWidget->rowCount() && search; row++) {
        for (int j = 0; j < (int) mandatoryList.size() && search; j++) {
            std::vector<std::string>::iterator it = std::find(headerList.begin(), headerList.end(), mandatoryList[j]);
            int col = it - headerList.begin();
            QTableWidgetItem* item = ui->tableWidget->item(row, col);
            if (item->text().compare("") == 0) {
                QMessageBox::critical(this, "Error", "Mandatory fields are still empty.");
                search = false;
            }
        }
    }

    if (search) {
        saveData();
    }
}

void ErrorEditDialog::on_cancel_clicked()
{
    reject();
}
