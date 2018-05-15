#include<iostream>
#include"Bitmap.h"
using namespace std;
using namespace myStd;

int main()
{
	Bitmap bitmap(800,600);
	bitmap.write("fractral.bmp");
	cout << "Compile success " << endl;
	return 0;
}
