#ifndef START_SCAN_COMMAND_H
#define START_SCAN_COMMAND_H

#include "../model/Scanner.h"
#include "ICommand.h"

class StartScanCommand : public ICommand {
public:
  explicit StartScanCommand(Scanner *scanner) : m_scanner(scanner) {}

  void execute() override {
    if (m_scanner) {
      m_scanner->startScan();
    }
  }

private:
  Scanner *m_scanner;
};

#endif // START_SCAN_COMMAND_H
