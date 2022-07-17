//
// Created by 董文龙 on 2022/7/17.
//

#ifndef SPOT_DETECTION_UTILS_H
#define SPOT_DETECTION_UTILS_H
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

//加载图片
bool load_image(const string& path, Mat& dst) {
    dst = imread(path);
    if (dst.empty()) {
       cout << "path is invalid" << endl;
        return false;
    }
    return true;
}



#endif //SPOT_DETECTION_UTILS_H
