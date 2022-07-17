//
// Created by 董文龙 on 2022/7/17.
//

#ifndef SPOT_DETECTION_BACKGROUND_SUBTRACTION_H
#define SPOT_DETECTION_BACKGROUND_SUBTRACTION_H
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
//置零函数，小于零则为0
uchar toZero(uchar a){
    if (a < 0)
        return 0;
    else
        return a;
}

//图片背景相减
Mat& bg_sub(Mat& src1, Mat& src2) {
    Mat src3;
    int rowNumber = src1.rows;
    int colNumber = src1.cols;
    for (int i = 0; i < rowNumber; i++)
    {
        for (int j = 0; j < colNumber; j++)
        {
            src3.at<Vec3b>(i, j)[0] = toZero(src2.at<Vec3b>(i, j)[0] - src1.at<Vec3b>(i, j)[0]);
            src3.at<Vec3b>(i, j)[1] = toZero(src2.at<Vec3b>(i, j)[1] - src1.at<Vec3b>(i, j)[1]);
            src3.at<Vec3b>(i, j)[2] = toZero(src2.at<Vec3b>(i, j)[2] - src1.at<Vec3b>(i, j)[2]);
        }
    }
    return src3;
}
#endif //SPOT_DETECTION_BACKGROUND_SUBTRACTION_H
