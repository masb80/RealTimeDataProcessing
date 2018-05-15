// C++ preprocessor language
// preprocessor run this before the code compile
#ifndef BITMAP_H_
// we are defining below
#define BITMAP_H_

#include<cstdint>
#include<string>
#include<memory>
using namespace std;

namespace myStd
{	
	class Bitmap
	{
		private:
			int m_width{0};
			int m_height{0};
	// unsigned char is equivalent to uint8_t in C
		unique_ptr<uint8_t[]>m_pPixels{nullptr}; // c++11 is giving me the freedom of initialization
		public:	
			Bitmap(int width, int height);
			bool write(string filename); 
			void setPixel(int x, int y, uint8_t green, uint8_t blue, uint8_t red); // uint8_t is char type 
			virtual ~Bitmap();
	};
}

#endif /* BITMAP_H_ */
