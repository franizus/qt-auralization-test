#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onThreadFinished(int elapsed)
{
    progress->setValue(100);
    ui->txtEdit->setPlainText(QString("Time elapsed: %1 ms").arg(elapsed));
}

void MainWindow::dialogCanceled()
{
    myThread->stop = true;
    progress->setValue(100);
}

void MainWindow::on_pushButton_clicked()
{
    /*QString fileName = QFileDialog::getOpenFileName(this, tr("Open"));
    qDebug() << fileName;
    QFile file(fileName);
    file.open(QFile::ReadOnly);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->txtEdit->setPlainText(text);
    file.close();*/

    myThread = new MyThread();
    connect(myThread, SIGNAL(finished(int)), this, SLOT(onThreadFinished(int)));

    progress = new QProgressDialog("Copying files...", "Cancel", 0, 100, this);
    progress->setWindowModality(Qt::WindowModal);
    connect(progress, SIGNAL(canceled()), this, SLOT(dialogCanceled()));

    myThread->start();
}
