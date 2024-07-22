#include <iostream>
using namespace std;
#include <opencv2/opencv.hpp>
using namespace cv;
#include <vector>

/*3.2.2:两图像间的像素操作*/

/*1.2.两幅图像间的逻辑运算*/

int main()
{
	Mat img = imread("lena.png");
	if (img.empty())
	{
		cerr << "please check filename" << endl;
		return -1;
	}

	//创建两个黑白图像
	Mat img0 = Mat::zeros(200, 200, CV_8UC1);
	Mat img1 = Mat::zeros(200, 200, CV_8UC1);
	Rect rect0(50, 50, 100, 100);
	img0(rect0) = Scalar(255);
	Rect rect1(100, 100, 100, 100);
	img1(rect1) = Scalar(255);
	imshow("img0", img0);
	imshow("img1", img1);
	
	//进行逻辑运算
	Mat myAnd, myOr, myXor, myNot,imgNot;
	
	bitwise_not(img0, myNot);
	bitwise_and(img0, img1,myAnd);
	bitwise_or(img0, img1, myOr);
	bitwise_xor(img0, img1, myXor);
	bitwise_not(img, imgNot);


	imshow("myNot", myNot);
	imshow("myAnd", myAnd);
	imshow("myOr", myOr);
	imshow("myXor", myXor);
	imshow("imgNot", imgNot);

	waitKey();
	return 0;
}
