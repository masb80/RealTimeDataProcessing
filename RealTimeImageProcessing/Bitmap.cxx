#include<fstream>
#include"Bitmap.h"
#include"BitmapInfoHeader.h"
#include"BitmapFileHeader.h"

using namespace std;
using namespace myStd;
namespace myStd
{
	Bitmap::Bitmap(int width, int height): m_width(width), m_height(height), m_pPixels(new uint8_t[width * height * 3]{}) // times 3 cz uint8_t, every pixel will take 3 bytes
	{
	
	}
	bool Bitmap::write(string filename)
	{
		BitmapFileHeader fileHeader;
		BitmapInfoHeader infoHeader;

		fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width*m_height*3; // file size 
		fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader); // how data will be in file
	infoHeader.width = m_width;
	infoHeader.height = m_height;

	ofstream file;
	file.open(filename, ios::out | ios::binary);

	if(!file)
	{
		return false;
	}
	file.write((char *) &fileHeader, sizeof(fileHeader));
	file.write((char *) &infoHeader, sizeof(infoHeader));
	file.write((char *) m_pPixels.get(), m_width*m_height*3);

	file.close();
	if(!file)
	{
		return false;
	}
		return true;
		
	}
	void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
	{
		uint8_t * pPixel = m_pPixels.get();// initialize the unique pointer to whole memory screen
		
		pPixel += (y*3)*m_width + (x*3); // initialize in each pixel and then moving forward
		//pointer arithmatic, if we add 1 then it forward by 1 byte
		// initially thinking each pixel has 1 byte of information 
		// pPixel += y*m_pixel, 
		// here y*m_widh is the number byte in pixel between one row
		// since each pixel got 3 bytes, we will multiply by 3
		pPixel[0] = blue; 
		pPixel[1] = green;
		pPixel[2] = red;
		
	
	}
	Bitmap::~Bitmap(){}
}
