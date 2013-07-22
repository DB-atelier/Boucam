#include "facedetection.h"

FaceDetection::FaceDetection()
{
    detectionEnabled= false;
}

FaceDetection::~FaceDetection()
{
    parser.save();
}

int  FaceDetection::init()
{



    rng=12345;
    face_cascade_name = "lbpcascade_frontalface.xml";

    //-- 1. Load the cascades
      if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };

    scaleFactor=1.1;
    minNeighbors=3;
    flags=0;
    minSize=120;
    maxSize=120;

    detectionEnabled = true;

    parser.parse("facedetect.ini");
    parser.setInts("minSize",&minSize);
    parser.parseInts("maxSize",&maxSize);
    parser.setInts("minNeighbors",&minNeighbors);

    std::cout << maxSize << std::endl;
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

void FaceDetection::detect( cv::Mat frame )
{
    cvtColor( frame, frame_gray, CV_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    lastFrame = frame;
    //-- Detect faces
    face_cascade.detectMultiScale( frame_gray, faces, scaleFactor, minNeighbors, flags, cv::Size(minSize, maxSize) );
}

void FaceDetection::drawEllipse()
{
    for(unsigned int i = 0; i < faces.size(); i++ )
    {
        cv::Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
        ellipse( lastFrame, center, cv::Size( faces[i].width/2, faces[i].height/2), 0, 0, 360, cv::Scalar( 255, 0, 0 ), 2, 8, 0 );
    }
}

QPixmap FaceDetection::toQPixmap()
{
    cv::Mat rgb;
    cv::cvtColor(lastFrame, rgb, (-2*lastFrame.channels()+10)); //???
    qtFrame.convertFromImage(QImage(rgb.data, rgb.cols, rgb.rows, QImage::Format_RGB888));
    return qtFrame;
}
