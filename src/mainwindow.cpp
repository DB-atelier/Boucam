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
    faceD.init();
    webcam.open(0); //... ->numero de cam en settings
    timer.start(40,this);
}

//"mainloop"
void MainWindow::timerEvent(QTimerEvent* event)
{
    if(faceD.detectionEnabled)
    {
        cv::Mat* curFrame=webcam.capture();
        if(curFrame)
        {
            QPixmap* camPix=faceD.detectAndDisplay(*curFrame);
            pLabelCV->setPixmap(*camPix);
            pLabelCV->adjustSize();
            resize(camPix->width(),camPix->height());
        }
    }else
    {
        QPixmap* ppix = webcam.capturePixmap();
        if( ppix )
        {
            pLabelCV->setPixmap(*ppix);
            pLabelCV->adjustSize();
            resize(ppix->width(),ppix->height());
        }
    }
}

