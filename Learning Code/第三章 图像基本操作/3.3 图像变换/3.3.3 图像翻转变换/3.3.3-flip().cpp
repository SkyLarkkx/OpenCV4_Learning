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

	Mat dst1, dst2, dst3;
	flip(img, dst1, 1);//round y
	imshow("round y", dst1);
	waitKey();
	
	flip(img, dst2, 0);//round x
	imshow("round x", dst2);
	waitKey();
	
	flip(img, dst3, -1);//round 180°
	imshow("round 180", dst3);
	waitKey();

	return 0;

}
