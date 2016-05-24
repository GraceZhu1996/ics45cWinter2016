/*(40 points) Derive a total of four classes from Shape: derive three classes (Circle, Square, and Triangle) directly from your abstract base class and make them concrete by providing implementations for the virtual functions introduced in your abstract base class Shape. The methods for each of these three classes must actually behave differently from one another (example: Circle area vs. Square area vs. Triangle area). 
 */
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
#define Pi 3.14159
class Circle:public Shape
{
public:
	Circle(double newRadius = 0):Shape(newRadius, newRadius)
		{
			radius = newRadius;
		};
	
	virtual double area()
		{
			return Pi * radius * radius ;
		};
	virtual void draw()
		{
			cout <<
				"          ***         \n"<<
			    "    *            *    \n"<<
				"  *                *  \n"<<
				" *                  * \n"<<
				"*                    *\n"<<
				"*                    *\n"<<
				" *                  * \n"<<
				"  *                *  \n"<<
			    "    *            *    \n"<<
				"         ****         \n"<<endl;				
				
		};

		
private:
	double radius;
};
#endif
