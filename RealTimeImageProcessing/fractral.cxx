#include<iostream>
#include"Bitmap.h"
#include"Mandelbrot.h"
using namespace std;
using namespace myStd;

int main()
{
	int const WIDTH = 800;
	int const HEIGHT = 600;

	double min = 99999;
	double max = -99999;
	Mandelbrot mandelbrot;
	Bitmap bitmap(WIDTH,HEIGHT);
	for(int y =0; y < HEIGHT; y++)
	{
		for(int x = 0; x < WIDTH; x++)
		{
		
		
		double xFractral = (x- WIDTH/2)*(2.0/HEIGHT);
		double yFractral = (y-HEIGHT/2)*(2.0/HEIGHT);
		int iterations = mandelbrot.getIteration(xFractral, yFractral);
		uint8_t color = (uint8_t) (256*(double)iterations/mandelbrot.MAX_ITERATIONS); 
		color = color * color * color;
		bitmap.setPixel(x, y, 0, color, 0);
				
		if(xFractral < min) min = xFractral;
		if(xFractral > max) max = xFractral;
		

		}
	}

	bitmap.write("fractral.bmp");
	cout << "Compile success " << endl;
	return 0;
}
