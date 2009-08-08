#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QFileInfo>
#include <QDir>
#include <QtNetwork>
#include "captcha.h"
#include "floatfann.h"
#include "fann_cpp.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void slotReadyRead();
    void slotReadyReadImage();

private slots:
    void on_lineEdit_returnPressed();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_saveButton_clicked();
    void on_parseButton_clicked();
};

#endif // MAINWINDOW_H
