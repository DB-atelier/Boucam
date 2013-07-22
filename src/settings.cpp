#include "settings.h"

Settings::Settings(QWidget *parent) :
    QWidget(parent)
{
    trustMinSli = new QSlider(Qt::Horizontal);
    faceMinSli = new QSlider(Qt::Horizontal);
    faceMaxSli = new QSlider(Qt::Horizontal);
    interieMvtSli = new QSlider(Qt::Horizontal);
    interieSclSli = new QSlider(Qt::Horizontal);
    offDelaySli = new QSlider(Qt::Horizontal);
    doCannySli = new QSlider(Qt::Horizontal);
    onDelaySli = new QSlider(Qt::Horizontal);

    trustMinLab = new QLabel("Trust min :");
    faceMinLab = new QLabel("Face Size Min :");
    faceMaxLab = new QLabel("Face Size Max :");
    interieMvtLab = new QLabel("Inertie Mvt :");
    interieSclLab = new QLabel("Inertie Scl :");
    offDelayLab = new QLabel("Off Delay :");
    doCannyLab = new QLabel("doCanny :");
    onDelayLab = new QLabel("On Delay :");

    mainLay = new QGridLayout(this);

    mainLay->addWidget(trustMinLab,0,0);
    mainLay->addWidget(faceMinLab,1,0);
    mainLay->addWidget(faceMaxLab,2,0);
    mainLay->addWidget(interieMvtLab,3,0);
    mainLay->addWidget(interieSclLab,4,0);
    mainLay->addWidget(offDelayLab,5,0);
    mainLay->addWidget(doCannyLab,6,0);
    mainLay->addWidget(onDelayLab,7,0);

    mainLay->addWidget(trustMinSli,0,1);
    mainLay->addWidget(faceMinSli,1,1);
    mainLay->addWidget(faceMaxSli,2,1);
    mainLay->addWidget(interieMvtSli,3,1);
    mainLay->addWidget(interieSclSli,4,1);
    mainLay->addWidget(offDelaySli,5,1);
    mainLay->addWidget(doCannySli,6,1);
    mainLay->addWidget(onDelaySli,7,1);

    setLayout(mainLay);

}

void Settings::update()
{

}
