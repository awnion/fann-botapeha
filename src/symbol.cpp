#include "symbol.h"

const QString Symbol::char_table = "0123456789abcdefghjk";
const int Symbol::height = 15;
const int Symbol::width = 15;

Symbol::Symbol()
{
}

Symbol::Symbol(const QImage &image)
{
    this->image = QImage(image);
    this->ch = 0x0;
}

float *Symbol::getArrayInput()
{
    float *tmp = new float[image.width() * image.height()];

    for(int x = 0; x < image.width(); x++)
    {
        for(int y = 0; y < image.height(); y++)
        {
            tmp[y * image.width() + x] = (float) qGray(image.pixel(x, y)) / 255;
        }
    }
    return tmp;
}

float *Symbol::getArrayOutput()
{
    float *tmp = new float[char_table.length()];
    for(int i = 0; i < char_table.length(); i++)
    {
        tmp[i] = i == char_table.indexOf(ch) ? 1 : 0;
    }
    return tmp;
}

QString Symbol::getStringInput()
{
    QString s("");
    float *array = this->getArrayInput();

    for(int i = 0; i < image.width() * image.height(); i++)
    {
        s += QString("%1 ").arg(array[i],0,'E');
    }
    return s;
}

QString Symbol::getStringOutput()
{
    QString s("");
    float *array = this->getArrayOutput();

    for(int i = 0; i < char_table.length(); i++)
    {
        s += QString("%1 ").arg(array[i]);
    }
    return s;
}

void Symbol::setChar(const QChar &ch)
{
    this->ch = ch;
}

QChar Symbol::getChar()
{
    return this->ch;
}

QChar Symbol::Parse(const QString &configuration_file)
{
    float *output;

    FANN::neural_net *ann = new FANN::neural_net();
    ann->create_from_file(configuration_file.toStdString());

    output = ann->run(this->getArrayInput());

    int max = 0;
    for(int i = 1; i < char_table.length(); i++)
    {
        if (output[max] < output[i] )
        {
            max = i;
        }
    }

    ann->destroy();
    delete ann;

    return char_table.at(max);
}

QImage Symbol::getImage()
{
    return QImage(image);
}
