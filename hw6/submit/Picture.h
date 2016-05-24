/* (20 points) Write a class Picture that holds a list of Shapes.  Include methods to add a Shape to this picture.  Define two polymorphic functions that operate on a Picture: drawAll() and totalArea(). Implement Picture as a LinkedList of Shapes. */
#ifndef PICTURE_H
#define PICTURE_H
#include "Shape.h"
class Picture
{
public:
	Picture ()
		{

		    head = nullptr;

		}
 
	void drawAll()
		{
			for (LinkedList * temp = head; temp != nullptr; temp = temp->next)
			{
				temp->info->draw();
				cout << endl;
			}
		}
	double totalArea()
		{
			double sum = 0;
			for (LinkedList * temp = head; temp != nullptr; temp = temp->next)
				sum += temp->info->area();
			return sum;
		}
	void add (Shape*s)
		{
			head = new LinkedList(s, head);
		}
	~Picture()
		{
			LinkedList::deleteList(head);
		}
private:

	struct LinkedList
	{
		Shape* info;
		LinkedList * next;
		LinkedList(Shape *newInfo, LinkedList * newNext=nullptr)
			:info(newInfo), next(newNext){}


		static void deleteList(LinkedList * L)
			{
				if (L!= nullptr)
				{
					deleteList(L->next);
					delete L;
				
				}
			}
		
		
	};
	LinkedList * head;
};
#endif
