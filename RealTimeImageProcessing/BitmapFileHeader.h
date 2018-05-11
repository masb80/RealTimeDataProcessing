// C++ preprocessor language
// preprocessor run this before the code compile
#ifndef BITMAPFILEHEADER_H_
// we are defining below
#define BITMAPFILEHEADER_H_

#include<cstdint>

using namespace std;

#pragma  pack(2) // usually c++ has padding. it will keep data structure exactly. no semicolon cz no it is a preprocessor directive
namespace myStd
{
	struct BitmapFileHeader
	{
		char header[2]{'B','M'}; // format will work only c++11
		int fileSize; // int making all 32 bits atleast will work
		int32_t reserved{0};// garultee to be 32 bits, initialied with 0
		int32_t  dataOffset; // how long into the file data will be  

	};
}




#endif /* BITMAPFILEHEADER_H_ */
