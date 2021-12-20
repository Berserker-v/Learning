#ifndef DATACONVERT_H
#define DATACONVERT_H

#include <QObject>
#include <QByteArray>
#include <QString>

class DataConvert : public QObject
{
    Q_OBJECT
public:
    explicit DataConvert(QObject *parent = nullptr);

    static QByteArray* QString2Hex(const QString &string, int memory = 256);
    static char Char2Hex(const char &ch);
    template<typename T> static void Bytes2Number(T* pDst, char *pSrc, int cnt, int endian = QSysInfo::LittleEndian);

signals:

};

template <typename T>
void DataConvert::Bytes2Number(T* pDst, char *pSrc, int cnt, int endian)
{
    // 长度小于1返回
    if(cnt < 1) return;

    int size = sizeof(T);
    T* pCopy = pDst;
    // 读取cnt个T类型数据,每读取一次将 源字节指针向后偏移size T类型数据指针向后偏移1
    for(int i=0; i<cnt; ++i, ++pCopy, pSrc+=size) {
        if(QSysInfo::BigEndian == endian) {
            // 大端数据需要转换为小端数据后在复制内存
            char* pBigEndian = new char[size];
            for(int j=0;j<size;++j) pBigEndian[j] = pSrc[size-1-j];
            memcpy(pCopy, pBigEndian, size);
            delete [] pBigEndian;
        } else {
            // 小端模式可直接复制内存
            memcpy(pCopy, pSrc, size);
        }
    }   
}














#endif // DATACONVERT_H
