#include "donate.h"
#include "ui_donate.h"

Donate::Donate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Donate)
{
    ui->setupUi(this);
    ui->label->setOpenExternalLinks(true);
}

Donate::~Donate()
{
    delete ui;
}

