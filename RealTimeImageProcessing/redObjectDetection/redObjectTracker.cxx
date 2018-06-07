#include<iostream>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	namedWindow("Control Color", CV_WINDOW_AUTOSIZE); // taking a window for cntroling color 
	 
	VideoCapture cap(0);
	Mat imgTemp;
	//cap.read(imgTemp); // start a video temporary

	cout << "initial successfull" << endl;

	while(true) // eventing start
	{
		if(waitKey(30)==27)
		{
			cout << "esc key pressed" << endl;
			break;
		}
	}
	return 0;
}
