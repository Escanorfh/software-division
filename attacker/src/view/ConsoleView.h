#ifndef CONSOLE_VIEW_H
#define CONSOLE_VIEW_H

#include "../controller/RequestHandler.h"
#include "../model/Scanner.h"
#include <string>

class ConsoleView {
public:
  explicit ConsoleView(RequestHandler *handler, Scanner *scanner);
  void start();

  // Callbacks
  void onVulnerabilityFound(const std::string &name,
                            const std::string &severity);
  void onProgressUpdated(int percent);

private:
  void displayMenu();
  void processInput(const std::string &input);
  void runInputLoop();

  RequestHandler *m_handler;
  Scanner *m_scanner;
  bool m_running;
};

#endif // CONSOLE_VIEW_H
