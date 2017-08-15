#include "prefix.h"
#include "ui_prefix.h"

Prefix::Prefix(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Prefix)
{
    ui->setupUi(this);
    this->setWindowTitle("Set Prefix for Text File");
}

Prefix::~Prefix()
{
    delete ui;
}

void Prefix::on_buttonBox_accepted()
{
}

void Prefix::on_buttonBox_rejected()
{
    if(ui->lineEdit->text().count() != 0)
    {
        null = false;
    }else{
        null = true;
    }
}

QString Prefix::getText()
{
    if(null == false)
    {
    return ui->lineEdit->text();
    }else{
    return orignal;
    }
}

void Prefix::setText(QString text)
{
    ui->lineEdit->setText(text);
    orignal = text;
}
