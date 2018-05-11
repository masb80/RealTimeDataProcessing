// C++ preprocessor language
// preprocessor run this before the code compile
#ifndef BITMAPINFOHEADER_H_
// we are defining below
#define BITMAPINFOHEADER_H_

#include<cstdint>

using namespace std;

#pragma  pack(2) // usually c++ has padding. it will keep data structure exactly. no semicolon cz no it is a preprocessor directivenamespace mystd
namespace myStd
{
	struct BitmapInfoHeader
	{
		int32_t headerSize{40};// total int size in here 40. int32_t is in c standard which is as int, int16_t is as short int 
		int32_t  width; //  
		int32_t  height; //  
		int16_t  planes{1}; // we use 1 bite in each color RGB,  int16_t is as short int
		int16_t  bitsPerPixel{24}; //
		int32_t  compression{0}; //
		int32_t  dataSize{0}; //
		int32_t  horizontalResolution{2400}; // 2400 bit per pixel
		int32_t  verticalResolution{2400}; //
		int32_t colors{0}; //
		int32_t ImportantColors{0}; //
	};
}




#endif /* BITMAPFILEHEADER_H_ */
