#include "ConsoleView.h"
#include <functional>
#include <iostream>

ConsoleView::ConsoleView(RequestHandler *handler, Scanner *scanner)
    : m_handler(handler), m_scanner(scanner), m_running(false) {

  // Setup callbacks
  m_scanner->setVulnerabilityCallback(
      [this](const std::string &name, const std::string &severity) {
        this->onVulnerabilityFound(name, severity);
      });

  m_scanner->setProgressCallback(
      [this](int percent) { this->onProgressUpdated(percent); });
}

void ConsoleView::start() {
  m_running = true;
  std::cout << "Attacker App CLI Prototype (Pure C++)" << std::endl;
  displayMenu();
  runInputLoop();
}

void ConsoleView::runInputLoop() {
  std::string line;
  while (m_running && std::getline(std::cin, line)) {
    processInput(line);
    if (m_running && !m_scanner->isScanning()) {
      displayMenu();
    }
  }
}

void ConsoleView::displayMenu() {
  std::cout << "\nAvailable Commands:" << std::endl;
  std::cout << "  1. start - Start Scan" << std::endl;
  std::cout << "  2. stop  - Stop Scan" << std::endl;
  std::cout << "  3. quit  - Exit Application" << std::endl;
  std::cout << "\nEnter command: " << std::flush;
}

void ConsoleView::processInput(const std::string &input) {
  if (input == "1" || input == "start") {
    m_handler->handleStartScan();
  } else if (input == "2" || input == "stop") {
    m_handler->handleStopScan();
  } else if (input == "3" || input == "quit" || input == "exit") {
    std::cout << "Exiting..." << std::endl;
    m_running = false;
    // Also stop the scanner if it's running
    if (m_scanner->isScanning()) {
      m_handler->handleStopScan();
    }
  } else {
    std::cout << "[ERROR] Unknown command." << std::endl;
  }
}

void ConsoleView::onVulnerabilityFound(const std::string &name,
                                       const std::string &severity) {
  std::cout << "\n[VULN] Found: " << name << " (" << severity << ")"
            << std::endl;
}

void ConsoleView::onProgressUpdated(int percent) {
  if (percent % 10 == 0) {
    std::cout << "[SCAN] Progress: " << percent << "%" << std::endl;
  }
}
