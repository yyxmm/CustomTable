#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_model = new MyTableModel(this);
    ui->tableView->setModel(m_model);

    m_model->addMyData(new MyData("John", 25, "New York"));
    m_model->addMyData(new MyData("Jane", 22, "Los Angeles"));
    m_model->addMyData(new MyData("Alice", 30, "Chicago"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonInsertBefore_clicked()
{
    int currentRow = ui->tableView->currentIndex().row();
    if (currentRow == -1) {
        QMessageBox::warning(this, "Warning", "Please select a row to insert before");
        return;
    }
    m_model->insertRow(currentRow);
}

void MainWindow::on_pushButtonInsertAfter_clicked()
{
    int currentRow = ui->tableView->currentIndex().row();
    if (currentRow == -1) {
        QMessageBox::warning(this, "Warning", "Please select a row to insert after");
        return;
    }
    m_model->insertRow(currentRow + 1);
}

void MainWindow::on_pushButtonInsertLast_clicked()
{
    m_model->insertRow(m_model->rowCount());
}

void MainWindow::on_pushButtonDelete_clicked()
{
    int currentRow = ui->tableView->currentIndex().row();
    if (currentRow == -1) {
        QMessageBox::warning(this, "Warning", "Please select a row to delete");
        return;
    }
    m_model->removeRow(currentRow);
}

