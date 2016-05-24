// (20 points) Write a main program that builds a Picture and fills it with two triangles, two circles, two squares, and two rectangles (Specified below).  Then have it call drawAll(), then have it print out the totalArea() of the shapes on that picture.


// 	FirstTriangle: height=5, base=5
// 	SecondTriangle: height=4, base=3

// 	FirstCircle: radius = 5
// 	SecondCircle: radius = 10

// 	FirstSquare: side=5
// 	SecondSqaure: side = 10

// 	FirstRectangle: height = 4 width=8
// 	SecondRectangle: height=8 width=4

#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"
#include "Picture.h"
int main()
{
	Picture pic;
	Triangle FirstTriangle(5,5);
	pic.add(&FirstTriangle);
	Triangle SecondTriangle(4,3);
	pic.add(&SecondTriangle);
	Circle FirstCircle(5);
	pic.add(&FirstCircle);
	Circle SecondCircle(10);
	pic.add(&SecondCircle);
	Square FirstSquare(5);
	pic.add(&FirstSquare);
	Square SecondSqaure(10);
	pic.add(&SecondSqaure);
	Rectangle FirstRectangle(4,8);
	pic.add(&FirstRectangle);
	Rectangle SecondRectangle(8,4);
	pic.add(&SecondRectangle);
	pic.drawAll();
	cout << "Total area is: " << pic.totalArea() << endl;
	
	return 0;
}

//g++ main.cpp -g -o test
