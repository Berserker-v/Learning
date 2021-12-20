#include "examples.h"

const uint32_t COLUMN = 10;

/**
 * @brief 读取二进制文件
 * @param 文件
 * @return 二维Vector指针
 */
QVector<QVector<double>>* ReadBinFile(QFile &file)
{
    // 设置小端模式
    QDataStream in(&file);
    in.setByteOrder(QDataStream::LittleEndian);
    // 使用二维Vector保存数据
    QVector<QVector<double>> *pavpVector = new QVector<QVector<double>>();
    while(!in.atEnd()) {
        QVector<double> avp;
        for(uint32_t i=0;i<COLUMN;++i) {
            double temp;
            in >> temp;
            avp.append(temp);
        }
        pavpVector->append(avp);
    }
    return pavpVector;
}

/**
 * @brief 读取文本文件
 * @param 文件
 * @return 二维Vector指针
 */
QVector<QVector<double> >* ReadTextFile(QFile &file)
{
    QTextStream in(&file);
    // 使用二维Vector保存数据
    QVector<QVector<double>> *pavpVector = new QVector<QVector<double>>();
    // 过滤表头
    in.readLine();
    while (!in.atEnd()) {
        QVector<double> avp;
        for(uint32_t i=0;i<COLUMN;++i) {
            double temp;
            in >> temp;
            avp.append(temp);
        }
        pavpVector->append(avp);
    }
    return pavpVector;
}

/**
 * @brief 写入文本文件
 * @param 文件
 * @param 二维Vector指针
 */
void WriteTextFile(QFile &file, QVector<QVector<double>> *pdata)
{
    QTextStream out(&file);
    // 写入表头
    out << qSetFieldWidth(16) << Qt::right
        << "pitch(rad)" << "roll(rad)" << "yaw(rad)"
        << "VE(m/s)"    << "VN(m/s)"   << "VU(m/s)"
        << "Lat(rad)"   << "Lng(rad)"  << "H(m)" << "Time(s)"  <<  Qt::endl;
    // 写入文本数据
    for(int i=0; i<pdata->length(); ++i) {
        for(uint32_t j=0; j<COLUMN; ++j) {
            out << Qt::fixed << qSetRealNumberPrecision(9) << pdata->at(i).at(j);
        }
        out << Qt::endl;
    }
}

/**
 * @brief 写入二进制文件
 * @param 文件
 * @param 二维Vector指针
 */
void WriteBinFile(QFile &file, QVector<QVector<double> > *pdata)
{
    QDataStream out(&file);
    out.setByteOrder(QDataStream::LittleEndian);
    // 写入二进制数据
    for(int i=0; i<pdata->length(); ++i) {
        for(uint32_t j=0; j<COLUMN; ++j) {
            out << pdata->at(i).at(j);
        }
    }
}

/**
 * @brief 读取十六进制文件
 * @param 文件
 * @return 二维vector指针
 */
QVector<QVector<double>>* ReadHexFile(QFile &file)
{
    QTextStream in(&file);
    in.skipWhiteSpace();
    // 使用二维Vector保存数据
    QVector<QVector<double>> *pavpVector = new QVector<QVector<double>>();
    while(!in.atEnd())
    {
        QVector<double> avp;
        QString str = in.read(24*COLUMN);
        QByteArray *pBA = DataConvert::QString2Hex(str,24*COLUMN);
        char *pdata = pBA->data();
        double *pRow = new double[COLUMN];
        DataConvert::Bytes2Number<double>(pRow,pdata,COLUMN,QSysInfo::BigEndian);
        for(uint32_t i=0;i<COLUMN; ++i) {
            avp.append(pRow[i]);
        }
        pavpVector->append(avp);
    }
    return pavpVector;
}








