#include <iostream>
using namespace std;
#include <opencv2/opencv.hpp>
using namespace cv;



int main()
{
	Mat img = imread("lena.png",IMREAD_COLOR);
	if (img.empty())
	{
		cerr << "please check filename" << endl;
		return -1;
	}
	imshow("src", img);//显示原图
	waitKey();
	

	//turn to gray
	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	imshow("gray", gray);
	waitKey();


	//彩色图像binary二值化
	Mat img_b, img_b_i;
	threshold(img, img_b, 128, 255, THRESH_BINARY);
	imshow("img_b", img_b);
	waitKey();

	threshold(img, img_b_i, 128, 255, THRESH_BINARY_INV);
	imshow("img_b_i", img_b_i);
	waitKey();

	destroyWindow("img_b");
	destroyWindow("img_b_i");

	//灰色图像二值化
	Mat binary, binary_inv, trunc, tozero, tozero_inv, otsu, triangle;
	
	//using BINARY(inv)
	threshold(gray, binary, 128, 255, THRESH_BINARY);
	imshow("binary", binary);
	waitKey();

	threshold(gray, binary_inv, 128, 255, THRESH_BINARY_INV);
	imshow("binary_inv", binary_inv);
	waitKey();

	destroyWindow("binary");
	destroyWindow("binary_inv");


	//using TRUNC
	threshold(gray, trunc, 128,255,THRESH_TRUNC);
	imshow("trunc", trunc);
	waitKey();
	
	destroyWindow("trunc");


	//using TOZERO(inv)
	threshold(gray,tozero,128,255,THRESH_TOZERO);
	imshow("tozero", tozero);
	waitKey();

	threshold(gray, tozero_inv, 128, 255, THRESH_TOZERO_INV);
	imshow("tozero_inv", tozero_inv);
	waitKey();
    
	destroyWindow("tozero");
	destroyWindow("tozero_inv");
	

	//OTSU and TRIANGLE ,both of them only can input array CV_8UC1
	//大津法(OTSU)二值化
	//using OTSU
	Mat img_otsu;
	threshold(gray, img_otsu, 0, 255, THRESH_BINARY | THRESH_OTSU);
	imshow("otsu", img_otsu);
	waitKey();

	//三角形法(TRIANGLE)法二值化
	//using TRIANGLE
	Mat img_tri;
	threshold(gray, img_tri, 0, 255, THRESH_BINARY | THRESH_TRIANGLE);
	imshow("triangle", img_tri);
	waitKey();

	destroyAllWindows();
	return 0;

}
