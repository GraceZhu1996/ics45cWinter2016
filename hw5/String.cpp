
#include "String.h"

String::String(const char * s)
{
	head = ListNode::stringToList(s);
}

String::String(const String & s)
{
	head = ListNode::copy(s.head);
}

String String::operator =(const String & s)
{
	ListNode::deleteList(head);
	head = ListNode::copy(s.head);
	return *this;
}

char & String::operator [](const int index)
{

	return ListNode::FindByIndex(head, index);
}

int String::indexOf(char c) const
{
	return ListNode::FindIndexOf(head, c, 0);

}

bool String::operator ==(const String & s) const
{
	return ListNode::compare(head,s.head) == 0;
}

bool String::operator <(const String & s) const
{
	return ListNode::compare(head, s.head) > 0;
}

String String::operator +(const String & s) const
{
	String str;
	str.head =  ListNode::concat(head, s.head);
	return str;
}

String String::operator +=(const String & s)
{
	*this = *this + s;
	return *this;
}

void String::print(ostream & out)
{
	ListNode* temp = head;
	while (temp != nullptr)
	{
		out << temp ->info;
		temp = temp->next;
	}
	ListNode::deleteList(temp);
}

void String::read(istream & in)
{
	ListNode::deleteList(head);
	char * ptr = new char[10000];
	in.getline(ptr, 10000);
	head = ListNode::stringToList(ptr);
	delete [] ptr;
}
void String::deleteNode(int d)
{
	ListNode::deleteNode(head, d);
}
String::~String()
{
	ListNode::deleteList(head);
}

String::ListNode *String::ListNode::stringToList(const char *s)
{
	return *s == '\0' ? nullptr: new ListNode(*s, stringToList(s+1));
}
String::ListNode *String::ListNode::copy(ListNode * L)
{
	return L == nullptr ? nullptr: new ListNode( L->info, copy( L->next ) );

}
bool String::ListNode::equal(ListNode * L1, ListNode * L2)
{
	return L1 == nullptr || L2 == nullptr ? L1 == L2
      : L1->info == L2->info && equal( L1->next, L2->next );
}

String::ListNode * String::ListNode::concat(ListNode * L1, ListNode * L2)
{
	if (L1 == nullptr)
		return copy(L2);
	else
		return new ListNode (L1->info, concat(L1->next,L2));

}

int String::ListNode::compare(ListNode * L1, ListNode * L2)
{
	if (L1==nullptr & L2 != nullptr)
		return 0-L2->info;
    else if (L2==nullptr & L1 != nullptr)
		return L1->info - 0;
	else if (L1 == nullptr && L2 == nullptr)
		return 0;
	else if (L1->info == L2->info)
		return compare(L1->next, L2->next);
    else
		return L1->info - L2->info;

}
char & String::ListNode:: FindByIndex(ListNode * L, int n)
{
	// if (L == nullptr)
	// 	return (char &)"\0";
	// else if (n == 0)
	// 	return L->info;
	// else
	// 	return FindByIndex (L->next, n-1);
	return L== nullptr?(char &)"\0":n==0?L->info:FindByIndex (L->next, --n);
}
int String::ListNode::FindIndexOf(ListNode * L, char c, int n)
{
	// if (L == nullptr)
	// 	return '\0';
	// else if (L-> info == c)
	// 	return n;
	// else
	// 	return FindIndexOf(L->next, c, ++n);
	return L==nullptr?-1:L->info == c ? n : FindIndexOf(L->next, c, ++n);
}
void String::ListNode::deleteList(ListNode * L)
{
    if ( L != NULL )
    {
      deleteList( L->next );
      delete L;
    }
}

int String::ListNode::length(ListNode * L)
{
	return L == nullptr ? 0 : 1 + length(L->next);
}

void String::ListNode::deleteNode(ListNode * L, int d)
{
    ListNode * temp1 = L;
	ListNode * temp2 = L;
    for (int i = 0; temp1 != nullptr; i++, temp1=temp1->next,temp2=temp2->next)
    {
        if(i+1 == d)
		{
			temp2->next=temp2->next->next;
			delete temp1->next;
			break;
		}
    }
}
ostream & operator << ( ostream & out, String str )
{
	str.print(out);
	return out;
}

istream & operator >> ( istream & in, String & str )
{
	str.read(in);
	return in;
}
void String::error( char * p )
    {
      cerr << "Error (class String): " << p << endl;
    }
