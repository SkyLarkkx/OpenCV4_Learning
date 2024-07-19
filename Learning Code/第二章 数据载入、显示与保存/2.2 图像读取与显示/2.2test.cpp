#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include <opencv2/opencv.hpp>
using namespace cv;


/*2.2:图像的读取与显示*/

int main()
{
	


	Mat img;
	img = imread("C:/Users/Wentao Qiu/Desktop/QQ图片20240529214945.jpg",-1);
	namedWindow("test", WINDOW_GUI_EXPANDED);
	
	imshow("test",img);
	waitKey(0);
	


}