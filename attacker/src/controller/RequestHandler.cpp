#include "RequestHandler.h"
#include "../commands/StartScanCommand.h"
#include "../commands/StopScanCommand.h"
#include <iostream>

RequestHandler::RequestHandler(Scanner *scanner) : m_scanner(scanner) {

  // Initialize Commands
  m_startScanCommand = std::make_shared<StartScanCommand>(m_scanner);
  m_stopScanCommand = std::make_shared<StopScanCommand>(m_scanner);
}

void RequestHandler::handleStartScan() {
  std::cout << "RequestHandler: Received Start Scan request." << std::endl;
  if (m_startScanCommand) {
    m_startScanCommand->execute();
  }
}

void RequestHandler::handleStopScan() {
  std::cout << "RequestHandler: Received Stop Scan request." << std::endl;
  if (m_stopScanCommand) {
    m_stopScanCommand->execute();
  }
}

void RequestHandler::handleGenerateReport() {
  std::cout << "RequestHandler: Received Generate Report request." << std::endl;
  // TODO: Implement GenerateReportCommand
}
