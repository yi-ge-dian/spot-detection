//
// Created by 董文龙 on 2022/7/17.
//

#ifndef SPOT_DETECTION_GRAY_LEVEL_TRANSFORMATION_H
#define SPOT_DETECTION_GRAY_LEVEL_TRANSFORMATION_H
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void gray_trans(const Mat& src, Mat& dst,float* mapping)
{
    int channels = src.channels();
    if (channels == 1)
    {
        dst = Mat(src.size(), CV_32FC1);
        for (int i = 0; i < src.rows; i++)
        {
            auto* p1 = dst.ptr<float>(i);
            const auto* p2 = src.ptr<uchar>(i);
            for (int j = 0; j < src.cols; j++)
                p1[j] = mapping[p2[j]];
        }
    }
    else if (channels == 3)
    {
        dst = Mat(src.size(), CV_32FC3);
        for (int i = 0; i < src.rows; i++)
        {
            float* p1 = dst.ptr<float>(i);
            const uchar* p2 = src.ptr<uchar>(i);
            for (int j = 0; j < src.cols * 3; j+=3)
            {
                p1[j] = mapping[p2[j]];
                p1[j+1] = mapping[p2[j+1]];
                p1[j+2] = mapping[p2[j+2]];
            }
        }
    }
}

#endif //SPOT_DETECTION_GRAY_LEVEL_TRANSFORMATION_H
