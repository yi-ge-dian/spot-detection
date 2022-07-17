//
// Created by 董文龙 on 2022/7/17.
//
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "src/gray_level_transformation.h"

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
    // load image
    string path ="../resources/img/test1.jpeg";
    Mat image = imread(path);
    if (image.empty()) {
        printf("Image not loaded");
        return -1;
    }

    // call gray_trans function
    float pixels[256];
    for (int i = 0; i < 256; i++)
        pixels[i] = powf(i, 1.5);   //
    Mat imageLog;
    gray_trans(image, imageLog, pixels);

    //show image
    imshow("image", image);
    waitKey(0);
    return 0;
}