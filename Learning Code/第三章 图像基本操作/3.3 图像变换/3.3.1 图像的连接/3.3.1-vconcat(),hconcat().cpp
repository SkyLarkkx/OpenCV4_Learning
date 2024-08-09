#include <iostream>
using namespace std;
#include <opencv2/opencv.hpp>
using namespace cv;
#include <vector>

/* 3.3.1:图像的连接 */

int main()
{
	//矩阵数组的横竖连接
	Mat matArray[] = { Mat(1,2,CV_32FC1,Scalar(1)),Mat(1,2,CV_32FC1,Scalar(2)) };
	Mat vout, hout;
	vconcat(matArray, 2,vout);
	cout << "图像数组竖向连接" << endl << vout << endl;
	hconcat(matArray, 2, hout);
	cout << "图像数组横向连接" << endl << hout << endl;
	waitKey();
	
}
