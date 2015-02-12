// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
/*
#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <thread>
#include "ObjectExtractor.h"
using namespace cv;
using namespace std;
int test();

int main(int, char**)
{
	Mat frame = imread("testframe_3.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	ObjectExtractor extractor;
	vector<Rect> boxes = extractor.extractBoxes(frame);
	for (Rect box : boxes){
		cout << box << endl;
		rectangle(frame, box, Scalar(255, 255, 255));
	}
	imshow("Title", frame);
	waitKey(0);
	return 0;
}
*/