#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fsmodel.h"
#include "bboxmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_gridMinius_clicked();
    void on_gridPlus_clicked();

private:
    Ui::MainWindow *ui;
    BBoxModel *bboxes;
    FileSystemModel *fsmodel;

    QString prefix;
    int gridSize;
};
#endif // MAINWINDOW_H
