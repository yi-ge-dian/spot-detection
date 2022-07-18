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

/**
 * @description 图片背景相减 src1-src2
 * @param src1
 * @param src2
 * @param dst
 * @return
 */
bool bg_sub(Mat &src1, Mat &src2, Mat &dst) {
    cout << src1.size << endl;
    cout << src2.size << endl;
    if (src1.size != src2.size) {
        return false;
    }
    addWeighted(src1, 1, src2, -1, 0, dst);
    return true;
}

#endif //SPOT_DETECTION_BACKGROUND_SUBTRACTION_H
