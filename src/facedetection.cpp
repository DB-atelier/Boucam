#include "facedetection.h"

FaceDetection::FaceDetection()
{
}

FaceDetection::~FaceDetection()
{
}

int  FaceDetection::init()
{
    return 0;
}

void FaceDetection::clean()
{
}

void FaceDetection::setROI(float x0,float y0,float x1,float y1)
{
}

int  FaceDetection::update(cv::Mat* pImg)
{
    return 0;
}

int  FaceDetection::render(cv::Mat* pImg)
{
    return 0;
}

int  FaceDetection::sendTo(ChaussetteUdp *pSock)
{
    return 0;
}
