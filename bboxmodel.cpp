#include "bboxmodel.h"

#include <QGlobalStatic>
#include "csvparser.h"

Q_GLOBAL_STATIC(CSVParser, csvParser)

BBoxModel::BBoxModel(QObject *parent) : QAbstractListModel(parent)
{
}

QString BBoxModel::imageName()
{
    return m_imageName;
}

void BBoxModel::setImageName(QString imageName)
{
    m_imageName = imageName;

    const BBoxInfo* bboxes = csvParser->getBbox(imageName);

    if (bboxes) {
        for (auto bbox : *bboxes->rects()) {
            m_boxes.append(bbox);
        }
    }

    emit imageNameChanged();
}

int BBoxModel::rowCount(const QModelIndex& /*parent*/) const
{
    return m_boxes.count();
}

QVariant BBoxModel::data(const QModelIndex& index, int /*role*/) const
{
    return index.isValid() ? *m_boxes.at(index.row()): QVariant();
}

QHash<int, QByteArray> BBoxModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[RectRole] = "rect";
    return roles;
}
