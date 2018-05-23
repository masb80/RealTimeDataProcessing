// C++ preprocessor language
// preprocessor run this before the code compil#ifndef BITMAP_H_
#ifndef MANDELBROT_H_
// we are defining below
#define MANDELBROT_H_

#include<cstdint>
#include<string>
#include<memory>
using namespace std;

namespace myStd
{	
	class Mandelbrot
	{
		public:
			static const int MAX_ITERATIONS = 1000;
			
		public:	
			  int getIteration(double x, double y);
	};
}

#endif 
