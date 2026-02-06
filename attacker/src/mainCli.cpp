#include "controller/RequestHandler.h"
#include "model/Scanner.h"
#include "view/ConsoleView.h"

int main(int argc, char *argv[]) {
  // 1. Create Model
  Scanner *scanner = new Scanner();

  // 2. Create Controller (inject Model)
  RequestHandler *handler = new RequestHandler(scanner);

  // 3. Create Console View (inject Controller and Model)
  ConsoleView view(handler, scanner);

  // Start the interaction loop
  view.start();

  delete handler;
  delete scanner;

  return 0;
}
