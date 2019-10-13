#include "fsmodel.h"
#include <QDebug>
#include <QVector>
#include <QPainter>
#include <QDir>

Q_GLOBAL_STATIC(CSVParser, csvParser)
#define REDPENWIDTH 5

FileSystemModel::FileSystemModel(QObject *parent): QAbstractListModel(parent)
{
    m_names.clear();
    m_pixes.clear();
    fileCount = 0;
}

QVariant FileSystemModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    if(index.row()>= m_names.size())
        return QVariant();

    if(role == Qt::DisplayRole){
        return QVariant(); // m_names.at(index.row());
    } else if (role == Qt::DecorationRole) {
        QPixmap newImage; // (QSize(gridSize,gridSize));
        if(!newImage.load(m_rootPath+ "/" + m_names.at(index.row())))
            qDebug() << "cannot load file:" << m_rootPath+ "/" + m_names.at(index.row());
        const BBoxInfo *bboxes = csvParser->getBbox(m_names.at(index.row()));
        if(bboxes!=nullptr){
            QPainter painter(&newImage);
            for(int i=0; i < bboxes->rects()->count();i++){
                QPen pen; pen.setColor("red"); pen.setWidth(REDPENWIDTH);
                painter.setPen(pen);
                painter.drawRect(bboxes->rects()->at(i)->x()*newImage.width(),
                                 bboxes->rects()->at(i)->y()*newImage.height(),
                                 bboxes->rects()->at(i)->width()*newImage.width(),
                                 bboxes->rects()->at(i)->height()*newImage.height());
            }
        }
        return newImage.scaled(QSize(gridSize,gridSize),Qt::KeepAspectRatio);
    }else
        return QVariant();
}

void FileSystemModel::setRootPath(QString path)
{
    m_rootPath = path;

    QDir directory(m_rootPath);
    QStringList imageList = directory.entryList(QStringList() << "*.jpg" << "*.JPG", QDir::Files);

    int i=0;
    foreach (QString fileName, imageList) {
        m_names.insert(i,fileName);
        i++;
    }
}

bool FileSystemModel::canFetchMore(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    if(fileCount < m_names.count())
        return true;
    else
        return false;
}

void FileSystemModel::fetchMore(const QModelIndex &parent)
{
    Q_UNUSED(parent)
    int reminder = m_names.count() - fileCount;
    int itemsToFetch = qMin(10,reminder);

    if(itemsToFetch <=0)
        return;
    beginInsertRows(QModelIndex(), fileCount, fileCount + itemsToFetch -1);
    fileCount += itemsToFetch;
    endInsertRows();
}

int FileSystemModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return fileCount;
}
