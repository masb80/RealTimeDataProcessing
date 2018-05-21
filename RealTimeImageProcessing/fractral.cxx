#include<iostream>
#include"Bitmap.h"
using namespace std;
using namespace myStd;

int main()
{
	int const WIDTH = 800;
	int const HEIGHT = 600;

	double min = 99999;
	double max = -99999;
	Bitmap bitmap(WIDTH,HEIGHT);
	for(int y =0; y < HEIGHT; y++)
	{
		for(int x = 0; x < WIDTH; x++)
		{
	//		bitmap.setPixel(x, y, 255, 0, 255);
		double xFractral = (x- WIDTH/2)*(2.0/WIDTH);
		double yFractral = (y-HEIGHT/2)*(2.0/HEIGHT);
		if(xFractral < min) min = xFractral;
		if(xFractral > max) max = xFractral;


		}
	}
	cout << min << ", " << max << endl;

	bitmap.write("fractral.bmp");
	cout << "Compile success " << endl;
	return 0;
}
