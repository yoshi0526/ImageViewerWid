#include "fsmodel.h"
#include<QDebug>
#include <QVector>
#include <QDir>

FileSystemModel::FileSystemModel(QObject *parent): QAbstractListModel(parent)
{
    m_names.clear();
    m_pixes.clear();
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
        return m_pixes.at(index.row()).scaled(QSize(gridSize,gridSize),Qt::KeepAspectRatio);
    }else
        return QVariant();
}

void FileSystemModel::addPic(int n)
{
    QPixmap newImage; // (QSize(gridSize,gridSize));
    if(!newImage.load(m_rootPath+ "/" + m_names.at(n)))
        qDebug() << "cannot load file:" << m_rootPath+ "/" + m_names.at(n);

    m_pixes.insert(n,newImage);
    qDebug() << "addPic " << m_names.count();

}

void FileSystemModel::setRootPath(QString path)
{
    m_rootPath = path;
    addPics();
}

int FileSystemModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_names.count();
}

void FileSystemModel::addPics()
{
    QDir directory(m_rootPath);
    QStringList imageList = directory.entryList(QStringList() << "*.jpg" << "*.JPG", QDir::Files);

    int i=0;
    foreach (QString fileName, imageList) {
//        qDebug() << fileName << i;
        m_names.insert(i,fileName);
        addPic(i);
        i++;
    }

}
