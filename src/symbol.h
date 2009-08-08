#ifndef SYMBOL_H
#define SYMBOL_H

#include <QImage>

#include "fann.h"
#include "fann_cpp.h"

class Symbol
{
private:
    QImage image;
    QChar ch;

public:
    static const QString char_table;
    static const int height;
    static const int width;

    Symbol();
    Symbol(const QImage &image);

    float *getArrayInput();
    float *getArrayOutput();

    QString getStringInput();
    QString getStringOutput();

    void setChar(const QChar &c);
    QChar getChar();

    QChar Parse(const QString &configuration_file);

    QImage getImage();
};

#endif // SYMBOL_H
