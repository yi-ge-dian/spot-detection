//
// Created by 董文龙 on 2022/7/17.
//
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "src/gray_level_transformation.h"
#include "src/background_subtraction.h"
#include "src/utils.h"

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
    /**-------加载图片--------*/
    string path1 = "../resources/img/test.jpg";
    string path2 = "../resources/img/test1.jpg";
    Mat source_img1;
    bool result = load_image(path1, source_img1);
    if (!result) {
        cout << "load image failed" << endl;
        return -1;
    }
    Mat source_img2;
    bool result2 = load_image(path2, source_img2);
    if (!result2) {
        cout << "load image failed" << endl;
        return -1;
    }

    /**-------背景相减--------*/
    Mat bg_sub_img;
    bool bg_sub_result = bg_sub(source_img2, source_img1, bg_sub_img);
    if (!bg_sub_result) {
        cout << "bg_sub failed" << endl;
        return -1;
    }
    imshow("image", bg_sub_img);


    // call gray_trans function
//    float pixels[256];
//    for (int i = 0; i < 256; i++)
//        pixels[i] = powf(i, 1.5);   //
//    Mat imageLog;
//    gray_trans(image, imageLog, pixels);

    //show image
    //imshow("image", image);
    waitKey(0);
    return 0;
}