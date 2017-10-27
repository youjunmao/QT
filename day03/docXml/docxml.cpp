#include "docxml.h"
#include<QFile>
#include<QDomDocument>//文件
#include<QDomProcessingInstruction>//格式头部
#include<QDomElement>//元素
#include<QDebug>
#include<QTextStream>
#define cout qDebug()<<"["<<__FILE__<<":"<<__LINE__<<"]"
DocXml::DocXml()
{

}

void DocXml::createXml(QString fileName)
{
    QFile file(fileName);
    if(true==file.exists())
    {
        cout<<"文件已经存在";
        return;
    }
    else
    {
        bool isOpen=file.open(QIODevice::WriteOnly);
        if(true==isOpen)
        {
            //创建对象
            QDomDocument doc;
            //创建格式对象
            QDomProcessingInstruction ins;
            ins=doc.createProcessingInstruction("xml","version=\'1.0\' encoding='utf-8'");
            //追加元素
            doc.appendChild(ins);
            //根节点元素
            QDomElement root=doc.createElement("日期");
            doc.appendChild(root);
            //保存
            QTextStream stream(&file);//文本流关联文件
            doc.save(stream,4);

            file.close();//关闭文件
        }
        else
        {
            cout<<"打开失败";
        }
    }
}
