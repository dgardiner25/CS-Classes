#pragma once
#include"entry.h"
#include"newNumber.h"

#include<QApplication>
#include<QFileDialog>
#include<QMainWindow>
#include<QMessageBox>
#include<QString>
#include<QTextStream>
#include<QVBoxLayout>
#include<QMenuBar>

#include<vector>

using namespace std;

class PhoneBook : public QMainWindow
{
  Q_OBJECT
  public:
    PhoneBook();

  private slots:
    void enterNumber(QString name, QString number);
    void save();
    void open();
    void quit();

  private:
    // Read over the list of entries and turn them to a string
    QString serialize();

    // Read in a string of data and replace the GUI data with it
    void deserialize(QString data);

    // List of phone number entries
    vector<Entry*> entries;

    QVBoxLayout* layout;
    newNumber* newnum;

    QAction* quitAction;
    QAction* openAction;
    QAction* saveAction;
    QMenu* fileMenu;

    bool modified;
};
