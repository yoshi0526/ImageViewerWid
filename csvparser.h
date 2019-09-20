#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <QString>
#include <QHash>
#include <QVector>
#include <QRectF>

class BBoxInfo {
public:
    BBoxInfo();
    ~BBoxInfo();
    void addRect(QRectF*);
    QVector<QRectF*>* rects() const;
private:
    QVector<QRectF*>* m_rects;
};

class CSVParser
{
public:
    explicit CSVParser();
    ~CSVParser();

    QString basePath() const;
    QString csvName() const;
    void setBasePath(const QString &basePath);
    void setCsvName(const QString &csvName);

    BBoxInfo* getBbox(const QString& imageName) const;

private:
    void clearData();
    void loadData();

private:
    QString m_basePath;
    QString m_csvName;
    QHash<QString, BBoxInfo*> m_hashmap;
};

#endif // CSVPARSER_H
