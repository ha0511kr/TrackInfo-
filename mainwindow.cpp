#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Track Info+");
    ui->Spotify_Button->setText("Get Spotify Data");
    ui->Itunes_Button->setText("Get iTunes Data");
    ui->Current_Name->setText("Current Song:");
    ui->Current_Artist->setText("Current Artist:");
    ui->Current_Album->setText("Current Album:");
    ui->Current_ID->setText("Current ID:");
    clock_1 = new QTimer;
    clock_2 = new QTimer;
    this->setMaximumWidth(1000);
    connect(clock_1, SIGNAL(timeout()), this, SLOT(Spotify_Clock()));
    connect(clock_2, SIGNAL(timeout()), this, SLOT(iTunes_Clock()));
    getPrefixFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getPrefixFile()
{
    QString applcationDirectory = QApplication::applicationDirPath();
    QString applcationName = QApplication::applicationName() + ".app/Contents/MacOS";
    applcationDirectory.replace(applcationName, "");

    std::ifstream getprefix;
    QString data_prefix = applcationDirectory + "Data/Prefix(Do not delete this).txt";
    getprefix.open(data_prefix.toStdString().c_str());
    std::string readtext;
    if(getprefix.is_open())
    {
        while(std::getline(getprefix, readtext))
        {
             this->prefix_name = QString::fromStdString(readtext);
        }
        qDebug() << this->prefix_name;
        getprefix.close();
    }

}

void MainWindow::on_Spotify_Button_clicked()
{
    if(clock_2->isActive())
    {
        clock_2->stop();
        clock_1->start(500);
    }else if(clock_1->isActive()){
        //clock_1->start(500);
    }else if(!(clock_1->isActive()))
    {
        clock_1->start(500);
    }
}

void MainWindow::on_Itunes_Button_clicked()
{
    if(clock_1->isActive())
    {
        clock_1->stop();
        clock_2->start(500);
    }else if(clock_2->isActive())
    {

    }else if(!(clock_2->isActive()))
    {
        clock_2->start(500);
    }
}

void MainWindow::Spotify_Clock()
{
    {
    QString aScript =

    "tell application \"Spotify\"\n"
    "return name of current track"
    "\nend tell\n";

    QString osascript = "/usr/bin/osascript";
    QStringList processArguments;
    processArguments << "-l" << "AppleScript";

    QProcess p;
    p.start(osascript, processArguments);
    p.write(aScript.toUtf8());
    p.closeWriteChannel();
    p.waitForFinished();
    QByteArray result = p.readAll();
    QString resultAsString(result);
    //qDebug() << "Outputted: " << resultAsString;
    ui->Current_Name->setText("Current Song: " + resultAsString);
    this->songname = resultAsString;
    }

    {
    QString aScript =

    "tell application \"Spotify\"\n"
    "return artist of current track"
    "\nend tell\n";

    QString osascript = "/usr/bin/osascript";
    QStringList processArguments;
    processArguments << "-l" << "AppleScript";

    QProcess p;
    p.start(osascript, processArguments);
    p.write(aScript.toUtf8());
    p.closeWriteChannel();
    p.waitForFinished();
    QByteArray result = p.readAll();
    QString resultAsString(result);
    //qDebug() << "Outputted: " << resultAsString;
    ui->Current_Artist->setText("Current Artist: " + resultAsString);
    this->songartist = resultAsString;
    }

    {
    QString aScript =

    "tell application \"Spotify\"\n"
    "return album of current track"
    "\nend tell\n";

    QString osascript = "/usr/bin/osascript";
    QStringList processArguments;
    processArguments << "-l" << "AppleScript";

    QProcess p;
    p.start(osascript, processArguments);
    p.write(aScript.toUtf8());
    p.closeWriteChannel();
    p.waitForFinished();
    QByteArray result = p.readAll();
    QString resultAsString(result);
    //qDebug() << "Outputted: " << resultAsString;
    ui->Current_Album->setText("Current Album: " + resultAsString);
    this->songalbum = resultAsString;
    }

    {
    QString aScript =

    "tell application \"Spotify\"\n"
    "return id of current track"
    "\nend tell\n";

    QString osascript = "/usr/bin/osascript";
    QStringList processArguments;
    processArguments << "-l" << "AppleScript";

    QProcess p;
    p.start(osascript, processArguments);
    p.write(aScript.toUtf8());
    p.closeWriteChannel();
    p.waitForFinished();
    QByteArray result = p.readAll();
    QString resultAsString(result);
    //qDebug() << "Outputted: " << resultAsString;
    ui->Current_ID->setText("Current ID: " + resultAsString);
    this->songid = resultAsString;
    }

    /*{
    QString aScript =

    "tell application \"Spotify\"\n"
    "return artwork of current track"
    "\nend tell\n";

    QString osascript = "/usr/bin/osascript";
    QStringList processArguments;
    processArguments << "-l" << "AppleScript";

    QProcess p;
    p.start(osascript, processArguments);
    p.write(aScript.toUtf8());
    p.closeWriteChannel();
    p.waitForFinished();
    QByteArray result = p.readAll();

    //qDebug() << "Outputted: " << resultAsString;
    ui->Current_ID->setText(result.to);
    }*/
    outputToFile();
}

