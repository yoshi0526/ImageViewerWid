#include "csvparser.h"

#include <QFile>

#include <QDebug>

BBoxInfo::BBoxInfo() :
    m_rects(new QVector<QRectF*>)
{
}

BBoxInfo::~BBoxInfo()
{
    foreach (auto rect, *m_rects)
        delete rect;
    delete m_rects;
}

void BBoxInfo::addRect(QRectF* rect)
{
    m_rects->append(rect);
}

QVector<QRectF*>* BBoxInfo::rects() const
{
    return m_rects;
}

CSVParser::CSVParser() :
    m_basePath("../openimage/"),
    m_csvName("validation-annotations-bbox.csv")
{
    loadData();
};


CSVParser::~CSVParser()
{
    clearData();
}

QString CSVParser::basePath() const
{
    return m_basePath;
}

QString CSVParser::csvName() const
{
    return m_csvName;
}

void CSVParser::setBasePath(const QString &basePath)
{
    if (basePath == m_basePath)
        return;

    clearData();
    loadData();

    m_basePath = basePath;
}

void CSVParser::setCsvName(const QString &csvName)
{
    if (csvName == m_csvName)
        return;

    clearData();
    loadData();

    m_csvName = csvName;
}

BBoxInfo* CSVParser::getBbox(const QString& imageName) const
{
    return m_hashmap.value(imageName.section(".",0,0));
}

void CSVParser::clearData()
{
    foreach(auto element, m_hashmap)
        delete element;
}

void CSVParser::loadData()
{
    QFile file(basePath()+csvName());
    if (!file.open(QFile::ReadOnly))
        qDebug() << "failed to open : " << basePath()+csvName();

    QTextStream ts(&file);
    ts.readLine(); // skip the first line with tags
    while (!ts.atEnd()) {
        QString line = ts.readLine();
        auto elements = line.split(",");
        QString imageName = elements[0];
        qreal minX = elements[4].toDouble(), maxX = elements[5].toDouble();
        qreal minY = elements[6].toDouble(), maxY = elements[7].toDouble();
        auto itr_hash = m_hashmap.find(imageName);
        if (itr_hash == m_hashmap.end())
            itr_hash = m_hashmap.insert(imageName, new BBoxInfo);
        (*itr_hash)->addRect(new QRectF(QPointF(minX,minY),QPointF(maxX,maxY)));
    }
}
