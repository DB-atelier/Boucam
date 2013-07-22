#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QSlider>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>


class Settings : public QWidget
{
        Q_OBJECT
    public:
        explicit Settings(QWidget *parent = 0);
        void update();


    public slots:
        void validate();

    public:
        QSlider* trustMinSli;
        QSlider* faceMinSli;
        QSlider* faceMaxSli;
        QSlider* interieMvtSli;
        QSlider* interieSclSli;
        QSlider* offDelaySli;
        QSlider* doCannySli;
        QSlider* onDelaySli;

        QLabel* trustMinLab;
        QLabel* faceMinLab;
        QLabel* faceMaxLab;
        QLabel* interieMvtLab;
        QLabel* interieSclLab;
        QLabel* offDelayLab;
        QLabel* doCannyLab;
        QLabel* onDelayLab;

        QLabel* welcomeLab;
        QGridLayout* mainLay;
        QPushButton* okBut;



};

#endif // SETTINGS_H
