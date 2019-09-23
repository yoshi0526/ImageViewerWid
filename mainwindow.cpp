#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
//    , prefix("file:../openimage/validation")
    , prefix("../openimage/validation")
    , gridSize(300)
{
    ui->setupUi(this);
    resize(640,480);

    // File load
    fsmodel = new FileSystemModel;
    fsmodel->setRootPath(prefix);

    ui->listView->setModel(fsmodel);
    ui->listView->setRootIndex(fsmodel->index(prefix));
    ui->listView->setViewMode(QListView::IconMode);
    ui->listView->setIconSize(QSize(gridSize,gridSize));
    ui->listView->setDragEnabled(false);
    ui->listView->setSpacing(50);
    ui->listView->setResizeMode(QListView::Adjust);

    ui->tableView->setModel(fsmodel);
    ui->tableView->setRootIndex(fsmodel->index(prefix));
    ui->treeView->setModel(fsmodel);
    ui->treeView->setRootIndex(fsmodel->index(prefix));

    qDebug() << "fsmodel->rowCount " << fsmodel->rowCount() << "";
    qDebug() << "fsmodel->columnCount " << fsmodel->columnCount() << "";

    // timer 10000
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_gridMinius_clicked()
{
    if(gridSize>30)
        gridSize /= 1.414;
    ui->listView->setIconSize(QSize(gridSize,gridSize));
}

void MainWindow::on_gridPlus_clicked()
{
    gridSize *= 1.414;
    ui->listView->setIconSize(QSize(gridSize,gridSize));
}
