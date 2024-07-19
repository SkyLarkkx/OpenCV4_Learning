#include <iostream>
using namespace std;
#include <opencv2/opencv.hpp>
using namespace cv;

#define black Scalar(0,0,0)
#define blue Scalar(255,0,0)

/* 2.4.2：视频的保存 */

/*
cv::VideoWriter::VideoWriter();//默认构造函数
cv::VideoWriter::VideoWriter(const String& filename,//保存视频的地址和文件名，包含视频格式
	                         int fourcc,//压缩帧的4字符编码器解码
	                         double fps,//保存视频的帧率
	                         Size frameSize,//视频帧的尺寸
	                         bool isColor = true
                            );
*/

int main()
{
	//Mat image = imread("C:\\Users\\Wentao Qiu\\Desktop\\图片1.jpg");

	VideoCapture video(0);

	if (video.isOpened())
	{
		cout << "The width=" << video.get(CAP_PROP_FRAME_WIDTH) << endl;
		cout << "The height=" << video.get(CAP_PROP_FRAME_HEIGHT) << endl;
		cout << "FPS=" << video.get(CAP_PROP_FPS) << endl;
	}
	else
	{
		cerr << "Please check your filename" << endl;
		return -1;
	}

	Mat image;
	video >> image;
	if (image.empty())
	{
		cerr << "image error loading" << endl;
		return -1;
	}

	bool isColor = (image.type() == CV_8UC3);//判断视频类型是否为彩色

	VideoWriter writer;

	int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');//选择编码格式

	double fps = 120;//选择视频帧率

	string filename = "live.avi";//保存的视频文件名称

	writer.open(filename,codec, 30, image.size(), isColor);//帧率是摄像头实际帧率

	while (true)
	{
		//检测是否执行完毕
		if (!video.read(image))//读取帧，判断能否继续从摄像头或者视频文件读出一帧图像
		{
			cout << "摄像头断开连接或视频读取完成" << endl;
			break;
		}

		writer.write(image);//将图像写入视频流
		//writer << image;
		

		imshow("Live", image);//显示图像
		
		if (waitKey(1000 / fps) == 27)//按“Esc”退出视频保存
		{                             //waitKey(1000 / fps)使每秒只显示设置的视频帧率，否则视频会比正常快
			break;
		}
	}

	//退出视频时自动关闭视频流
	video.release();
	writer.release();

	return 0;
}