#include "fsmodel.h"
#include<QDebug>
#include <QVector>
#include <QImageReader>

FileSystemModel::FileSystemModel(QObject *parent): QAbstractListModel(parent)
{
    m_fileNames.clear();

}

FileSystemModel::~FileSystemModel()
{

}

QVariant FileSystemModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    if(role==Qt::DecorationRole && index.column()==0x0 ){
//            qDebug() << "role DecorationRole index.row() " << index.row();
            if(m_images.count()>index.row())
                return m_images.at(index.row());
            else
                QVariant();
    } else {
        return QVariant();
    }

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
}

int FileSystemModel::columnCount(const QModelIndex &parent) const
{
    return 5;
}

QModelIndex FileSystemModel::index(int row, int column, const QModelIndex &parent) const
{
    return QModelIndex();
}

int FileSystemModel::rowCount(const QModelIndex &parent) const
{
    return 1;
}

void FileSystemModel::addPics()
{
    qDebug() << "add Pics" ;

}
