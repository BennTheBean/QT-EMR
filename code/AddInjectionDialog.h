#ifndef ADDINJECTIONDIALOG_H
#define ADDINJECTIONDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QRegularExpression>
#include <QDate>

namespace Ui {
class AddInjectionDialog;
}

class AddInjectionDialog : public QDialog {
    Q_OBJECT

public:
    explicit AddInjectionDialog(QWidget *parent = nullptr);
    ~AddInjectionDialog();

    QString getType() const;
    QString getDate() const;

private:
    Ui::AddInjectionDialog *ui;
    void onSubmitClicked();
    void onCancelClicked();
};

#endif // ADDINJECTIONDIALOG_H
