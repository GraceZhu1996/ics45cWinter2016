/*Derive the fourth class, Rectangle, from Square and add a width.  For draw() use character graphics.  The shapes should resemble the shape defined by the class.
 */
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Square.h"

class Rectangle: public Square
{
public:
	Rectangle (double newHeight = 0, double newWidth = 0):Square(newHeight)
		{
			height = newHeight;
			width = newWidth;
			;
		}
	virtual double area()
		{
			return height*width;
		}

	virtual void draw()
		{
			for (int col = 0; col < width; col++)
				cout << "* ";
			cout << "\n";
			for (int row = 2; row < height; row++)
			{
				cout << "*";
				for (int col = 1; col < (width-1)*2; col++)
					cout << " ";
				cout << "*\n";
			}
			for (int col = 0; col < width; col ++)
				cout << "* ";
			cout << endl;
		}
	
private:
	double height, width;
};
#endif
