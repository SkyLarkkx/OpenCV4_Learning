#include <iostream>
using namespace std;
#include <opencv2/opencv.hpp>
using namespace cv;



int main()
{
	Mat test1 = imread("C:\\Users\\Wentao Qiu\\Desktop\\old book test1.jpeg",IMREAD_COLOR);
	Mat test2 = imread("C:\\Users\\Wentao Qiu\\Desktop\\old book test2.webp", IMREAD_COLOR);
	if (test1.empty()||test2.empty())
	{
		cerr << "please check filename" << endl;
		return -1;
	}

	//turn to  gray
	Mat gray1, gray2;
	cvtColor(test1, gray1, COLOR_BGR2GRAY);
	cvtColor(test2, gray2, COLOR_BGR2GRAY);

	

	//test1
	namedWindow("test1", WINDOW_NORMAL);
	imshow("test1", test1);
	namedWindow("gray1", WINDOW_NORMAL);
	imshow("gray1", gray1);
	waitKey();

	Mat test1_otsu;
	threshold(gray1, test1_otsu, 0, 255, THRESH_BINARY | THRESH_OTSU);//using OTSU
	namedWindow("otsu1", WINDOW_NORMAL);
	imshow("otsu1", test1_otsu);
	waitKey();

	Mat test1_tri;
	threshold(gray1, test1_tri, 0, 255, THRESH_BINARY | THRESH_TRIANGLE);//using TRIANGLE
	namedWindow("triangle1", WINDOW_NORMAL);
	imshow("triangle1", test1_tri);
	waitKey();

	Mat test1_apt_mean;
	adaptiveThreshold(gray1, test1_apt_mean, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 101, 0);//均值法
	namedWindow("adaptive1_mean", WINDOW_NORMAL);
	imshow("adaptive1_mean", test1_apt_mean);
	waitKey();

	Mat test1_apt_gaus;
	adaptiveThreshold(gray1, test1_apt_gaus, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 101, 0);//高斯法
	namedWindow("adaptive1_gaus", WINDOW_NORMAL);
	imshow("adaptive1_gaus", test1_apt_gaus);
	waitKey();

	/*
	imwrite("C:\\Users\\Wentao Qiu\\Desktop\\test1_OTSU.jpeg", test1_otsu);
	imwrite("C:\\Users\\Wentao Qiu\\Desktop\\test1_TRI.jpeg", test1_tri);
	imwrite("C:\\Users\\Wentao Qiu\\Desktop\\test1_APT_MEAN.jpeg", test1_apt_mean);
	imwrite("C:\\Users\\Wentao Qiu\\Desktop\\test1_APT_GAUSSIAN.jpeg", test1_apt_gaus);
	*/
	destroyAllWindows();
	
	
	
	
	//test2
	namedWindow("test2", WINDOW_NORMAL);
	imshow("test2", test2);
	namedWindow("gray2", WINDOW_NORMAL);
	imshow("gray2", gray2);
	waitKey();

	Mat test2_otsu;
	threshold(gray2, test2_otsu, 0, 255, THRESH_BINARY | THRESH_OTSU);//using OTSU
	namedWindow("otsu2", WINDOW_NORMAL);
	imshow("otsu2", test2_otsu);
	waitKey();

	Mat test2_tri;
	threshold(gray2, test2_tri, 0, 255, THRESH_BINARY | THRESH_TRIANGLE);//using TRIANGLE
	namedWindow("triangle2", WINDOW_NORMAL);
	imshow("triangle2", test2_tri);
	waitKey();

	Mat test2_apt_mean;
	adaptiveThreshold(gray2, test2_apt_mean, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 131, 20);//均值法
	namedWindow("adaptive2_mean", WINDOW_NORMAL);
	imshow("adaptive2_mean", test2_apt_mean);
	waitKey();

	Mat test2_apt_gaus;
	adaptiveThreshold(gray2, test2_apt_gaus, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 131, 15);//高斯法
	namedWindow("adaptive2_gaus", WINDOW_NORMAL);
	imshow("adaptive2_gaus", test2_apt_gaus);
	waitKey();

	/*
	imwrite("C:\\Users\\Wentao Qiu\\Desktop\\test2_OTSU.jpeg", test2_otsu);
	imwrite("C:\\Users\\Wentao Qiu\\Desktop\\test2_TRI.jpeg", test2_tri);
	imwrite("C:\\Users\\Wentao Qiu\\Desktop\\test2_APT_MEAN.jpeg", test2_apt_mean);
	imwrite("C:\\Users\\Wentao Qiu\\Desktop\\test2_APT_GAUSSIAN.jpeg", test2_apt_gaus);
	*/
	destroyAllWindows();

	
}
