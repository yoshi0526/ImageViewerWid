#include "fsmodel.h"
#include<QDebug>
#include <QImageReader>

FileSystemModel::FileSystemModel(QObject *parent): QFileSystemModel(parent)
{
    connect(this, &FileSystemModel::directoryLoaded, this, &FileSystemModel::addPics);
}

QVariant FileSystemModel::data(const QModelIndex &index, int role) const
{

    if(!index.isValid())
        return QVariant();

//    if(role==QFileSystemModel::FileNameRole && index.column()==0){
//        QString name = fileName(index);
//        return name;
//    }
//    if(role==Qt::DisplayRole){

//        QString aname = filePath(index);
//        QImageReader reader(aname);
//        reader.setAutoTransform(true);
//        const QImage newImage = reader.read();
//        return reader.size(); // aname;
//          return QVariant();
//    }
//    return QVariant();
    return QFileSystemModel::data(index, role);
}

void FileSystemModel::addPic(const QPixmap &pixmap)
{
    if (!pixmaps.isEmpty()) {
        beginRemoveRows(QModelIndex(), 0, pixmaps.size() - 1);
        pixmaps.clear();
        endRemoveRows();
    }
    QPixmap image = pixmap.scaled(30,30);
    beginInsertRows(QModelIndex(), 0, 0);
    pixmaps.insert(0, pixmap);
    endInsertRows();
}

void FileSystemModel::addPics()
{
    qDebug() << "add Pics" ;
    for (int i = 0; i < rowCount(this->index(rootPath())); i++) {
        qDebug() << " i:" << i;
        QPixmap apixmap;
//        addPic(apixmap);
    }
}
