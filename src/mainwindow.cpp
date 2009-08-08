#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->on_parseButton_clicked();

    setWindowTitle("botAPEHA");
}

MainWindow::~MainWindow()
{
    delete ui;
}

Captcha *c;

void MainWindow::on_parseButton_clicked()
{
    ui->saveButton->setEnabled(false);

    QDir dir("../captcha/test");

    if (dir.exists())
    {
        QStringList list = dir.entryList();

        if (list.count() < 3) // if directory is empty
        {
            return;
        }

        c = new Captcha(dir.path() + "/" + list.at(2));

        c->ClearBg();

        QPixmap pm;

        pm = QPixmap::fromImage(c->getInitImage());
        ui->img1->setPixmap(pm);
        pm = QPixmap::fromImage(c->getCurImage());
        ui->img2->setPixmap(pm);
        pm = QPixmap::fromImage(c->getCurImage().scaled(180, 60));
        ui->label->setPixmap(pm);

        c->FindSymbols();

        ui->label1->setPixmap(QPixmap::fromImage(c->symbols[0].getImage()));
        ui->label2->setPixmap(QPixmap::fromImage(c->symbols[1].getImage()));
        ui->label3->setPixmap(QPixmap::fromImage(c->symbols[2].getImage()));
        ui->label4->setPixmap(QPixmap::fromImage(c->symbols[3].getImage()));

        ui->lineEdit->setText(c->Parse("../captcha/ann.net"));

        ui->saveButton->setEnabled(true);
    }
}

void MainWindow::on_saveButton_clicked()
{
    if (c == NULL) return;

    if (ui->lineEdit->text().length() == 4)
    {
        for(int i = 0; i < 4; i++)
        {
            c->symbols[i].setChar(ui->lineEdit->text()[i].toAscii());
        }

        c->SaveToTest("../captcha/data");
    }

    delete c;

    ui->lineEdit->setText("");

    this->on_parseButton_clicked();

    ui->lineEdit->setFocus();
}

void MainWindow::on_pushButton_2_clicked()
{
    QFile file("../captcha/data");
    file.open(QIODevice::ReadOnly);

    int numlines = 0;
    char tmp[3000];
    while (file.readLine(tmp, sizeof(tmp)) != -1) numlines++;

    file.close();

    file.open(QIODevice::ReadOnly);

    QFile train_file("../captcha/ann.train");
    train_file.open(QIODevice::WriteOnly);
    train_file.write(QString("%1 225 20\n").arg(numlines/2).toAscii());
    train_file.write(file.readAll());
    file.close();
    train_file.close();

    if (QFile::exists("../captcha/ann.test"))
    {
        QFile::remove("../captcha/ann.test");
    }
    train_file.copy("../captcha/ann.test");
}

QNetworkReply *reply;
QNetworkReply *reply2;
QString image_file;

void MainWindow::on_pushButton_3_clicked()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    QUrl url("http://utes.apeha.ru/user_add_2.html");

    QNetworkRequest request(url);
    request.setRawHeader("Referer", "http://apeha.ru/user_add_1.html");
    request.setRawHeader("User-Agent", "Mozilla/5.0");
    request.setRawHeader("Accept-Charset", "windows-1251,utf-8;q=0.7,*;q=0.7");

    reply = manager->post(request, "User%7Bnick%7D=&User%7Bemail%7D=&User%7Bfname%7D=&User%7Blname%7D=&User%7BFemale%7D=0&User%7BDay%7D=0&User%7BMon%7D=0&User%7BYea%7D=0&User%7Btown%7D=&User%7Bdeviz%7D=&User%7Bhobby%7D=&User%7Bistinf%7D=&User%7Bruid%7D=");
    connect(reply, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
}

void MainWindow::slotReadyRead()
{
    reply->open(QIODevice::ReadOnly);
    for (int i = 0; i < 46; i++)
    {
        reply->readLine();
    }

    image_file = QString(reply->readLine(2000)).mid(10, 52);

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    QUrl url(image_file);

    QNetworkRequest request(url);
    request.setRawHeader("Referer", "http://apeha.ru/user_add_2.html");
    request.setRawHeader("User-Agent", "Mozilla/5.0");
    request.setRawHeader("Accept-Charset", "windows-1251,utf-8;q=0.7,*;q=0.7");

    reply2 = manager->get(request);
    connect(reply2, SIGNAL(readyRead()), this, SLOT(slotReadyReadImage()));
}

void MainWindow::slotReadyReadImage()
{
    reply2->open(QIODevice::ReadOnly);
    reply2->setTextModeEnabled(false);

    QFile file("../captcha/test/" + image_file.mid(45, 7) + ".png");
    file.open(QIODevice::WriteOnly);
    file.write(reply2->readAll());
    file.close();

    this->on_parseButton_clicked();

    ui->statusBar->showMessage("Image loaded.", 10000);
}

void MainWindow::on_lineEdit_returnPressed()
{
    this->on_saveButton_clicked();
}
