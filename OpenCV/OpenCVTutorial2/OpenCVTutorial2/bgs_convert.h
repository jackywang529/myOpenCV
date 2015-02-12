//
//  bgs_convert.h
//  OpenCVTutorial2
//
//  Created by Chung Yu Wang on 2/10/15.
//  Copyright (c) 2015 Jacky Wang. All rights reserved.
//

#ifndef __OpenCVTutorial2__bgs_convert__
#define __OpenCVTutorial2__bgs_convert__

#include <stdio.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "FrameDifferenceBGS.h"
#include "WeightedMovingMeanBGS.h"
#include "WeightedMovingVarianceBGS.h"
#include "AdaptiveBackgroundLearning.h"
#include "AdaptiveSelectiveBackgroundLearning.h"

using namespace cv;

class bgs_convert {
private:
    string bgs_class;
    IBGS *bgs;
public:
    bgs_convert(std::string bgs_class);
    ~bgs_convert();
    
    VideoCapture convert_video(VideoCapture capture, std::string store_path);
    Mat convert_image(Mat frame, Mat img_bkgmodel, std::string store_path);
};

#endif /* defined(__OpenCVTutorial2__bgs_convert__) */
