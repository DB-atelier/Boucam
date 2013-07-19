#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBasicTimer>
#include <QLabel>

#include "webcam.h"
#include "facedetection.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    void init();

    Webcam webcam;
    FaceDetection faceD;

    QBasicTimer timer;
    void timerEvent(QTimerEvent* event);
    QLabel* pLabelCV;

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