void MainWindow::iTunes_Clock()
{
    {
    QString aScript =

    "tell application \"iTunes\"\n"
    "return name of current track"
    "\nend tell\n";

    QString osascript = "/usr/bin/osascript";
    QStringList processArguments;
    processArguments << "-l" << "AppleScript";

    QProcess p;
    p.start(osascript, processArguments);
    p.write(aScript.toUtf8());
    p.closeWriteChannel();
    p.waitForFinished();
    QByteArray result = p.readAll();
    QString resultAsString(result);
    //qDebug() << "Outputted: " << resultAsString;
    ui->Current_Name->setText("Current Song: " + resultAsString);
    this->songname = resultAsString;
    }

    {
    QString aScript =

    "tell application \"iTunes\"\n"
    "return artist of current track"
    "\nend tell\n";

    QString osascript = "/usr/bin/osascript";
    QStringList processArguments;
    processArguments << "-l" << "AppleScript";

    QProcess p;
    p.start(osascript, processArguments);
    p.write(aScript.toUtf8());
    p.closeWriteChannel();
    p.waitForFinished();
    QByteArray result = p.readAll();
    QString resultAsString(result);
    //qDebug() << "Outputted: " << resultAsString;
    ui->Current_Artist->setText("Current Artist: " + resultAsString);
    this->songartist = resultAsString;
    }

    {
    QString aScript =

    "tell application \"iTunes\"\n"
    "return album of current track"
    "\nend tell\n";

    QString osascript = "/usr/bin/osascript";
    QStringList processArguments;
    processArguments << "-l" << "AppleScript";

    QProcess p;
    p.start(osascript, processArguments);
    p.write(aScript.toUtf8());
    p.closeWriteChannel();
    p.waitForFinished();
    QByteArray result = p.readAll();
    QString resultAsString(result);
    //qDebug() << "Outputted: " << resultAsString;
    ui->Current_Album->setText("Current Album: " + resultAsString);
    this->songalbum = resultAsString;
    }

    {
    QString aScript =

    "tell application \"iTunes\"\n"
    "return id of current track"
    "\nend tell\n";

    QString osascript = "/usr/bin/osascript";
    QStringList processArguments;
    processArguments << "-l" << "AppleScript";

    QProcess p;
    p.start(osascript, processArguments);
    p.write(aScript.toUtf8());
    p.closeWriteChannel();
    p.waitForFinished();
    QByteArray result = p.readAll();
    QString resultAsString(result);
    //qDebug() << "Outputted: " << resultAsString;
    ui->Current_ID->setText("Current ID: NULL - Spotify Only!");
    this->songid = "Current ID: NULL - Spotify Only!";
    }

    /*{
    QString aScript =

    "tell application \"iTunes\"\n"
    "return artwork of current track"
    "\nend tell\n";

    QString osascript = "/usr/bin/osascript";
    QStringList processArguments;
    processArguments << "-l" << "AppleScript";

    QProcess p;
    p.start(osascript, processArguments);
    p.write(aScript.toUtf8());
    p.closeWriteChannel();
    p.waitForFinished();
    QByteArray result = p.readAll();

    //qDebug() << "Outputted: " << resultAsString;
    ui->Current_ID->setText(result.to);
    }*/
    outputToFile();
}

