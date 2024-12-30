#ifndef ADDFILEDIALOG_H
#define ADDFILEDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QRegularExpression>
#include <QDate>

namespace Ui {
class AddFileDialog;
}

class AddFileDialog : public QDialog {
    Q_OBJECT

public:
    explicit AddFileDialog(QWidget *parent = nullptr);
    ~AddFileDialog();

    QString getData() const;
    QString getDate() const;
    QString getFile() const;

private:
    Ui::AddFileDialog *ui;
    void onSubmitClicked();
    void onCancelClicked();
};

#endif // ADDFILEDIALOG_H
