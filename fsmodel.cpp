#include "fsmodel.h"
#include<QDebug>

FileSystemModel::FileSystemModel(QObject *parent): QFileSystemModel(parent)
{

}

QVariant FileSystemModel::data(const QModelIndex &index, int role) const
{
//    if(role==QFileSystemModel::FileNameRole && index.column()==0){
//        QString name = fileName(index);
//        return name;
//    }
    if(role==Qt::DisplayRole){
        QString aname = filePath(index);
//        qDebug() << aname;
        return aname;
//          return QVariant();
    }
    return QVariant();
//    return QFileSystemModel::data(index, role);
}
