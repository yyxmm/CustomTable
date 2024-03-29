#ifndef MYDATA_H
#define MYDATA_H

#include <QObject>
#include <QString>

enum MyDataColumn {
    NameColumn = 0,
    AgeColumn,
    CityColumn,
    ColumnCount
};

class MyData : public QObject
{
    Q_OBJECT

public:
    explicit MyData(QObject *parent = nullptr);
    explicit MyData(const QString &name, int age, const QString &city, QObject *parent = nullptr);

    int row() const;
    void setRow(int newRow);

    QString name() const;
    void setName(const QString &newName);

    int age() const;
    void setAge(int newAge);

    QString city() const;
    void setCity(const QString &newCity);

signals:
    void dataChanged(int row, int column);

private:
    int m_row;

    QString m_name;
    int m_age = 0;
    QString m_city;
};

#endif // MYDATA_H
