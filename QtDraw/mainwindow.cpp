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
    connect(ui->upButton,&QPushButton::clicked,this,&MainWindow::DrawUp);
    connect(ui->leftButton,&QPushButton::clicked,this,&MainWindow::DrawLeft);

    connect(ui->editWidth,SIGNAL(triggered()),this,SLOT(EditWidth()));
    connect(ui->editColor,SIGNAL(triggered()),this,SLOT(EditColour()));

    QMenu *fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction("Exit",this,&MainWindow::close);
}


void MainWindow::DrawRight()
{
    QPainter painter(&pixmap);
    painter.setPen(QPen(colour, width));
    painter.drawLine(x, y, x+20, y);
    ui->label->setPixmap(pixmap);
    x += 20;
    //QPushButton *a = new QPushButton;
}

void MainWindow::DrawDown()
{
    QPainter painter(&pixmap);
    painter.setPen(QPen(colour, width));
    painter.drawLine(x ,y ,x ,y+20);
    ui->label->setPixmap(pixmap);
    y += 20;
    //QPushButton *a = new QPushButton;
}

void MainWindow::DrawUp()
{
    QPainter painter(&pixmap);
    painter.setPen(QPen(colour, width));
    painter.drawLine(x, y, x, y-20);
    ui->label->setPixmap(pixmap);
    y -= 20;
    //QPushButton *a = new QPushButton;
}

void MainWindow::DrawLeft()
{
    QPainter painter(&pixmap);
    painter.setPen(QPen(colour, width));
    painter.drawLine(x, y, x-20, y);
    ui->label->setPixmap(pixmap);
    x -= 20;
    //QPushButton *a = new QPushButton;
}

void MainWindow::EditWidth()
{
    width = QInputDialog::getInt(this, "Pen Width", "Enter a width:", 10, 1);
}

void MainWindow::EditColour()
{
    colour = QColorDialog::getColor(Qt::green, this, "Pen color");
}

MainWindow::~MainWindow()
{
//    https://stackoverflow.com/questions/16362191/qt-grab-widget-and-save-image
    ui->label->grab().save("image.png");
    delete ui;
}

