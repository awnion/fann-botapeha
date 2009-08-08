#ifndef CAPTCHA_H
#define CAPTCHA_H

#include <QtGui/QMainWindow>
#include <QFile>

#include "symbol.h"

class Captcha
{
private:
    QString image_file;
    QImage init_image;
    QImage current_image;
    int isEmptyLine(int x);
    int getTop(const int left, const int right);
    QImage getSymbolImage(const int left, const int right, const int top);

public:
    static const int symbol_count;

    bool isCleared;
    QVector<Symbol> symbols;

    Captcha();
    Captcha(const QString &image_file);

    void ClearBg();
    void FindSymbols();
    void SaveToTest(const QString &test_file);

    QString Parse(const QString &configuration_file);

    QImage getInitImage();
    QImage getCurImage();
};

#endif // CAPTCHA_H
