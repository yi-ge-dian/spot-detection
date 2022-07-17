//
// Created by 董文龙 on 2022/7/17.
//
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

int main() {
    cv::Mat image = cv::imread("../test.jpg");
    if (image.empty()){
        printf("Image not loaded");
        return -1;
    }
    imshow("image", image);
    cv::waitKey(0);
    return 0;
}