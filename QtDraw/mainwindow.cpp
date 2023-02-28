#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , pixmap{750,400}
    , x{40}
    , y{40}
{
    ui->setupUi(this);
    pixmap.fill(QColor("white"));
    DrawRight();

    connect(ui->rightButton,&QPushButton::clicked,this,&MainWindow::DrawRight);
    connect(ui->downButton,&QPushButton::clicked,this,&MainWindow::DrawDown);

    QMenu *fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction("Exit",this,&MainWindow::close);
}

void MainWindow::DrawRight()
{
    QPainter painter(&pixmap);
    painter.setPen(QPen(Qt::green,5));
    painter.drawLine(x, y, x+20, y);
    ui->label->setPixmap(pixmap);
    x += 20;
    QPushButton *a = new QPushButton;
}

void MainWindow::DrawDown()
{
    QPainter painter(&pixmap);
    painter.setPen(QPen(Qt::green, 5));
    painter.drawLine(x ,y ,x ,y+20);
    ui->label->setPixmap(pixmap);
    y += 20;
    QPushButton *a = new QPushButton;
}

MainWindow::~MainWindow()
{
//    https://stackoverflow.com/questions/16362191/qt-grab-widget-and-save-image
    ui->label->grab().save("image.png");
    delete ui;
}

