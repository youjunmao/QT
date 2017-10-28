#include "docxml.h"
#include<QFile>
#include<QDomDocument>//文件
#include<QDomProcessingInstruction>//格式头部
#include<QDomElement>//元素
#include<QDebug>
#include<QTextStream>
#include<QDateTime>
#define cout qDebug()<<"["<<__FILE__<<":"<<__LINE__<<"]"
DocXml::DocXml()
{

}

void DocXml::readXml(QString filename)
{
    QFile file(filename);
    bool isOpen=file.open(QIODevice::ReadOnly);
    if(true==isOpen)
    {
        QDomDocument doc;
        isOpen=doc.setContent(&file);
        if(true==isOpen)
        {
            file.close();
            //获取根节点
            QDomElement root=doc.documentElement();
            //获取当前时间
            QDateTime   date=QDateTime::currentDateTime();
            QString     dateStr=date.toString("yyyy-MM-dd");

            if(root.hasChildNodes())
            {
                QDomElement lastElemt=root.lastChildElement();
                if(lastElemt.attribute("date")==dateStr)
                {
                    QDomNodeList list=lastElemt.childNodes();
                    for(int i=0;i<list.size();i++)
                    {
                        QDomNodeList subList=list.at(i).toElement().childNodes();
                        for(int j=0;j<subList.size();j++)
                        {
                            cout<<subList.at(j).toElement().text();
                        }
                    }
                }
                else
                {
                    cout<<"no curDate data";
                }
            }
        }
        else
        {
            cout<<"setContent fail";
        }
    }
    else
    {
        cout<<"open fail";
    }
}

void DocXml::writeXml(QDomDocument &doc, QDomElement &root, QStringList& list)
{
    QDateTime   curTime=QDateTime::currentDateTime();
    QString     timeStr=curTime.toString("h:m:s");

    QDomElement dateElemt=doc.createElement("时间");
    root.appendChild(dateElemt);

    QDomAttr    dateAttr=doc.createAttribute("time");
    dateAttr.setNodeValue(timeStr);
    dateElemt.setAttributeNode(dateAttr);

    for(int i=0;i<list.size();i++)
    {
        //QString elementStr=QString("%1 %2").arg(list.at(i)).arg(i);
        QDomElement element=doc.createElement(list.at(i));
        dateElemt.appendChild(element);

        element.appendChild(doc.createTextNode(list.at(i)));
    }
}

void DocXml::appendXml(QString filename, QStringList list)
{
    QFile file(filename);
    bool isOpen=file.open(QIODevice::ReadOnly);
    if(true==isOpen)
    {
        QDomDocument doc;
        isOpen=doc.setContent(&file);
        if(true==isOpen)
        {
            file.close();
            //获取根节点
            QDomElement root=doc.documentElement();
            //获取当前时间
            QDateTime   date=QDateTime::currentDateTime();
            QString     dateStr=date.toString("yyyy-MM-dd");
            //
            if(!root.hasChildNodes())
            {
                QDomElement dateElemt=doc.createElement("日期");
                root.appendChild(dateElemt);

                QDomAttr    dateAttr=doc.createAttribute("date");
                dateAttr.setNodeValue(dateStr);
                dateElemt.setAttributeNode(dateAttr);

                DocXml::writeXml(doc, dateElemt, list);
            }
            else
            {
                QDomElement lastElemt=root.lastChildElement();
                if(lastElemt.attribute("date")==dateStr)
                {
                    DocXml::writeXml(doc,lastElemt,list);
                }
                else
                {
                    QDomElement dateElemt=doc.createElement("日期");
                    root.appendChild(dateElemt);

                    QDomAttr    dateAttr=doc.createAttribute("date");
                    dateAttr.setNodeValue(dateStr);
                    dateElemt.setAttributeNode(dateAttr);

                    DocXml::writeXml(doc, dateElemt, list);
                }
            }
            isOpen=file.open(QIODevice::WriteOnly);
            if(true==isOpen)
            {
                QTextStream stream(&file);
                doc.save(stream,4);
                file.close();
            }
        }
        else
        {
            cout<<" set Contene fail";
        }
    }
    else
    {
        cout<<"open fail";
    }
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
            QDomElement root=doc.createElement("日期销售清单");
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
