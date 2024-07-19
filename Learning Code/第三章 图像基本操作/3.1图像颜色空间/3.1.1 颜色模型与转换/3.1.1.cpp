#include <iostream>
using namespace std;
#include <opencv2/opencv.hpp>
using namespace cv;

/*3.3.1:颜色模型与转换*/


int main()
{
	Mat img = imread("lena.png");

	if (img.empty())
	{
		cerr << "请确认图像名称是否正确" << endl;
		return -1;
	}

	Mat BGRA, RGB, gray, YUV, HSV, Lab;
	Mat img32;
	img.convertTo(img32, CV_32F, 1.0 / 255);//将 CV_8U 类型转换成 CV_32F类型

	cvtColor(img32, BGRA, COLOR_BGR2BGRA);//BGR->BGRA
	cvtColor(img32, RGB, COLOR_BGR2RGB);//BGR->RGB
	cvtColor(img32, gray, COLOR_BGR2GRAY);//BGR->GRAY
	cvtColor(img32, YUV, COLOR_BGR2YUV);//BGR->YUV
	cvtColor(img32, HSV, COLOR_BGR2HSV);//BGR->HSV
	cvtColor(img32, Lab, COLOR_BGR2Lab);//BGR->Lab

	imshow("原图", img32);
	imshow("BGRA", BGRA);
	imshow("RGB", RGB);
	imshow("GRAY", gray);
	imshow("YUV", YUV);
	imshow("HSV", HSV);
	imshow("Lab", Lab);

	waitKey();
	return 0;


}