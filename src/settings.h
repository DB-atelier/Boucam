#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QSlider>
#include <QGridLayout>
#include <QLabel>

class Settings : public QWidget
{
        Q_OBJECT
    public:
        explicit Settings(QWidget *parent = 0);
        void update();

    signals:

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

        QGridLayout* mainLay;
};

#endif // SETTINGS_H
