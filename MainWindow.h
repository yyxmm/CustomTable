#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "MyTableModel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonInsertBefore_clicked();

    void on_pushButtonInsertAfter_clicked();

    void on_pushButtonInsertLast_clicked();

    void on_pushButtonDelete_clicked();

private:
    Ui::MainWindow *ui;

    MyTableModel *m_model;
};
#endif // MAINWINDOW_H
