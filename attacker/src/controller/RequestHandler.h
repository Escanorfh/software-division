#ifndef REQUEST_HANDLER_H
#define REQUEST_HANDLER_H

#include "../commands/ICommand.h"
#include "../model/Scanner.h"
#include <memory>

class RequestHandler {
public:
  explicit RequestHandler(Scanner *scanner);

  void handleStartScan();
  void handleStopScan();
  void handleGenerateReport();

private:
  Scanner *m_scanner;
  std::shared_ptr<ICommand> m_startScanCommand;
  std::shared_ptr<ICommand> m_stopScanCommand;
};

#endif // REQUEST_HANDLER_H
