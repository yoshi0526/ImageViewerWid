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
    void addPic(QImage image);
    void setGridSize(int size){gridSize = size;}
    void setRootPath(QString path);
    int columnCount(const QModelIndex &parent) const override;
    QModelIndex index(int row, int column = 0, const QModelIndex &parent = QModelIndex()) const override;
    int rowCount(const QModelIndex &parent) const override;
private:
    QVector<QImage> m_images;
    QVector<QString> m_fileNames;
    int gridSize;
    QString m_rootPath;
private slots:
    void addPics();

};

#endif // FILESYSTEMMODEL_H
