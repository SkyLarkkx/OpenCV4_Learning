#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include <opencv2/opencv.hpp>
using namespace cv;


/*2.3.2:摄像头调用*/

int main()
{
	
	system("color F0");
	VideoCapture video(0);
	namedWindow("video", WINDOW_AUTOSIZE);

	system("cls");
	if (video.isOpened())
	{
		cout << "视频文件的当前位置(ms)= " << video.get(CAP_PROP_POS_MSEC) << endl;
		cout << "视频流中图像的宽度= " << video.get(CAP_PROP_FRAME_WIDTH) << endl;
		cout << "视频流中图像的高度= " << video.get(CAP_PROP_FRAME_HEIGHT) << endl;
		cout << "视频流中图像的帧率= " << video.get(CAP_PROP_FPS) << endl;
		cout << "编解码器的四字符代码= " << video.get(CAP_PROP_FOURCC) << endl;
		cout << "视频流中图像的帧数= " << video.get(CAP_PROP_FRAME_COUNT) << endl;
		cout << "返回的Mat对象的格式= " << video.get(CAP_PROP_FORMAT) << endl;
		cout << "图像的亮度= " << video.get(CAP_PROP_BRIGHTNESS) << endl;
		cout << "图像对比度= " << video.get(CAP_PROP_CONTRAST) << endl;
		cout << "图像饱和度= " << video.get(CAP_PROP_SATURATION) << endl;
		cout << "图像的色调= " << video.get(CAP_PROP_HUE) << endl;
		cout << "图像的增益= " << video.get(CAP_PROP_GAIN) << endl;
	}
	else
	{
		cout << "请确认视频文件名称是否正确" << endl;
		return -1;
	}
	
	while (true)
	{
		
		Mat frame;
		video >> frame;
		if(frame.empty())
		{
			break;
		}
		imshow("video", frame);
		if (waitKey(30) > 0) break;
	}
	
	//释放摄像头资源
	video.release();

	//销毁所有窗口
	destroyAllWindows();

	return 0;
}