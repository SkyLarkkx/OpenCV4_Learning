#include <iostream>
using namespace std;
#include <opencv2/opencv.hpp>
using namespace cv;
#include <vector>

/*3.2.1: 图像像素统计*/


int main()
{
	float a[12] = { 1,2,3,4,5,10,6,7,8,9,10,0 };
	double minval, maxval;//用于存放矩阵中的最大值和最小值
	Point minIdx, maxIdx;//用于存放矩阵中的最大值和最小值在矩阵中的位置

	/*寻找单通道矩阵中的最值*/
	Mat img = Mat(3, 4, CV_32FC1, a);
	minMaxLoc(img, &minval, &maxval, &minIdx, &maxIdx);
	cout << "img中的最大值是：" << maxval << " " << "在矩阵中的位置:" << maxIdx << endl;
	cout << "img中的最小值是：" << minval << " " << "在矩阵中的位置:" << minIdx << endl;

	/*寻找多通道矩阵中的最值*/
	Mat imgs = Mat(2, 3, CV_32FC2, a);
	Mat img_re = imgs.reshape(1, 4);//将多通道矩阵变成单通道矩阵
	minMaxLoc(img_re, &minval, &maxval, &minIdx, &maxIdx);
	cout << "img_中的最大值是：" << maxval << " " << "在矩阵中的位置:" << maxIdx << endl;
	cout << "img_re中的最小值是：" << minval << " " << "在矩阵中的位置:" << minIdx << endl;

	return 0;
}