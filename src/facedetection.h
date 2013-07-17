#ifndef FACEDETECTION_H
#define FACEDETECTION_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


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

    //...

};

#endif // FACEDETECTION_H
