#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//2.1:图像储存容器

/* ------------------ 2.1.1:Mat类创建-------------------  */

//创建Mat类
Mat A;
A = imread("test.jpg");
Mat B = A;

//声明一个指定类型的Mat类
Mat a = Mat_<double>(3, 3);

//通过OpenCV数据类型创建Mat类
Mat b(640, 480, CV_16UC3);
Mat c(3, 3, CV_8U);


/*--------------- 2.1.2:Mat类构造与赋值----------------- */

/*   1.Mat类的构造     */

//默认构造函数
cv::Mat::Mat();
//e.g: Mat A;

//利用矩阵尺寸和类型参数
cv::Mat::Mat(int rows, int cols, int type);
//e.g: Mat A(10,10,CV_32FC3);

//用Size()结构构造
cv::Mat::Mat(Size size(), int type);//size::Size(cols,rows)
/	

//利用已有矩阵
cv::Mat::Mat(const& m);//m:已经构建完整的Mat类矩阵类型
//一个改动另外一个也会改动,若想不相互影响，则用m=a.clone();

//构造已有Mat类的子类
cv::Mat::Mat(const Mat& m, const Range& rowRange, const Range& colRange = Range::all());//子类与原Mat类共享相同数据，其中一个变化另外也为随之变化
//e.g: Mat a(m,Range(2,5),Range(3,6));




/*       2.Mat类的赋值          */

//构造时赋值
cv::Mat::Mat(int rows, int cols, int type, const Scalar& s);//Scalar结构中变量的个数要与定义中的通道数相对应,大于的不会被读取，少的会以0补充
//e.g: Mat a(2,2,CV_8UC3,Scalar(0,0,255));

//枚举法赋值
cv::Mat a = (cv::Mat_<int>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
//按行存值

//循环法赋值
cv::Mat c= cv::Mat_<int>(3, 3);//定义矩阵
for (int i = 0;i < c.rows;i++)
{
	for (int j = 0;j < c.cols;j++)
	{
		c.at<int>(i, j) = i + j;
    }
}

//利用类方法赋值
cv::Mat a = cv::Mat::eye(3, 3, CV_8UC1);//eye():构建单位矩阵
cv::Mat b = cv::Mat::diag(b);//diag():构建对角矩阵,其参数得为Mat类型的一维变量
cv::Mat c = cv::Mat::ones(3, 3, CV_8UC1);//构建一个全为1的矩阵
cv::Mat d = cv::Mat::zeros(3, 3, CV_8UC3);//构建一个全为0的矩阵

//利用数组进行赋值
float a[8] = { 1,2,3,4,5.6,7,8 };
cv::Mat b = cv::Mat(2, 2, CV_32FC2, a);//从第一个开始依次赋值每个元素的所有通道



/*---------2.1.3:Mat类支持的运算-----------*/

//加减乘除运算

//两个Mat类矩阵的惩罚运算

cv::Mat j, m;
double k;
j = c * d;//数学乘积
k = a.dot(b);//内积
m = a.mul(b);//对应位乘积


/*---------2.1.4:Mat类元素的读取-----------*/

//1.用过at方法读取Mat类矩阵中的元素

//at方法读取Mat类单通道矩阵元素
cv::Mat a = (cv::Mat_<uchar>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
int value = (int)a.at<uchar>(0, 0);
//如果矩阵定义类型为uchar，需要输入数据的时候，需要强制转换int类型输出，否则输出结果不是整数

//……读取多通道矩阵元素
Mat b = (3, 4, CV_8UC3, Scalar(0, 0, 1));//Vec 系列是用于表示固定大小的向量的模板类
cv::Vec3b vc3 = b.at<cv::Vec3b>(0, 0);//cv::Vec3b 是 OpenCV 中的一个数据类型，用于表示一个具有 3 个 8 位无符号字符（即 3 个字节）的向量。它通常用于表示图像中的一个像素值
int first = (int)vc3.val[0];//b（0,0）第一个通道数据
int second = (int)vc3.val[1];
int third = (int)vc3.val[2];

//2.通过指针ptr读取Mat类矩阵中的元素

Mat b(3, 4, CV_8UC3, Scalar(0, 0, 1));
for (int i = 0;i < b.rows;i++)
{
	uchar* ptr = b.ptr<uchar>(i);
	for(int j=0;j<b.cols*b.channels();j++)
	{
		cout << (int)ptr[j] << endl;
	}
}//输出矩阵所有元素

//直接访问
int value = (int)b.ptr<uchar>(1)[2];

//3.通过迭代器访问Mat类矩阵中的元素
cv::MatIterator_<uchar> it = a.begin<uchar>();
cv::MatIterator_<uchar> it_end = a.end<uchar>();
for(int i=0;it!=it_end;it++)
{
	cout << (int)(*it) << " ";
	if (++i % a.cols == 0) 
		cout << endl;
}

//通过矩阵元素的地址定位方式访问元素
(int)(*(b.data + b.step[0] * row + b.step[1] * col + channel));