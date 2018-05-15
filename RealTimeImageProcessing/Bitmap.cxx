#include"Bitmap.h"

using namespace std;
namespace myStd
{
	Bitmap::Bitmap(int width, int height): m_width(width), m_height(height), m_pPixels(new uint8_t[width * height * 3]) // times 3 cz uint8_t
	{
	
	}
	bool Bitmap::write(string filename)
	{
	return false;
		
	}
	void Bitmap::setPixel(int x, int y, uint8_t green, uint8_t blue, uint8_t red)
	{
		
	}
	Bitmap::~Bitmap(){}
}
