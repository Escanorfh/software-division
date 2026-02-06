#include "MainWindow.h"

MainWindow::MainWindow(RequestHandler *handler, Scanner *scanner,
                       QWidget *parent)
    : QMainWindow(parent), m_handler(handler), m_scanner(scanner) {

  setupUi();

  // Connect View -> Controller
  connect(m_btnStartScan, &QPushButton::clicked, m_handler,
          &RequestHandler::handleStartScan);
  connect(m_btnStopScan, &QPushButton::clicked, m_handler,
          &RequestHandler::handleStopScan);

  // Connect Model -> View (Observer Pattern)
  connect(m_scanner, &Scanner::progressUpdated, this,
          &MainWindow::updateStatus);
  connect(m_scanner, &Scanner::scanStarted, this, &MainWindow::onScanStarted);
  connect(m_scanner, &Scanner::scanStopped, this, &MainWindow::onScanStopped);
}

MainWindow::~MainWindow() {}

void MainWindow::setupUi() {
  m_centralWidget = new QWidget(this);
  setCentralWidget(m_centralWidget);

  m_layout = new QVBoxLayout(m_centralWidget);

  m_lblStatus = new QLabel("Status: Idle", this);
  m_layout->addWidget(m_lblStatus);

  m_btnStartScan = new QPushButton("Start Scan", this);
  m_layout->addWidget(m_btnStartScan);

  m_btnStopScan = new QPushButton("Stop Scan", this);
  m_btnStopScan->setEnabled(false);
  m_layout->addWidget(m_btnStopScan);
}

void MainWindow::updateStatus(int progress) {
  m_lblStatus->setText(QString("Scanning... %1%").arg(progress));
}

void MainWindow::onScanStarted() {
  m_btnStartScan->setEnabled(false);
  m_btnStopScan->setEnabled(true);
  m_lblStatus->setText("Status: Scanning Started...");
}

void MainWindow::onScanStopped() {
  m_btnStartScan->setEnabled(true);
  m_btnStopScan->setEnabled(false);
  m_lblStatus->setText("Status: Idle");
}
