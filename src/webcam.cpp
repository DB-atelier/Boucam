#include "webcam.h"

Webcam::Webcam()
{
    camId = -1;
}

Webcam::~Webcam()
{
    close();
}

bool Webcam::open(int icam)
{
    close();
    videocapture.open(icam);
    camId = icam;
    return videocapture.isOpened();
}

void Webcam::close()
{
    videocapture.release();
    camId = -1;
}

cv::Mat* Webcam::capture()
{
    if(videocapture.read(frame))
        return &frame;

    return NULL;
}


#ifdef QPIXMAP_H
QPixmap* Webcam::capturePixmap()
{
    if(!videocapture.read(frame))
        return NULL;
    cv::Mat rgb;
    cv::cvtColor(frame, rgb, (-2*frame.channels()+10)); //???
    qtFrame.convertFromImage(QImage(rgb.data, rgb.cols, rgb.rows, QImage::Format_RGB888));
    return &qtFrame;
}
#endif
