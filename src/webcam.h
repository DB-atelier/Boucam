#ifndef WEBCAM_H
#define WEBCAM_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <QPixmap>

#include "facedetection.h"

class Webcam
{
public:
    Webcam();
    virtual ~Webcam();

    bool open(int icam = 0);
    void close();
    cv::Mat* capture();
    cv::Mat* getLast(){return &frame;}
#ifdef QPIXMAP_H
    QPixmap* capturePixmap();
    QPixmap  qtFrame;
#endif

    int camId;
    cv::VideoCapture videocapture;
    cv::Mat frame;
    FaceDetection faceD;


};

#endif // WEBCAM_H
