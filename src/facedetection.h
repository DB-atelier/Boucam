#ifndef FACEDETECTION_H
#define FACEDETECTION_H

//#include <opencv2/core/core.hpp>

#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <opencv2/highgui/highgui_c.h>

#include <iostream>
#include <stdio.h>
#include <QPixmap>

#include "iniparser.h"

class ChaussetteUdp; //TODO


class FaceDetection
{
public:
    FaceDetection();
    virtual ~FaceDetection();

    //returns error code
    int  init(); //
    void clean();
    //Region of interrest normalisée
    void setROI(float x0,float y0,float x1,float y1);
    int  update(cv::Mat* pImg);
    //draw infos on picture
    int  render(cv::Mat* pImg);
    int  sendTo(ChaussetteUdp* pSock);

    //K having fun
    void detect(cv::Mat frame );
    void drawEllipse();
    QPixmap toQPixmap();
    //...


public:
    std::string face_cascade_name;
    cv::CascadeClassifier face_cascade;
    cv::RNG rng;

    std::vector<cv::Rect> faces;
    cv::Mat frame_gray;
    cv::Mat lastFrame;
    QPixmap  qtFrame;

    double scaleFactor;
    int minNeighbors;
    int flags;
    int minSize;
    int maxSize;

    bool detectionEnabled;

    IniParser parser;
};

#endif // FACEDETECTION_H
