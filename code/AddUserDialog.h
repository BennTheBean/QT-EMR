#ifndef ADDUSERDIALOG_H
#define ADDUSERDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QRegularExpression>
#include "Singleton.h"

namespace Ui {
class AddUserDialog;
}

class AddUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddUserDialog(QWidget *parent = nullptr);
    ~AddUserDialog();

    QString getName() const;
    QString getPass() const;
    QString getRole() const;
private:
    Ui::AddUserDialog *ui;
    void onSubmitClicked();
    void onCancelClicked();

    bool verifyUnique() const;
};

#endif // ADDUSERDIALOG_H
