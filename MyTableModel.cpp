#include "MyTableModel.h"

const int COLUMN_COUNT = 3;

MyTableModel::MyTableModel(QObject *parent) :
    QAbstractTableModel(parent)
{
}

void MyTableModel::addMyData(MyData *data)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_datas << data;
    endInsertRows();
}

QVariant MyTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
            case 0:
                return "Name";
            case 1:
                return "Age";
            case 2:
                return "City";
            }
        }
    }
    return QVariant();
}

bool MyTableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}

int MyTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_datas.count();
}

int MyTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return COLUMN_COUNT;
}

QVariant MyTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole) {
        auto *data = m_datas.at(index.row());
        switch (index.column()) {
        case NameColumn:
            return data->name();
        case AgeColumn:
            return data->age();
        case CityColumn:
            return data->city();
        }
    }
    return QVariant();
}

bool MyTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        auto *data = m_datas.at(index.row());
        switch (index.column()) {
        case NameColumn:
            data->setName(value.toString());
            break;
        case AgeColumn:
            data->setAge(value.toInt());
            break;
        case CityColumn:
            data->setCity(value.toString());
            break;
        }

        // MyData内部会发dataChanged信号，这里就不用发了
        // emit dataChanged(index, index, {role});
        return true;
    }
    return false;
}

Qt::ItemFlags MyTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable; // FIXME: Implement me!
}

bool MyTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);

    auto *data = new MyData();
    m_datas.insert(row, data);

    // 更新MyData中的行号
    for (int i = row; i < row + count; i++) {
        m_datas.at(i)->setRow(i);
    }

    endInsertRows();
    return true;
}

bool MyTableModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    beginInsertColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endInsertColumns();
    return true;
}

bool MyTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);

    for (int i = row; i < row + count; i++) {
        auto *data = m_datas.at(i);
        m_datas.removeAt(i);
        delete data;
    }

    // 更新MyData中的行号
    for (int i = row; i < m_datas.size(); i++) {
        m_datas.at(i)->setRow(i);
    }

    endRemoveRows();
    return true;
}

bool MyTableModel::removeColumns(int column, int count, const QModelIndex &parent)
{
    beginRemoveColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endRemoveColumns();
    return true;
}

void MyTableModel::onMyDataChanged(int row, int column)
{
    QModelIndex topLeft = index(row, column);
    QModelIndex bottomRight = index(row, column);
    emit dataChanged(topLeft, bottomRight);
}
