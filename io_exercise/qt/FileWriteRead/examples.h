#ifndef EXAMPLES_H
#define EXAMPLES_H
#include <QFile>
#include <QDataStream>
#include <QTextStream>
#include <QList>
#include <QVector>

#include "dataconvert.h"

QVector<QVector<double>>* ReadBinFile(QFile &file);

QVector<QVector<double>>* ReadTextFile(QFile &file);

QVector<QVector<double>>* ReadHexFile(QFile &file);

void WriteTextFile(QFile &file, QVector<QVector<double>> *pdata);

void WriteBinFile(QFile &file, QVector<QVector<double>> *pdata);

#endif // EXAMPLES_H
