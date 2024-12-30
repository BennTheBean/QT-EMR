#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Singleton.h"
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    Singleton* data;
    ~MainWindow();

private slots:
    void openPatientWindow();
    void openSettings();
    void openAppointmentWindow();
    void login();

private:
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
