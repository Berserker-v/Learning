#include "dataconvert.h"

DataConvert::DataConvert(QObject *parent) : QObject(parent)
{

}

/**
 * @brief HEX字符形式转换为HEX数据
 * @param 字符串形式HEX数据
 * @param 预留内存长度 默认256字节
 * @return QByteArray指针
 */
QByteArray* DataConvert::QString2Hex(const QString &string, int memory)
{
    auto str = string;
    // 去除字符串间的空格
    str.replace(" ","");
    int length = str.length() - str.length()%2;
    char heighHex, lowHex, ch;
    // 新建ByteArray并保留memory长度内存
    QByteArray *pHexByte = new QByteArray();
    pHexByte->reserve(memory);
    // 转换过程
    for(int i=0;i<length;i+=2)
    {
        if(i>(length)) break;
        // 将每个字符转换为对应的HEX数据
        heighHex = Char2Hex(str.at(i).toLatin1());
        lowHex   = Char2Hex(str.at(i+1).toLatin1());
        // 将两个HEX数据拼接表示为一个字节
        ch = 0x10*heighHex + lowHex;
        pHexByte->append(ch);
    }
    // 字符串末尾出现单字符情况
    if(str.length()%2 != 0)
    {
        lowHex = Char2Hex(str.back().toLatin1());
        pHexByte->append(lowHex);
    }
    return pHexByte;
}

/**
 * @brief 字符形式HEX转换为HEX字节高/低位
 * @param 字符形式HEX
 * @return 4位HEX
 */
char DataConvert::Char2Hex(const char &ch)
{
    if(ch>='0' && ch<='9')
        return ch-0x30;
    else if(ch>='a' && ch<='f')
        return ch-'a'+0x0a;
    else if(ch>='A' && ch<='F')
        return ch-'A'+0x0a;
    else
        return 0x00;
}