void MainWindow::outputToFile()
{
    /*QFile file("SongName.txt");
    file.open(QIODevice::ReadOnly);
    file.write(songname.toStdString().c_str());
    file.close();
    */
    QString applcationDirectory = QApplication::applicationDirPath();
    QString applcationName = QApplication::applicationDisplayName() + ".app/Contents/MacOS";
    applcationDirectory.replace(applcationName, "");
    //ui->Current_ID->setText(applcationDirectory);
    //ui->Current_ID->setText(applcationName + " " + applcationDirectory);

    std::ofstream songn;
    QString songname_dir = applcationDirectory + "Output/Name.txt";
    songn.open(songname_dir.toStdString().c_str());
    songn << songname.toStdString();
    songn.close();

    std::ofstream songar;
    QString songar_dir = applcationDirectory + "Output/Artist.txt";
    songar.open(songar_dir.toStdString().c_str());
    songar << songartist.toStdString();
    songar.close();

    std::ofstream songal;
    QString songal_dir = applcationDirectory + "Output/Album.txt";
    songal.open(songal_dir.toStdString().c_str());
    songal << songalbum.toStdString();
    songal.close();

    std::ofstream songid;
    QString songid_dir = applcationDirectory + "Output/ID.txt";
    songid.open(songid_dir.toStdString().c_str());
    songid << this->songid.toStdString();
    songid.close();

    if(prefix_bool == true)
    {
        QString main = prefix_name;

        if(main.contains("%1"))
        {
            main.replace("%1", songname);
        }
        if(main.contains("%2"))
        {
            main.replace("%2", songartist);
        }
        if(main.contains("%3"))
        {
            main.replace("%3", songalbum);
        }
        if(main.contains("%4"))
        {
            main.replace("%4", this->songid);
        }

        for(int a = 0; a < main.size(); a++)
        {
            if(main.contains("\n"))
            {
                main.replace("\n", "");
            }
        }

        //qDebug() << main;
    std::ofstream custom;
    QString custom_dir = applcationDirectory + "Output/Custom.txt";
    custom.open(custom_dir.toStdString().c_str());
    custom << main.toStdString();
    custom.close();
    }

    /*std::ofstream songnart;
    QString songname_dir = applcationDirectory + "Songname.txt";
    songn.open(songname_dir.toStdString().c_str());
    songn << songname.toStdString();
    songn.close();*/
}

void MainWindow::on_Prefix_CheckBox_clicked(bool checked)
{
    this->prefix_bool = checked;
    ui->EditPrefix_Button->setEnabled(prefix_bool);
    //on_EditPrefix_Button_clicked();
}

void MainWindow::on_EditPrefix_Button_clicked()
{
    //ui->EditPrefix_Button->setEnabled(this->prefix);
    prefix = new Prefix;
    prefix->setText(this->prefix_name);
    prefix->exec();
    this->prefix_name = prefix->getText();

    QString applcationDirectory = QApplication::applicationDirPath();
    QString applcationName = QApplication::applicationName() + ".app/Contents/MacOS";
    applcationDirectory.replace(applcationName, "");
    std::ofstream data;
    QString data_prefix = applcationDirectory + "Data/Prefix(Do not delete this).txt";
    data.open(data_prefix.toStdString().c_str());
    data << prefix_name.toStdString();
    data.close();
}

void MainWindow::on_actionAbout_triggered()
{
    About about;
    about.exec();
}

void MainWindow::on_actionDonation_triggered()
{
    Donate donate;
    donate.exec();
}
