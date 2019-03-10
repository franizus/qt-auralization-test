#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QProgressDialog>
#include "mythread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QProgressDialog *progress;
    MyThread *myThread;

public slots:
    void onThreadFinished(int);
    void dialogCanceled();

private slots:
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
