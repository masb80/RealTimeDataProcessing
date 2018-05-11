// C++ preprocessor language
// preprocessor run this before the code compile
#ifndef BITMAP_H_
// we are defining below
#define BITMAP_H_

#include<cstdint>
#include<string>
using namespace std;

namespace myStd
{	
	class Bitmap
	{
		private:
			int m_width{0};
			int m_height{0};
		public:	
			Bitmap(int width, int height);
			bool write(string filename); 
			void setPixel(int x, int y, uint8_t green, uint8_t blue, uint8_t red); // uint8_t is char type 
			virtual ~Bitmap();
	};
}

#endif /* BITMAP_H_ */
