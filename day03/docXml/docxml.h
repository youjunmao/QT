#ifndef DOCXML_H
#define DOCXML_H
#include<QString>
#include<QStringList>
#include<QDomDocument>
#include<QDomElement>
class DocXml
{
public:
    DocXml();
    static void createXml(QString fileName);
    static void appendXml(QString filename,QStringList list);
    static void writeXml(QDomDocument &doc,QDomElement &root,QStringList& list);
    static void readXml(QString filename);
};

#endif // DOCXML_H
