#include<iostream>
#include"Bitmap.h"
using namespace std;
using namespace myStd;

int main()
{
	int const WIDTH = 800;
	int const HEIGHT = 600;
	Bitmap bitmap(WIDTH,HEIGHT);
	for(int y =0; y < HEIGHT; y++)
	{
		for(int x = 0; x < WIDTH; x++)
		{
			bitmap.setPixel(x, y, 255, 0, 255);

			
		}
	}

	bitmap.write("fractral.bmp");
	cout << "Compile success " << endl;
	return 0;
}
