#ifndef SCANNER_H
#define SCANNER_H

#include <atomic>
#include <functional>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

namespace SecurityApp {
struct Vulnerability;
}

class Scanner {
public:
  using VulnerabilityCallback =
      std::function<void(const std::string &name, const std::string &severity)>;
  using ProgressCallback = std::function<void(int percent)>;

  Scanner();
  ~Scanner();

  void startScan();
  void stopScan();
  bool isScanning() const;

  void setVulnerabilityCallback(VulnerabilityCallback cb);
  void setProgressCallback(ProgressCallback cb);

private:
  void runScanLoop();

  std::atomic<bool> m_scanning;
  std::atomic<bool> m_stopRequested;
  std::thread m_scanThread;
  int m_progress;

  VulnerabilityCallback m_vulnCallback;
  ProgressCallback m_progressCallback;
  std::mutex m_callbackMutex;
};

#endif // SCANNER_H
