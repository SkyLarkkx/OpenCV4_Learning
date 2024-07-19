#include <iostream>
using namespace std;
#include <opencv2/opencv.hpp>
using namespace cv;

/*2.4.3:保存和读取 XML 和 YMAL 文件*/

/*
cv::FileStorage::FileStorage(const String& filename,//打开的文件名称
	                         int flags,//对文件的操作类型标志
	                         const String&encoding=String()//编码格式，需要使用UTF-8XML 编码
                            );
*/

int main()
{
	system("color F0");

	string filename = "datas.xml";//文件名
	//string filename = "datas.yaml";//文件名

	//写入模式打开文件
	FileStorage fwrite(filename, FileStorage::WRITE);

	//存入矩阵Mat类型的数据
	Mat mat = Mat::eye(3, 3, CV_8U);
	fwrite.write("mat", mat);

	//存入浮点型数据
	float x = 100.123;
	fwrite << "x" << x;

	//存入字符串型数据
	String str = "string type writing test";
	fwrite.write("string", str);


	//存入数组，节点名称为 number_array
	fwrite << "number_array" << "[" << 4 << 5 <<  6 << "]";

	//存入多 node 节点数据，主名称 multi_nodes
	fwrite << "multi_nodes" << "{" << "year" << 2024 << "month" << 7 << "day" << 16 << "time" << "[" << 1 << 7 << 3 << 6 << "]" << "}";

	//关闭文件
	fwrite.release();

	//以读取方式打开文件
	FileStorage fread(filename, FileStorage::READ);

	//判断是否成功打开文件
	if (!fread.isOpened())
	{
		cerr << "打开文件失败，请确认文件的名称是否正确" << endl;
		return -1;
	}

	//读取 Mat 类型数据
	Mat matread;
	fread["mat"] >> matread;
	cout << "mat =" << endl << mat << endl << endl;

	//读取浮点型数据
	float xread;
	fread["x"] >> xread;
	cout << "float x = " << x << endl << endl;

	String Strread;
	fread["string"] >> Strread;
	cout << "string = " << Strread << endl << endl;

	//读取含多个数据的 number_array 节点
	FileNode filenode = fread["number_array"];
	cout << "number_array =[ ";
	for (FileNodeIterator i = filenode.begin();i!=filenode.end();i++)
	{
		float a;
		*i >> a;
		cout << a << " ";
	}
	cout << "]" << endl << endl;

	//读取含有多个子节点的节点数据，不使用 FileNode 和 迭代器 进行读取
	FileNode multinode = fread["multi_nodes"];
	int year = (int)multinode["year"];
	int month = (int)multinode["month"];
	int day = (int)multinode["day"];

	cout<< "multi_nodes : " << endl
		<< "year= " << year << endl
		<< "month= " << month << endl
		<< "day= " << day << endl
		<< "time= ";

	for (int i = 0;i < 4;i++)
	{
		int a = (int)multinode["time"][i];
		cout << a << " ";
	}
	cout << endl;


	//关闭文件
	fread.release();

	return 0;
}