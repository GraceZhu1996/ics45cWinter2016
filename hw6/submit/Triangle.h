#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"
class Triangle: public Shape
{
public:
	Triangle(double newHeight = 0, double newBase = 0):Shape(newHeight/2,newBase/2 )
		{
			height = newHeight;
			base = newBase;
			;

		}
	virtual double area()
		{
			return height*base/2;
		}
	virtual void draw()
		{
			for (int h = 1, m = 2; h <height; h++, m+=2)
			{
				int b = 0, a;
				for (a = b; b <=(base*2-m)/2;b++)
					cout <<" ";
				cout << "*";
				for (; a<(base-b); a++)
					cout <<"  ";
				cout << "*\n";
			}
			for (int n = 0; n < base+1; n++)
				cout << "**";
			cout <<endl;

		}
private:
	double height, base;
};
#endif
