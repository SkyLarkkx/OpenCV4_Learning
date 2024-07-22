#include <iostream>
using namespace std;
#include <opencv2/opencv.hpp>
using namespace cv;
#include <vector>

/*3.2.2:两图像间的像素操作*/

/*1.两幅图像的比较运算*/

int main()
{
	float a[12] = { 1,2,3.3,4,5,9,5,5,8.2,9,10,2 };
	float b[12] = { 1,2.2,3,1,3,10,6,7,8,9.3,10,1 };
	Mat imga = Mat(3, 4, CV_32FC1, a);
	Mat imgb = Mat(3, 4, CV_32FC1, b);
	Mat imgas = Mat(2, 3, CV_32FC2, a);
	Mat imgbs = Mat(2, 3, CV_32FC2, b);

	
	
	//对两个单通道矩阵进行比较运算
	Mat myMax, myMin;
	max(imga, imgb, myMax);
	min(imga, imgb, myMin);
	
	imshow("Max", myMax);
	imshow("Min",myMin);
	waitKey();
	destroyAllWindows();

	//对两个多通道矩阵进行比较运算
	Mat myMaxs, myMins;
	max(imgas, imgbs, myMaxs);
	min(imgas, imgbs, myMins);

	imshow("Maxs", myMaxs);
	imshow("Mins", myMins);
	waitKey();
	destroyAllWindows();

	//对两幅彩色图像进行比较运算
	Mat img0 = imread("lena.jpg");
	Mat img1 = imread("noobcv.jpg");
	if (img0.empty() || img1.empty())
	{
		cerr << "请确认图像文件名称是否正确" << endl;
		return -1;
	}
	Mat comMin, comMax;
	max(img0, img1, comMax);
	min(img0, img1, comMin);
	imshow("comMin", comMin);
	imshow("comMax", comMax);

	

	//与掩模进行比较运算
	Mat src1 = Mat::zeros(Size(512, 512), CV_8UC1);
	Rect rect(100, 100, 300, 300);
	src1(rect) = Scalar(255, 255, 255);//生成一个低通300×300的掩模
	Mat comsrc1, comsrc2;
	min(img0,src1,comsrc1);
	imshow("comsrc1", comsrc1);

	Mat src2 = Mat(512, 512, CV_8UC3, Scalar(0, 0, 255));//生成一个显示红色通道的低通掩模
	min(img0, src2, comsrc2);
	imshow("comsrc2", comsrc2);

	//对两幅灰色图像进行比较运算
	Mat img0G, img1G, comMinG, comMaxG;
	cvtColor(img0, img0G, COLOR_BGR2GRAY);
	cvtColor(img1, img1G, COLOR_BGR2GRAY);
	min(img0G, img1G, comMinG);
	max(img0G, img1G, comMaxG);
	imshow("comMinG", comMinG);
	imshow("comMaxG", comMaxG);
	waitKey();
	return 0;
}
