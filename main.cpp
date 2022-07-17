//
// Created by 董文龙 on 2022/7/17.
//
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "src/gray_level_transformation.h"
#include "src/utils.h"

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
    /**-------加载图片--------*/
    string path ="../resources/img/test.jpg";
    Mat source_img;
    bool result = load_image(path, source_img);
    if (!result) {
        cout << "load image failed" << endl;
        return -1;
    }
    /**-------背景相减--------*/
    Mat background_subtraction_img;


    // call gray_trans function
    float pixels[256];
    for (int i = 0; i < 256; i++)
        pixels[i] = powf(i, 1.5);   //
    Mat imageLog;
    gray_trans(image, imageLog, pixels);

    //show image
    //imshow("image", image);
    waitKey(0);
    return 0;
}