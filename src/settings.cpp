#include "settings.h"

Settings::Settings(QWidget *parent) :
    QWidget(parent)
{
    trustMinSli = new QSlider;
    faceMinSli = new QSlider;
    faceMaxSli = new QSlider;
    interieMvtSli = new QSlider;
    interieSclSli = new QSlider;
    offDelaySli = new QSlider;
    doCannySli = new QSlider;
    onDelaySli = new QSlider;

    trustMinLab = new QLabel;
    faceMinLab = new QLabel;
    faceMaxLab = new QLabel;
    interieMvtLab = new QLabel;
    interieSclLab = new QLabel;
    offDelayLab = new QLabel;
    doCannyLab = new QLabel;
    onDelayLab = new QLabel;

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
