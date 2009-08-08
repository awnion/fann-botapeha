/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Sat 8. Aug 02:53:37 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tabWidgetPage1;
    QWidget *tabWidgetPage2;
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *img1;
    QLabel *img2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLineEdit *lineEdit;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *parseButton;
    QPushButton *saveButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(470, 357);
        MainWindow->setMouseTracking(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 471, 341));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setSizeIncrement(QSize(0, 0));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(true);
        tabWidget->setMovable(false);
        tabWidgetPage1 = new QWidget();
        tabWidgetPage1->setObjectName(QString::fromUtf8("tabWidgetPage1"));
        tabWidget->addTab(tabWidgetPage1, QString());
        tabWidgetPage2 = new QWidget();
        tabWidgetPage2->setObjectName(QString::fromUtf8("tabWidgetPage2"));
        label = new QLabel(tabWidgetPage2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 110, 181, 61));
        horizontalLayoutWidget = new QWidget(tabWidgetPage2);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 70, 181, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setMargin(11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        img1 = new QLabel(horizontalLayoutWidget);
        img1->setObjectName(QString::fromUtf8("img1"));

        horizontalLayout->addWidget(img1);

        img2 = new QLabel(horizontalLayoutWidget);
        img2->setObjectName(QString::fromUtf8("img2"));

        horizontalLayout->addWidget(img2);

        horizontalLayoutWidget_2 = new QWidget(tabWidgetPage2);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 180, 101, 21));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setMargin(11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label1 = new QLabel(horizontalLayoutWidget_2);
        label1->setObjectName(QString::fromUtf8("label1"));

        horizontalLayout_2->addWidget(label1);

        label2 = new QLabel(horizontalLayoutWidget_2);
        label2->setObjectName(QString::fromUtf8("label2"));

        horizontalLayout_2->addWidget(label2);

        label3 = new QLabel(horizontalLayoutWidget_2);
        label3->setObjectName(QString::fromUtf8("label3"));

        horizontalLayout_2->addWidget(label3);

        label4 = new QLabel(horizontalLayoutWidget_2);
        label4->setObjectName(QString::fromUtf8("label4"));

        horizontalLayout_2->addWidget(label4);

        lineEdit = new QLineEdit(tabWidgetPage2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 210, 101, 35));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(18);
        lineEdit->setFont(font);
        lineEdit->setMaxLength(4);
        verticalLayoutWidget = new QWidget(tabWidgetPage2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(200, 70, 210, 221));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        parseButton = new QPushButton(verticalLayoutWidget);
        parseButton->setObjectName(QString::fromUtf8("parseButton"));
        parseButton->setMinimumSize(QSize(0, 30));
        QFont font1;
        font1.setPointSize(14);
        parseButton->setFont(font1);

        verticalLayout->addWidget(parseButton);

        saveButton = new QPushButton(verticalLayoutWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setEnabled(true);
        saveButton->setMinimumSize(QSize(0, 30));
        saveButton->setFont(font1);

        verticalLayout->addWidget(saveButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 30));
        pushButton_2->setFont(font1);

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 30));
        pushButton_3->setFont(font1);

        verticalLayout->addWidget(pushButton_3);

        label_2 = new QLabel(tabWidgetPage2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 441, 51));
        tabWidget->addTab(tabWidgetPage2, QString());
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(lineEdit, parseButton);
        QWidget::setTabOrder(parseButton, saveButton);
        QWidget::setTabOrder(saveButton, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton_3);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        centralWidget->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        tabWidget->setTabText(tabWidget->indexOf(tabWidgetPage1), QApplication::translate("MainWindow", "CAPTCHA \321\202\320\265\321\201\321\202\320\265\321\200", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        img1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        img2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        label1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        label2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        label3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        label4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        parseButton->setText(QApplication::translate("MainWindow", "Load image and parse", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\321\213\320\262\320\260\320\265\321\202 \320\264\320\260\320\275\320\275\321\213\320\265 \320\276 \321\200\320\260\321\201\320\277\320\276\321\200\321\201\320\265\320\275\320\275\320\276\320\271 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\320\265 \320\270 \321\203\320\264\320\260\320\273\321\217\320\265\321\202 \320\265\320\265.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveButton->setText(QApplication::translate("MainWindow", "Append this data", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Make train and test files", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 1 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\321\203 \321\201 APEHA.ru", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_3->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_3->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        pushButton_3->setText(QApplication::translate("MainWindow", "Load image from Inet", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">- \320\223\321\200\321\203\320\267\320\270\321\202 1-\321\216 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\321\203 \320\270\320\267 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\320\270 </span><span style=\" font-size:8pt; font-weight:600;\">../captcha/test</span><span style=\" font-size:8pt;\"> \320\270 \320\277\320\260\321\200\321\201\320\270\321\202 \320\265\320\265.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0;"
                        " text-indent:0px;\"><span style=\" font-size:8pt;\">- \320\235\320\265\320\271\321\200\320\276\320\275\320\275\320\260\321\217 \321\201\320\265\321\202\321\214 \320\273\320\265\320\266\320\270\321\202 \320\262 </span><span style=\" font-size:8pt; font-weight:600;\">../captcha/ann.net</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabWidgetPage2), QApplication::translate("MainWindow", "CAPTCHA \321\202\321\200\320\265\320\275\320\265\321\200", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
