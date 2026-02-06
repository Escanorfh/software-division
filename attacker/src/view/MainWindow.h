#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../controller/RequestHandler.h"
#include "../model/Scanner.h"
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(RequestHandler *handler, Scanner *scanner,
             QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void updateStatus(int progress);
  void onScanStarted();
  void onScanStopped();

private:
  void setupUi();

  RequestHandler *m_handler;
  Scanner *m_scanner;

  QWidget *m_centralWidget;
  QVBoxLayout *m_layout;
  QPushButton *m_btnStartScan;
  QPushButton *m_btnStopScan;
  QLabel *m_lblStatus;
};

#endif // MAINWINDOW_H
