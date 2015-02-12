#include <iostream>
#include <iomanip>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "FrameDifferenceBGS.h"
#include "WeightedMovingMeanBGS.h"
#include "WeightedMovingVarianceBGS.h"
#include "AdaptiveBackgroundLearning.h"
#include "AdaptiveSelectiveBackgroundLearning.h"
#include "bgs_convert.h"
#include "ObjectExtractor.h"

using namespace cv;

// Helper function prototypes
string getPathFromDataset(string dataType, int imgNum);
string getDigitString(int numDigits, int num);

int main (int argc, char *argv[]) {
    string videoName = "WeightedMovingMean.avi";
    VideoCapture cap(videoName); // open the default camera
    if (!cap.isOpened()) {
        std::cout << "video not opened\n";
    }
    
    Mat frame;
    ObjectExtractor extractor;
    while(1) {
        cap >> frame;
        cvtColor(frame,frame,CV_RGB2GRAY);
        
        if (!frame.data) {
            break;
        }
        
        vector<Rect> boxes = extractor.extractBoxes(frame);
        for (Rect box : boxes){
            std::cout << box << endl;
            rectangle(frame, box, Scalar(255, 255, 255));
        }
        imshow("Object Detection", frame);
        
        if (cvWaitKey(1) >= 0)
            break;
    }
    return 0;
}

void TestBGSVideoConvert() {
    VideoCapture capture("train.avi"); // open the default camera
    bgs_convert *convert = new bgs_convert("AdaptiveSelectiveBackgroundLearning");
    
    // Test video convert
    VideoCapture result = convert->convert_video(capture, "AdaptiveSelectiveBackgroundLearning.avi");
    Mat vidTest;
    while(1) {
        result >> vidTest;
        if (!vidTest.data) {
            //std::cout << "no result data\n";
            break;
        }
        
        imshow("Video Test", vidTest);
        
        if (cvWaitKey(1) >= 0)
            break;
    }
}

void TestSingleImageObjectExtractiong() {
    Mat frame = imread("testframe_3.jpg", CV_LOAD_IMAGE_GRAYSCALE);
    ObjectExtractor extractor;
    vector<Rect> boxes = extractor.extractBoxes(frame);
    for (Rect box : boxes){
        std::cout << box << endl;
        rectangle(frame, box, Scalar(255, 255, 255));
    }
    imshow("Title", frame);
    cvWaitKey(0);
}

string getPathFromDataset(string dataType, int imgNum) {
    int numDigits = 6; // in image file specification prepends 0 till 6 digits
    string num = getDigitString(numDigits, imgNum);
    string path = "/Users/jackywang/Desktop/231a/project/pedestrianData/pedestrianDetectionDataset/" + dataType + "/input/in"              + num + ".jpg";
    return path;
}

string getDigitString(int numDigits, int num) {
    std::stringstream ss;
    ss << std::setw(numDigits) << std::setfill('0') << num;
    return ss.str();
}

void sampleCode() {
    /*
     
     VideoCapture cap("out2.avi");
     if(!cap.isOpened()) { // check if we succeeded
     printf("input video not opened\n");
     return -1;
     }
     
     double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
     double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
     int fps = cap.get(CV_CAP_PROP_FPS);
     printf("input fps=%f\n", cap.get(CV_CAP_PROP_FPS));
     Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));
     VideoWriter output_cap("out2.avi", CV_FOURCC('I', 'Y', 'U', 'V'), fps, frameSize, true);
     //VideoWriter output_cap("out2.mov", CV_FOURCC('8', 'B', 'P', 'S'), fps, frameSize, true);
     //VideoWriter output_cap("out.mov", static_cast<int>(cap.get(CV_CAP_PROP_FOURCC)), fps, frameSize, true);
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
     //output_cap << frame;
     
     
     // Attempt to fix Mac OS gray scale not able to be written
     Mat imageGrey;
     Mat imageArr[] {edges, edges, edges};
     merge(imageArr, 3, imageGrey);
     output_cap.write(imageGrey);
     
     
     
     
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