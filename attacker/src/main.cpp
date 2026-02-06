#include "controller/RequestHandler.h"
#include "model/Scanner.h"
#include "view/MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  // 1. Create Model
  Scanner *scanner = new Scanner();

  // 2. Create Controller (inject Model)
  RequestHandler *handler = new RequestHandler(scanner);

  // 3. Create View (inject Controller and Model)
  MainWindow window(handler, scanner);
  window.setWindowTitle("Attacker App (Raspberry Pi)");
  window.resize(400, 300);
  window.show();

  return app.exec();
}
