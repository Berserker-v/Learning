#include <QCoreApplication>
#include <QMap>
#include <QFile>
#include <QDebug>
#include <QDataStream>
#include <QDir>
#include <QTextStream>
#include <QDebug>
#include <QtMath>
#include <QFileInfo>
#include <QElapsedTimer>

#include "dataconvert.h"
#include "examples.h"

#include <iostream>
#include <iomanip>
#include <malloc.h>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QElapsedTimer time;

    QString dataPath = QDir::currentPath() + "/data/";

    //读取二进制文件示例
    QFile file(dataPath+"trjavp.bin");

//    if(!file.open(QIODevice::ReadOnly)) {
//        qDebug() << "Can't open file for reading";
//        return 0;
//    }
//    time.start();
//    auto *pAvp = ReadBinFile(file);
//    qDebug() << "Reading bin file complete. Time cost: " << time.elapsed() << "ms";
//    file.close();

    //写入文本文件示例
//    file.setFileName(dataPath+"trjavpQt.txt");
//    if(!file.open(QIODevice::WriteOnly)) {
//        qDebug() << "Can't open file for writing";
//        return 0;
//    }
//    time.restart();
//    WriteTextFile(file, pAvp);
//    qDebug() << "Writing text file complete. Time cost: " << time.elapsed() << "ms";
//    file.close();

    //读取文本文件示例
//    file.setFileName(dataPath+"trjavpQt.txt");
//    if(!file.open(QIODevice::ReadOnly)) {
//        qDebug() << "Can't open file for writing";
//        return 0;
//    }
//    time.restart();
//    pAvp = ReadTextFile(file);
//    qDebug() << "Reading text file complete. Time cost: " << time.elapsed() << "ms";
//    file.close();

    //写入二进制文件示例
//    file.setFileName(dataPath+"trjavpQt.bin");
//    if(!file.open(QIODevice::WriteOnly)) {
//        qDebug() << "Can't open file for writing";
//        return 0;
//    }
//    time.restart();
//    WriteBinFile(file, pAvp);
//    qDebug() << "Writing bin file complete. Time cost: " << time.elapsed() << "ms";
//    file.close();

    //读取HEX形式文本文件示例
    file.setFileName(dataPath+"trjavphex.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Can't open file for writing";
        return 0;
    }
    time.restart();
    auto *pAvp = ReadHexFile(file);
    file.close();
    qDebug() << "Reading hex file complete. Time cost: " << time.elapsed() << "ms";

    //写入文本文件示例
    file.setFileName(dataPath+"trjavphexQt.txt");
    if(!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Can't open file for writing";
        return 0;
    }
    time.restart();
    WriteTextFile(file, pAvp);
    qDebug() << "Writing text file complete. Time cost: " << time.elapsed() << "ms";
    file.close();

    time.invalidate();
    return a.exec();
}








