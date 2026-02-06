#ifndef STOP_SCAN_COMMAND_H
#define STOP_SCAN_COMMAND_H

#include "../model/Scanner.h"
#include "ICommand.h"

class StopScanCommand : public ICommand {
public:
  explicit StopScanCommand(Scanner *scanner) : m_scanner(scanner) {}

  void execute() override {
    if (m_scanner) {
      m_scanner->stopScan();
    }
  }

private:
  Scanner *m_scanner;
};

#endif // STOP_SCAN_COMMAND_H
