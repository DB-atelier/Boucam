#include "facedetection.h"

FaceDetection::FaceDetection()
{
    detectionEnabled= false;
}

FaceDetection::~FaceDetection()
{
}

int  FaceDetection::init()
{
    rng=12345;
    face_cascade_name = "haarcascade_frontalface_alt.xml";

    //-- 1. Load the cascades
      if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };

    detectionEnabled = true;
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

QPixmap* FaceDetection::detectAndDisplay( cv::Mat frame )
{

    std::vector<cv::Rect> faces;
    cv::Mat frame_gray;

    cvtColor( frame, frame_gray, CV_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    //-- Detect faces
    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, cv::Size(30, 30) );

    for( int i = 0; i < faces.size(); i++ )
    {
      cv::Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
      ellipse( frame, center, cv::Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, cv::Scalar( 255, 0, 255 ), 4, 8, 0 );

      cv::Mat faceROI = frame_gray( faces[i] );

    }
    //-- Show what you got

    cv::Mat rgb;
    cv::cvtColor(frame, rgb, (-2*frame.channels()+10)); //???
    qtFrame.convertFromImage(QImage(rgb.data, rgb.cols, rgb.rows, QImage::Format_RGB888));
    return &qtFrame;

}
