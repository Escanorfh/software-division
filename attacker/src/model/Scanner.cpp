#include "Scanner.h"
#include <chrono>
#include <iostream>

Scanner::Scanner() : m_scanning(false), m_stopRequested(false), m_progress(0) {}

Scanner::~Scanner() { stopScan(); }

void Scanner::startScan() {
  if (m_scanning)
    return;

  m_scanning = true;
  m_stopRequested = false;
  m_progress = 0;

  std::cout << "Scanner: Scan started." << std::endl;

  // Start the scan loop in a separate thread
  m_scanThread = std::thread(&Scanner::runScanLoop, this);
}

void Scanner::stopScan() {
  m_stopRequested = true;

  if (m_scanThread.joinable()) {
    m_scanThread.join();
  }

  if (m_scanning) {
    m_scanning = false;
    std::cout << "Scanner: Scan stopped." << std::endl;
  }
}

bool Scanner::isScanning() const { return m_scanning; }

void Scanner::setVulnerabilityCallback(VulnerabilityCallback cb) {
  std::lock_guard<std::mutex> lock(m_callbackMutex);
  m_vulnCallback = cb;
}

void Scanner::setProgressCallback(ProgressCallback cb) {
  std::lock_guard<std::mutex> lock(m_callbackMutex);
  m_progressCallback = cb;
}

void Scanner::runScanLoop() {
  while (!m_stopRequested && m_progress < 100) {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    if (m_stopRequested)
      break;

    m_progress += 10;

    {
      std::lock_guard<std::mutex> lock(m_callbackMutex);
      if (m_progressCallback) {
        m_progressCallback(m_progress);
      }
    }

    // Simulate finding vulnerabilities
    if (m_progress == 30) {
      std::lock_guard<std::mutex> lock(m_callbackMutex);
      if (m_vulnCallback) {
        m_vulnCallback("Open Port 22 (SSH)", "Medium");
      }
    } else if (m_progress == 70) {
      std::lock_guard<std::mutex> lock(m_callbackMutex);
      if (m_vulnCallback) {
        m_vulnCallback("Weak Password Policy", "High");
      }
    }
  }

  m_scanning = false;
}
