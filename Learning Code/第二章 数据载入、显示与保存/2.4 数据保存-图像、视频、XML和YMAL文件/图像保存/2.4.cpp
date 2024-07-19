#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include <opencv2/opencv.hpp>
using namespace cv;


/*2.4.1:图像的保存*/

int main()
{
    // 打开默认摄像头（设备ID为0）
    VideoCapture cap(0);

    // 检查摄像头是否成功打开
    if (!cap.isOpened()) {
        cerr << "Error: Could not open camera" << std::endl;
        return -1;
    }

    // 创建一个窗口来显示摄像头的输出
    namedWindow("Camera Feed", WINDOW_AUTOSIZE);

    Mat frame;
    while (true) {
        // 读取摄像头的当前帧
        cap >> frame;

        // 检查帧是否为空
        if (frame.empty()) {
            cerr << "Error: Blank frame grabbed" << std::endl;
            break;
        }

        // 显示当前帧
        imshow("Camera Feed", frame);

        // 等待30毫秒并检查是否按下了键盘上的任何键
        int key = waitKey(30);
        if (key >= 0) {
            if (key == 's') {
                // 保存图像
                //只有文件名则存放在项目路径，可以直接单独使用路径和文件名
                //string filename = "captured_frame.jpg";
                string filename = "C:/Users/Wentao Qiu/Desktop/captured_frame.jpg";
                if (imwrite(filename, frame)) {
                    cout << "Image saved to " << filename << endl;
                }
                else {
                    cerr << "Error: Could not save image" <<endl;
                }
            }
            break;
        }
    }

    // 释放摄像头资源
    cap.release();
    // 销毁所有窗口
    destroyAllWindows();

    return 0;

}