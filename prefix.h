#ifndef PREFIX_H
#define PREFIX_H

#include <QDialog>

namespace Ui {
class Prefix;
}

class Prefix : public QDialog
{
    Q_OBJECT

public:
    explicit Prefix(QWidget *parent = 0);
    ~Prefix();
    void setText(QString text);

    QString getText();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Prefix *ui;
    QString orignal;
    bool null;
};

#endif // PREFIX_H
