#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include <opencv2/opencv.hpp>
using namespace cv;


/*2.4.1:图像的保存*/

int main()
{
	Mat img(10, 10, CV_8UC3, Scalar(0, 0, 1));
	string filename = "C:/Users/Wentao Qiu/Desktop/captured_frame.jpg";
	imwrite(filename, img);
	return 0;
}