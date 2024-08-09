#include <iostream>
using namespace std;
#include <opencv2/opencv.hpp>
using namespace cv;
#include <vector>

/* 3.3.2：图像尺寸变换 */

int main()
{
	Mat img = imread("lena.png");
	if (img.empty())
	{
		cerr << "Please check filename" << endl;
		return -1;
	}

	Mat result1;
	resize(img, result1,Size(0,0), 2, 1, INTER_CUBIC);
	imshow("result_desize", result1);
	waitKey();

	Mat result2;
	resize(img, result2, Size(200, 500), 0, 0,INTER_AREA);
	imshow("result_fxfy", result2);
	waitKey();

	destroyAllWindows();
	return 0;
}
