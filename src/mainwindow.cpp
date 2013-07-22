#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pLabelCV = new QLabel(this);
    pLabelCV->setUpdatesEnabled(true);

    init();
}

/////
MainWindow::~MainWindow()
{
    timer.stop();
    webcam.close();
    delete ui;
}

void MainWindow::init()
{
    webcam.open(0); //... ->numero de cam en settings
    timer.start(40,this);
}

//"mainloop"
void MainWindow::timerEvent(QTimerEvent* event)
{
    setWid.update();
    QPixmap* ppix = webcam.capturePixmap();
    if( ppix )
    {
        pLabelCV->setPixmap(*ppix);
        pLabelCV->adjustSize();
        resize(ppix->width(),ppix->height());
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_F5:
            setWid.show();
            break;
    }
}
