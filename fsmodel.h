#ifndef FILESYSTEMMODEL_H
#define FILESYSTEMMODEL_H

#include <QAbstractListModel>

class FileSystemModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit FileSystemModel(QObject *parent = nullptr);
    ~FileSystemModel()  override;

    QVariant data(const QModelIndex &index, int role) const override;
    int rowCount(const QModelIndex &parent) const override;

    void setGridSize(int size){gridSize = size;}
    void setRootPath(QString path);

private:
    QVector<QImage> m_images;
    QStringList m_imageList;
    int gridSize;
    QString m_rootPath;
    void addPics();
    void addPic(QImage image);

};

#endif // FILESYSTEMMODEL_H
