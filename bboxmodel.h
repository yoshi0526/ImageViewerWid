#ifndef BBOXMODEL_H
#define BBOXMODEL_H

#include <QAbstractListModel>
#include <QVector>
#include <QRectF>

class BBoxModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(QString imageName READ imageName WRITE setImageName NOTIFY imageNameChanged)
public:
    enum BBoxRoles {
        RectRole = Qt::UserRole + 1
    };

    explicit BBoxModel(QObject *parent = nullptr);

    QString imageName();
    void setImageName(QString imageName);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
signals:
    void imageNameChanged();

private:
    QString m_imageName;
    QVector<QRectF*> m_boxes;
};

#endif // BBOXMODEL_H
