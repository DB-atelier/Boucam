#include "settings.h"

Settings::Settings(QWidget *parent) :
    QWidget(parent)
{
    welcomeLab = new QLabel("Paramètre de l'application :");
    okBut = new QPushButton("OK");

    trustMinSli = new QSlider(Qt::Horizontal);
    faceMinSli = new QSlider(Qt::Horizontal);
    faceMaxSli = new QSlider(Qt::Horizontal);
    interieMvtSli = new QSlider(Qt::Horizontal);
    interieSclSli = new QSlider(Qt::Horizontal);
    offDelaySli = new QSlider(Qt::Horizontal);
    doCannySli = new QSlider(Qt::Horizontal);
    onDelaySli = new QSlider(Qt::Horizontal);

//    trustMinSli->setValue(22);
//    faceMinSli->setValue();
//    faceMaxSli->setValue();
//    interieMvtSli->setValue();
//    interieSclSli->setValue();
//    offDelaySli->setValue();
//    doCannySli->setValue();
//    onDelaySli->setValue();

    trustMinLab = new QLabel("Trust min : " + QString::number(trustMinSli->value()));
    faceMinLab = new QLabel("Face Size Min : " + QString::number(faceMinSli->value()));
    faceMaxLab = new QLabel("Face Size Max : "+ QString::number(faceMaxSli->value()));
    interieMvtLab = new QLabel("Inertie Mvt : "+ QString::number(interieMvtSli->value()));
    interieSclLab = new QLabel("Inertie Scl : "+ QString::number(interieSclSli->value()));
    offDelayLab = new QLabel("Off Delay : "+ QString::number(offDelaySli->value()));
    doCannyLab = new QLabel("doCanny : "+ QString::number(doCannySli->value()));
    onDelayLab = new QLabel("On Delay : "+ QString::number(onDelaySli->value()));

    mainLay = new QGridLayout(this);

    mainLay->addWidget(welcomeLab,0,0);
    mainLay->addWidget(trustMinLab,1,0);
    mainLay->addWidget(faceMinLab,2,0);
    mainLay->addWidget(faceMaxLab,3,0);
    mainLay->addWidget(interieMvtLab,4,0);
    mainLay->addWidget(interieSclLab,5,0);
    mainLay->addWidget(offDelayLab,6,0);
    mainLay->addWidget(doCannyLab,7,0);
    mainLay->addWidget(onDelayLab,8,0);

    mainLay->addWidget(trustMinSli,1,1);
    mainLay->addWidget(faceMinSli,2,1);
    mainLay->addWidget(faceMaxSli,3,1);
    mainLay->addWidget(interieMvtSli,4,1);
    mainLay->addWidget(interieSclSli,5,1);
    mainLay->addWidget(offDelaySli,6,1);
    mainLay->addWidget(doCannySli,7,1);
    mainLay->addWidget(onDelaySli,8,1);
    mainLay->addWidget(okBut,9,1);

    setLayout(mainLay);
    QObject::connect(okBut, SIGNAL(clicked()),this,SLOT(validate()));

}

void Settings::update()
{
    trustMinLab->setText(QString("Trust min : ") + QString::number(trustMinSli->value()));
    faceMinLab->setText(QString("Face Size Min : ") + QString::number(faceMinSli->value()));
    faceMaxLab->setText(QString("Face Size Max : ") + QString::number(faceMaxSli->value()));
    interieMvtLab->setText(QString("Inertie Mvt : ")+ QString::number(interieMvtSli->value()) );
    interieSclLab->setText(QString("Inertie Scl : ")+ QString::number(interieSclSli->value()) );
    offDelayLab->setText(QString("Off Delay : ")+ QString::number(offDelaySli->value()) );
    doCannyLab->setText(QString("doCanny : ")+ QString::number(doCannySli->value()) );
    onDelayLab->setText(QString("On Delay : ")+ QString::number(onDelaySli->value()) );

}

void Settings::validate()
{
    close();
}
