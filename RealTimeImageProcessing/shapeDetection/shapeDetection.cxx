#include<iostream>
#include"opencv2/opencv.hpp"
//#include"cv.h"
#include"opencv2/highgui/highgui.hpp"
//#include"highgui.h"
using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	
	cout << "initial successfull" << endl;
	// Read the image file
	IplImage* image = cvLoadImage("finding_shapes_mask.png");
	//original image
	cvShowImage("Shape detection original", image);
	// converting the original image into grayscale
	IplImage * imgGrayScale = cvCreateImage(cvGetSize(image),8,1);
	cvCvtColor(image,imgGrayScale,CV_BGR2GRAY);
	// Thresholding the grayscale image to get better results
	cvThreshold(imgGrayScale, imgGrayScale,128, 255,CV_THRESH_BINARY);
	//making a pointer of contour 
	CvSeq * contours;
	// holding the sequence of contours
	CvSeq * result;
	// Storage the area of contours 
	CvMemStorage * storage = cvCreateMemStorage(0);
	// find all contours in image
	cvFindContours(imgGrayScale, storage, &contours, sizeof(CvContour), CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));

	while(contours)
	{
		//obtain a sequence of points of contour, pointed by the variable 'contour'
		result = cvApproxPoly(contours, sizeof(CvContour), storage, CV_POLY_APPROX_DP, cvContourPerimeter(contours)*0.02, 0);
		// if there are 3 vertices in the contour it should be  a triangle
		if(result->total == 3)
		{
		// iterate through each point
			CvPoint *pt[3];
			for(int i =0; i < 3; i++)
			{
				pt[i] = (CvPoint*)cvGetSeqElem(result,i);
			}
			// drawing the line arround the triangle
			cvLine(image, *pt[0], *pt[1], cvScalar(255,0,0),4);
			cvLine(image, *pt[1], *pt[2], cvScalar(255,0,0),4);
			cvLine(image, *pt[2], *pt[0], cvScalar(255,0,0),4);
		}
		// for quadrilateral
		else if(result->total == 4)
		{
		// iterate through each point
			CvPoint *pt[4];
			for(int i =0; i < 4; i++)
			{
				pt[i] = (CvPoint*)cvGetSeqElem(result,i);
			}
			// drawing the line arround the triangle
			cvLine(image, *pt[0], *pt[1], cvScalar(255,0,0),4);
			cvLine(image, *pt[1], *pt[2], cvScalar(255,0,0),4);
			cvLine(image, *pt[2], *pt[3], cvScalar(255,0,0),4);
			cvLine(image, *pt[3], *pt[0], cvScalar(255,0,0),4);
		}
		else if(result->total == 6)
		{
		// iterate through each point
			CvPoint *pt[6];
			for(int i =0; i < 6; i++)
			{
				pt[i] = (CvPoint*)cvGetSeqElem(result,i);
			}
			// drawing the line arround the triangle
			cvLine(image, *pt[0], *pt[1], cvScalar(255,0,0),4);
			cvLine(image, *pt[1], *pt[2], cvScalar(255,0,0),4);
			cvLine(image, *pt[2], *pt[3], cvScalar(255,0,0),4);
			cvLine(image, *pt[3], *pt[4], cvScalar(255,0,0),4);
			cvLine(image, *pt[4], *pt[5], cvScalar(255,0,0),4);
			cvLine(image, *pt[5], *pt[0], cvScalar(255,0,0),4);
			//cvLine(image, *pt[6], *pt[0], cvScalar(255,0,0),4);
		}
		else if(result->total == 10)
		{
		// iterate through each point
			CvPoint *pt[10];
			for(int i =0; i < 10; i++)
			{
				pt[i] = (CvPoint*)cvGetSeqElem(result,i);
			}
			// drawing the line arround the triangle
			cvLine(image, *pt[0], *pt[1], cvScalar(0,0,255),4);
			cvLine(image, *pt[1], *pt[2], cvScalar(0,0,255),4);
			cvLine(image, *pt[2], *pt[3], cvScalar(0,0,255),4);
			cvLine(image, *pt[3], *pt[4], cvScalar(0,0,255),4);
			cvLine(image, *pt[4], *pt[5], cvScalar(0,0,255),4);
			cvLine(image, *pt[5], *pt[6], cvScalar(0,0,255),4);
			cvLine(image, *pt[6], *pt[7], cvScalar(0,0,255),4);
			cvLine(image, *pt[7], *pt[8], cvScalar(0,0,255),4);
			cvLine(image, *pt[8], *pt[9], cvScalar(0,0,255),4);
			cvLine(image, *pt[9], *pt[0], cvScalar(0,0,255),4);
		}
		contours = contours->h_next;	
	}	
	cvNamedWindow("Shape Detected");
	cvShowImage("Shape Detected", image);
	
	cvWaitKey(0); // wait for key press
	
	// clean up the memory
	cvDestroyAllWindows();
	cvReleaseMemStorage(&storage);
	cvReleaseImage(&image);
	cvReleaseImage(&imgGrayScale);
	return 0;
}
