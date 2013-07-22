#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBasicTimer>
#include <QLabel>
#include <QKeyEvent>
#include "webcam.h"
#include "settings.h"

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
    void keyPressEvent(QKeyEvent *);
    void timerEvent(QTimerEvent* event);

    Webcam webcam;
    QBasicTimer timer;
    QLabel* pLabelCV;
    Settings setWid;

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
