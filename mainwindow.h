#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QProcess>
#include <QDebug>
#include <QTimer>
#include <fstream>
#include <QFile>
#include "prefix.h"
#include "donate.h"
#include "about.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    void outputToFile();

    void getPrefixFile();

private slots:

    void on_Spotify_Button_clicked();

    void on_Itunes_Button_clicked();

    void Spotify_Clock();

    void iTunes_Clock();

    void on_Prefix_CheckBox_clicked(bool checked);

    void on_EditPrefix_Button_clicked();

    void on_actionAbout_triggered();

    void on_actionDonation_triggered();

private:
    Ui::MainWindow *ui;
    QTimer *clock_1;
    QTimer *clock_2;
    QString songname;
    QString songartist;
    QString songalbum;
    QString songid;
    QImage songartwork;
    QString prefix_name;
    Prefix *prefix;
    bool prefix_bool;
};

#endif // MAINWINDOW_H
