#include <iostream>
using namespace std;
#include <opencv2/opencv.hpp>
using namespace cv;
#include <vector>

/* 3.3.3：图像翻转变换 */

int main()
{
	Mat img = imread("lena.png");
	if (img.empty())
	{
		cerr << "Please check filename" << endl;
		return -1;
	}

	Mat matrix1= getRotationMatrix2D(Point2f(img.cols / 2, img.rows / 2),-60, 1);//计算仿射变换矩阵

	Mat result1;
	Size dst_size (img.rows, img.cols);
	warpAffine(img, result1, matrix1, dst_size,INTER_NEAREST,BORDER_CONSTANT,0);//进行仿射变换
	imshow("wrap1", result1);
	waitKey();

	//根据定义的3个点进行仿射变换
	Point2f src_point[3];
	Point2f dst_point[3];

	src_point[0] = Point2f(0, 0);//左上
	src_point[1] = Point2f(0, (float)(img.cols - 1));//右上
	src_point[2] = Point2f((float)(img.cols - 1), (float)(img.rows - 1));//右下

	dst_point[0] = Point2f((float)(img.rows)*0.11, (float)(img.cols) * 0.20);
	dst_point[1] = Point2f((float)(img.rows) * 0.15, (float)(img.cols) * 0.70);
	dst_point[2] = Point2f((float)(img.rows) * 0.81, (float)(img.cols) * 0.85);

	Mat matrix2 = getAffineTransform(src_point, dst_point);//计算仿射变换矩阵

	Mat result2;
	warpAffine(img, result2, matrix2, dst_size);
	imshow("wrap2", result2);
	waitKey();

	destroyAllWindows();
	return 0;
}
