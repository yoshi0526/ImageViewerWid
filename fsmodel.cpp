#include "fsmodel.h"
#include<QDebug>
#include <QVector>
#include <QImageReader>
#include <QDir>

FileSystemModel::FileSystemModel(QObject *parent): QAbstractListModel(parent)
{
    m_imageList.clear();
    m_images.clear();
}

FileSystemModel::~FileSystemModel()
{

}

QVariant FileSystemModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    return QVariant();
}

void FileSystemModel::addPic(QImage image)
{
    beginInsertRows(QModelIndex(), 0, 0);
    m_images.insert(0, image);
    endInsertRows();
    qDebug() << "addPic " << m_images.count();
}

void FileSystemModel::setRootPath(QString path)
{
    m_rootPath = path;
    addPics();
}

int FileSystemModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QModelIndex FileSystemModel::index(int row, int column, const QModelIndex &parent) const
{
    return QModelIndex();
}

int FileSystemModel::rowCount(const QModelIndex &parent) const
{
    return m_images.count();
}

void FileSystemModel::addPics()
{
    QDir directory(m_rootPath);
    m_imageList = directory.entryList(QStringList() << "*.jpg" << "*.JPG", QDir::Files);

    qDebug() << "add " << m_imageList.count() << " Pics" ;
    foreach (QString fileName, m_imageList) {
        qDebug() << fileName;
    }

}
