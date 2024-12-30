#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMainWindow>
#include "Singleton.h"

namespace Ui {
class Settings;
}

class Settings : public QMainWindow
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

private:
    Ui::Settings *ui;
    Singleton* data;
    std::vector<User*> users;

    void openHomeWindow();
    void openAppointmentWindow();
    void openPatientWindow();

    void displayUsers();
    void addUser();
    void deleteUser();
};

#endif // SETTINGS_H
