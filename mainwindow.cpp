#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , prefix("../openimage/validation_s")
    , gridSize(200)
{
    ui->setupUi(this);
    resize(640,480);

    // File load
    fsmodel = new FileSystemModel;
    fsmodel->setGridSize(gridSize);
    fsmodel->setRootPath(prefix);

    ui->listView->setModel(fsmodel);
    ui->listView->setViewMode(QListView::IconMode); // QListView::IconMode);
    ui->listView->setIconSize(QSize(gridSize,gridSize));
    ui->listView->setDragEnabled(false);
    ui->listView->setSpacing(50);
//    ui->listView->setResizeMode(QListView::Fixed);

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
    fsmodel->setGridSize(gridSize);
}

void MainWindow::on_gridPlus_clicked()
{
    gridSize *= 1.414;
    fsmodel->setGridSize(gridSize);
    ui->listView->setIconSize(QSize(gridSize,gridSize));
}
