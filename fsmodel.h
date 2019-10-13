#ifndef FILESYSTEMMODEL_H
#define FILESYSTEMMODEL_H

#include <QAbstractListModel>
#include <QPixmap>
#include "csvparser.h"

class FileSystemModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit FileSystemModel(QObject *parent = nullptr);

    QVariant data(const QModelIndex &index, int role) const override;
    int rowCount(const QModelIndex &parent) const override;

    void setGridSize(int size){gridSize = size;}
    void setRootPath(QString path);

protected:
    bool canFetchMore(const QModelIndex &parent) const override;
    void fetchMore(const QModelIndex &parent) override;

private:
    QVector<QString> m_names;
    QVector<QPixmap> m_pixes;
    int gridSize;
    int fileCount;
    QString m_rootPath;
};

#endif // FILESYSTEMMODEL_H
