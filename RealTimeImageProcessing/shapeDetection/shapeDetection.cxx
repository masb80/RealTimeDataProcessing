#include<iostream>
#include"opencv2/opencv.hpp"
using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	// Read the image file
	 Mat image = imread("samad.jpg");

	  // Check for failure
	 if (image.empty()) 
	 {
		 cout << "Could not open or find the image" << endl;
		 cin.get(); //wait for any key press
		 return -1;
	 }
	 String windowName = "Shape Detection";
	 namedWindow(windowName);
	 imshow(windowName, image);

	cout << "initial successfull" << endl;
	bool eventStart = true;
	while(eventStart) // eventing start
	{
		
		if(waitKey(30)==27)
		{
			cout << "esc key pressed" << endl;
			break;
		}
	}
	destroyWindow(windowName); //destroy the created window
	return 0;
}
