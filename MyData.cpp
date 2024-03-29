#include "MyData.h"

MyData::MyData(QObject *parent) :
    QObject(parent)
{
}

MyData::MyData(const QString &name, int age, const QString &city, QObject *parent) :
    QObject(parent),
    m_name(name),
    m_age(age),
    m_city(city)
{
}

int MyData::row() const
{
    return m_row;
}

void MyData::setRow(int newRow)
{
    m_row = newRow;
}

QString MyData::name() const
{
    return m_name;
}

void MyData::setName(const QString &newName)
{
    m_name = newName;

    emit dataChanged(m_row, NameColumn);
}

int MyData::age() const
{
    return m_age;
}

void MyData::setAge(int newAge)
{
    m_age = newAge;

    emit dataChanged(m_row, AgeColumn);
}

QString MyData::city() const
{
    return m_city;
}

void MyData::setCity(const QString &newCity)
{
    m_city = newCity;

    emit dataChanged(m_row, CityColumn);
}
