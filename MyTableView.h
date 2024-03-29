#ifndef MYTABLEVIEW_H
#define MYTABLEVIEW_H

#include <QTableView>

class MyTableView : public QTableView
{
public:
    explicit MyTableView(QWidget *parent = nullptr);
    ~MyTableView();
};

#endif // MYTABLEVIEW_H
