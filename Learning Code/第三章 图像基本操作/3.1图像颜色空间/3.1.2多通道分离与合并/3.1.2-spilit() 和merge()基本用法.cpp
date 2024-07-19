#include <iostream>
using namespace std;
#include <opencv2/opencv.hpp>
using namespace cv;
#include <vector>

/*3.3.1:颜色模型与转换*/


int main()
{
	Mat img = imread("lena.png");
	if (img.empty())
	{
		cerr << "check filename" << endl;
		return -1;
	}

	Mat HSV;
	cvtColor(img, HSV, COLOR_RGB2HSV);
	Mat imgs0, imgs1, imgs2;//用于存放数组类型结果
	Mat result0, result1, result2;//多通道合并的结果

	/*
	*
	//输入数组参数的多通道分离和合并
	Mat imgs[3];
	split(img, imgs);
	imgs0 = imgs[0];
	imgs1 = imgs[1];
	imgs2 = imgs[2];

	imshow("RGB-B", imgs0);//显示分离后 B 通道像素值
	imshow("RGB-G", imgs1);
	imshow("RGB-R", imgs2);

	imgs[2] = img;//将数组中的图像通道数变得不一致
	merge(imgs, 3, result0);
	//imshow("result0", result0);//imshow只能显示三通道图像，得在Image Watch 桑查看

	Mat zero = Mat::zeros(img.rows, img.cols, CV_8UC1);
	imgs[0] = zero;
	imgs[2] = zero;
	merge(imgs, 3, result1);//用于还原G通道真实情况
	imshow("result1", result1);//显示合并结果

	*/

	//输入vector参数的多通道分离与合并
	vector<Mat> imgv;
	split(HSV, imgv);
	Mat imgv0, imgv1, imgv2;//用于存放vector类型的结果
	imgv0 = imgv.at(0);
	imgv1 = imgv.at(1);
	imgv2 = imgv.at(2);

	imshow("HSV-H", imgv0);
	imshow("HSV-S", imgv1);
	imshow("HSV-V", imgv2);

	imgv.push_back(HSV);//将vector中的图像通道数变得不一致
	merge(imgv, result2);
	//imshow("reslut2", result2);
	waitKey();
	return 0;
}