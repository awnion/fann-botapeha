#include "captcha.h"

const int Captcha::symbol_count = 4;

Captcha::Captcha()
{
}

Captcha::Captcha(const QString &image_file)
{
    this->image_file = image_file;
    this->init_image = QImage(image_file).convertToFormat(QImage::Format_RGB32);
    this->current_image = QImage(init_image);
    this->symbols = QVector<Symbol>();
    this->isCleared = false;
}

void Captcha::ClearBg()
{
    if (this->isCleared) return;

    this->isCleared = true;

    QImage bg[2] = {
        QImage("../captcha/bg/bg1.png").convertToFormat(QImage::Format_RGB32),
        QImage("../captcha/bg/bg2.png").convertToFormat(QImage::Format_RGB32)
    };

    uint tmp = 0;

    for (int x = 0; x < current_image.width(); x++)
    {
        tmp += current_image.pixel(x, 0) - bg[1].pixel(x, 0);
    }

    int curent = tmp == 0 ? 1 : 0;

    for (int x = 0; x < current_image.width(); x++)
    {
        for (int y = 0; y < current_image.height(); y++)
        {
            if (current_image.pixel(x, y) == bg[curent].pixel(x, y))
            {
                tmp = 0xFFFFFF;
            }
            else
            {
                tmp = current_image.pixel(x, y) - bg[curent].pixel(x, y);
            }
            current_image.setPixel(x, y, tmp);
        }

    }
}

int Captcha::isEmptyLine(int x)
{
    int isEmpty = 1;
    for (int y = 0; y < current_image.height(); y++)
    {
        if (current_image.pixel(x, y) != 0xFFFFFFFF)
        {
            isEmpty = 0;
            break;
        }
    }
    return isEmpty;
}

int Captcha::getTop(const int left, const int right)
{
    for (int y = 0; y < current_image.height(); y++)
    {
        for (int x = left; x < right; x++)
        {
            if (current_image.pixel(x, y) != 0xFFFFFFFF)
            {
                return y;
            }
        }
    }
    Q_ASSERT(false);
    return 0;
}

QImage Captcha::getSymbolImage(const int left, const int right, const int top)
{
    QImage image(15, 15, QImage::Format_RGB32);

    image.fill(0xFFFFFF);

    for (int y = top; y < current_image.height() && y < top + 15; y++)
    {
        for (int x = left; x < right; x++)
        {
            image.setPixel(x - left, y - top, current_image.pixel(x, y));
        }
    }
    return image;
}

void Captcha::FindSymbols()
{
    int finded = 0;
    int left = 0;

    for (int x = 0; x < current_image.width(); x++)
    {
        if (!finded && !isEmptyLine(x))
        {
            finded = 1;
            left = x;
        }

        if (finded && isEmptyLine(x))
        {
            if (x - left < 7) continue;

            finded = 0;

            int right = x;

            int top = getTop(left, right);

            symbols.push_back(Symbol(getSymbolImage(left, right, top)));
        }
    }
}

void Captcha::SaveToTest(const QString &test_file)
{
    QFile file(test_file);

    if (file.exists())
    {
        file.open(QIODevice::Append | QIODevice::Text);
    }
    else
    {
        file.open(QIODevice::WriteOnly | QIODevice::Text);
    }

    foreach(Symbol symbol, symbols)
    {
        if (symbol.getChar() != 0x0)
        {
            file.write(symbol.getStringInput().toAscii());
            file.write("\n");
            file.write(symbol.getStringOutput().toAscii());
            file.write("\n");
        }
    }

    file.close();

    QFile::remove(image_file);
}

QString Captcha::Parse(const QString &configuration_file)
{
    ClearBg();

    QString s("");
    foreach(Symbol symbol, symbols)
    {
        s += symbol.Parse(configuration_file);
    }

    return s;
}

QImage Captcha::getInitImage()
{
    return QImage(init_image);
}

QImage Captcha::getCurImage()
{
    return QImage(current_image);
}
