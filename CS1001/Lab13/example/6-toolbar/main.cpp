#include "notepad.h"
#include <QApplication>

int main(int argc, char** argv)
{
  QApplication app(argc,argv);

  Notepad n;
  n.show();

  return app.exec();
}
