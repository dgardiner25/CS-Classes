#include"phonebook.h"

PhoneBook::PhoneBook()
{
  // Set Up Layout
  newnum = new newNumber;
  
  connect(newnum, SIGNAL(numberEntered(QString, QString)),
          this, SLOT(enterNumber(QString, QString)));

  layout = new QVBoxLayout;
  layout->addWidget(newnum);
  
  QWidget* main = new QWidget;
  main->setLayout(layout);
  setCentralWidget(main);

  openAction = new QAction("&Open", this);
  connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

  saveAction = new QAction("&Save", this);
  connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

  quitAction = new QAction("&Quit",this);
  connect(quitAction, SIGNAL(triggered()), this, SLOT(quit()));

  menuBar()->setNativeMenuBar(false);
  
  fileMenu = menuBar()->addMenu("&File");
  fileMenu->addAction(openAction);
  fileMenu->addAction(saveAction);
  fileMenu->addAction(quitAction);

  modified = false;
}

void PhoneBook::save()
{
  QString fileName = QFileDialog::getSaveFileName(
      this, // Parent
      "Save File", // Dialog Title
      "", // Directory
      "All Files (*)" // File Type Filters
    );

  if(fileName != "")
  {
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly))
    {
      QMessageBox::critical(
          this, // Parent
          "Error", // Dialog Title
          "Could not write to file" // Dialog Text
        );
    }
    else
    {
      modified = false;
      QTextStream out(&file);
      out << serialize();
      file.close();
    }
  }
}

void PhoneBook::open()
{
  QString fileName = QFileDialog::getOpenFileName(
      this, // Parent
      "Open File", // Dialog Title
      "", // Directory
      "All Files (*)" // File Type Filters
    );

  if(fileName != "")
  {
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly))
    {
      QMessageBox::critical(
          this, // Parent
          "Error", // Dialog Title
          "Could not open file" // Dialog Text
        );
    }
    else
    {
      modified = true;
      QTextStream in(&file);
      deserialize(in.readAll());
      file.close();
    }
  }
}

void PhoneBook::quit()
{
  QMessageBox messageBox;
  if(modified)
  {
    messageBox.setWindowTitle("Quit?");
    messageBox.setText("Do you want to quit without saving?");
    messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    messageBox.setDefaultButton(QMessageBox::No);
    if(messageBox.exec() == QMessageBox::Yes)
    {
      qApp->quit();
    }
  }
  else
    qApp->quit();
}

QString PhoneBook::serialize()
{
  QString data = "";
  for(unsigned int i = 0; i < entries.size(); i++)
  {
    Entry* e = entries[i];
    data.append(e->getName() + ";" + e->getNumber() + "\n");
  }

  return data;
}

void PhoneBook::deserialize(QString data)
{
  // Clear all the phone numbers
  for(unsigned int i = 0; i < entries.size(); i++)
  {
    layout->removeWidget(entries[i]);
    delete entries[i];
  }
  entries.clear();

  QStringList split = data.split("\n",QString::SkipEmptyParts);
  for(int i = 0; i < split.size(); i++)
  {
    QStringList vals = split[i].split(";");

    QString name = vals[0];
    QString number = vals[1];

    enterNumber(name, number);
  }
}

void PhoneBook::enterNumber(QString name, QString number)
{
  Entry* e = new Entry(name, number);
  entries.push_back(e);
  layout->addWidget(e);
  modified = true;
}

