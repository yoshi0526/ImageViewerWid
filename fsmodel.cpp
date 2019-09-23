#include "fsmodel.h"
#include<QDebug>
#include <QImageReader>

FileSystemModel::FileSystemModel(QObject *parent): QFileSystemModel(parent)
{

}

QVariant FileSystemModel::data(const QModelIndex &index, int role) const
{

//    if(!index.isValid())
//        return QVariant();


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
