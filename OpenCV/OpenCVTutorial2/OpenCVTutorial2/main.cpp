#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
//#include "package_bgs/FrameDifferenceBGS.h"
#include "FrameDifferenceBGS.h"

using namespace cv;

int main (int argc, char *argv[]) {
    
    
    //VideoCapture cap("people.mp4"); // open the default camera
    //CvCapture *capture = cvCaptureFromCAM(0);
    CvCapture *capture = cvCaptureFromFile("people2.mp4");
    
    IBGS *bgs;
    bgs = new FrameDifferenceBGS;
    IplImage *frame;
    while (1)
    {
        frame = cvQueryFrame(capture);
        if(!frame) break;
        
        Mat img_input(frame);
        imshow("Input", img_input);
        
        Mat img_mask;
        Mat img_bkgmodel;
        
        bgs->process(img_input, img_mask, img_bkgmodel);
        
        if (cvWaitKey(33) >= 0)
            break;
    }
    
    delete bgs;
    
    cvDestroyAllWindows();
    cvReleaseCapture(&capture);
    
    return 0;
    
    /*
    VideoCapture cap(0);
    if(!cap.isOpened()) { // check if we succeeded
        printf("input video not opened\n");
        return -1;
    }
    
    double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    int fps = cap.get(CV_CAP_PROP_FPS);
    Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));
    //VideoWriter output_cap("out.avi", CV_FOURCC('I', 'Y', 'U', 'V'), fps, frameSize, false);
    VideoWriter output_cap("out.mov", CV_FOURCC('8', 'B', 'P', 'S'), fps, frameSize, true);
    if(!output_cap.isOpened()) { // check if we succeeded
        printf("output video not opened\n");
        return -1;
    }
    
    Mat edges;
    namedWindow("edges",1);
    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        //cvtColor(frame, edges, CV_BGR2GRAY);
        cvtColor(frame, edges, CV_BGR2BGRA);
        GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        Canny(edges, edges, 0, 30, 3);
        imshow("edges", edges);
        //output_cap.write(frame);
     
     */
    
    
        /*
         // Attempt to fix Mac OS gray scale not able to be written
         Mat imageGrey;
         Mat imageArr[] {edges, edges, edges};
         merge(imageArr, 3, imageGrey);
         output_cap.write(imageGrey);
         */
    
    /*
        
        if(waitKey(30) >= 0) break;
        //waitKey(0);
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
    */
    
    /* Webcam
     VideoCapture cap(0);
     
     while (true) {
     
     Mat Webcam;
     cap.read(Webcam);
     imshow("webcam", Webcam);
     
     }
     */
    
    /* Image Input
     if ( argc != 2 )
     {
     printf("usage: DisplayImage.out <Image_Path>\n");
     return -1;
     }
     
     Mat image;
     image = imread( argv[1], 1 );
     
     if ( !image.data )
     {
     printf("No image data \n");
     return -1;
     }
     
     namedWindow("Display Image", CV_WINDOW_AUTOSIZE );
     imshow("Display Image", image);
     
     waitKey(0);
     
     return 0;
     */
    
}