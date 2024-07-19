#include <iostream>
using namespace std;
#include <opencv2/opencv.hpp>
using namespace cv;
#include <vector>

/*3.2.1: 图像像素统计*/


int main()
{
	float a[12] = { 1,2,3,4,5,10,6,7,8,9,10,0 };
	Mat img = Mat(3, 4, CV_32FC1, a);//单通道矩阵
	Mat imgs = Mat(2, 3, CV_32FC2, a);//多通道矩阵

	cout << "/* 用mean求取图像的平均值 */" << endl;
	Scalar myMean;
	myMean = mean(imgs);
	cout << "第一个通道的平均值=" << myMean[0] << endl
		<< "第二个通道的平均值=" << myMean[1] << endl << endl;

	
	cout << "/* 用meanStdDev 同时求取图像的平均值和标准差 */" << endl;
	Mat myMeanMat, myStddevMat;
	
	meanStdDev(img, myMeanMat, myStddevMat);
	cout << "img平均值=" << myMeanMat << endl;
	cout << "img标准差=" << myStddevMat << endl << endl;

	meanStdDev(imgs, myMeanMat, myStddevMat);
	cout << "img平均值=" << myMeanMat << endl;
	cout << "img标准差=" << myStddevMat << endl;

	return 0;
}