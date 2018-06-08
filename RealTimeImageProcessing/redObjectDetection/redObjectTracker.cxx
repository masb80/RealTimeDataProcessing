#include<iostream>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	namedWindow("Color_Control", CV_WINDOW_AUTOSIZE); // taking a window for cntroling color 
	// HSV(Hue, saturation, value) color conversion
	int iLowH = 0;
	int iHighH = 179;
	
	int iLowS = 0;
	int iHighS = 255;
	
	int iLowV = 0;
	int iHighV = 255;
	
	cvCreateTrackbar("LowH","Color_Control", &iLowH, 179);
	cvCreateTrackbar("HighH","Color_Control", &iHighH, 179);
	
	VideoCapture cap(0);
	if(!cap.isOpened())
	{
		cout << " Can not open the video or webcam" << endl;
		return -1;
	}
	Mat imgTemp;
	cap.read(imgTemp); // start a video temporary

	cout << "initial successfull" << endl;
	bool eventStart = true;
	while(eventStart) // eventing start
	{
		Mat imageOriginal;
		
		bool newFrameFromWindow = cap.read(imageOriginal);
		if(!newFrameFromWindow)
		{
			cout << "Can not read frame from video" << endl;
		}
		
		cout <<"image original" << imageOriginal.size() << endl;
	
		// Conver BGR to HSV
		Mat imageHSV;
		cvtColor(imageOriginal, imageHSV, COLOR_BGR2HSV);
		
		// image HSV format thresholded
		Mat imageThresholded;
		inRange(imageHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imageThresholded);
		cout <<"image Thresolded" << imageThresholded.size() << endl;
		// 
		if(waitKey(30)==27)
		{
			cout << "esc key pressed" << endl;
			break;
		}
	}
	return 0;
}
