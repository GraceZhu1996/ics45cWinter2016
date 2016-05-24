#include "String.h"
String::String( const char * s)
{
	strcpy(buf, s);

}
String::String( const String & s)
{
	strcpy(buf, s.buf);
}

String String::operator =(const String & s)
{
	for (int n = 0; n < MAXLEN; n++)
		buf[n] = '\0';
	strcpy(buf, s.buf);
	return *this;
}

char & String::operator [](int index)
{
	if (inBounds(index-1))
		return buf[index-1];
	
	else
		return (char&)"\0";
}

int String::size()
{
	return strlen(buf);
}

String String::reverse()
{
	int n, m;
	char new_buf[MAXLEN];
	for (n = strlen(buf)-1, m = 0; n >= 0; n--, m++)
		new_buf[m] = buf[n];
	return String(new_buf);
}

int String::indexOf(const char c)
{
	int n;
	int index = '\0';
	for (n = 0; n < strlen(buf); n++)
		if(buf[n] == c){
			index = n;
			break;
		}
	return index;
		
}
int String::indexOf(const String pattern)
{
	for (int c = 0; buf[c]!= '\0'; c++){
		if (buf[c] == pattern.buf[0]){
			int n = 0, m = c;
			for (; inBounds(m) && n < strlen(pattern.buf);n++, m++){
				if (buf[m] != pattern.buf[n])
					break;
			}
			if (pattern.buf[n] == '\0')
			{
				return n;
			}
		}
	}
	return '\0';

}

bool String::operator ==(const String s)
{
	if (strcmp(buf, s.buf) == 0)
		return true;
	else
		return false;

}

bool String::operator !=(const String s)
{
	if (strcmp(buf, s.buf) != 0)
		return true;
	else
		return false;
}

bool String::operator >(const String s)
{
	if (strcmp(buf, s.buf) > 0)
		return true;
	else
		return false;
}

bool String::operator <(const String s)
{
	return ((String)s > * this);
}

bool String::operator <=(const String s)
{
	if (strcmp(buf, s.buf) <= 0)
		return true;
	else
		return false;
}

bool String::operator >=(const String s)
{
	if (strcmp(buf, s.buf) >= 0)
		return true;
	else
		return false;
}

String String::operator +(const String s)
{
	char nbuf[MAXLEN];
	strcpy(nbuf, buf);
	String ns(strcat(nbuf, s.buf));
	return ns;
}

String String::operator +=(const String s)
{
	strcat(buf, s.buf);
	return *this;
}

void String::print(ostream & out)
{
	out << "String: ";
	for (int n = 0; n<strlen(buf) && buf[n]!= '\0'; n++)
		out << buf[n];
}

void String::read(istream & in)
{
	in >> buf;
}

String::~String()
{
	//cout << "String " << buf << " has just died" << endl;
}

int String::strlen(const char * s)
{
	int n = 0;
	for (; n < MAXLEN; n++)
		if (s[n] == '\0')
			break;
	return n;
	
}

char * String::strcpy(char * dest, const char * src)
{
	if (strlen(src) <= MAXLEN){
		int n = 0;
		for (; n < strlen(src); n++){
			dest[n] = src[n];
		}
		dest[n] = '\0';
	}
	else
		cout << "size of src char * is bigger than MAXLEN"<< endl;
	return dest;	
}

char * String::strcat(char * dest, const char * src)
{
    if (strlen(dest)+ strlen(src) < MAXLEN){
		for (int n = strlen(dest), m = 0; src[m]!= '\0'; n++, m++){
			dest[n] = src[m];
		}
	}
	else
		cout << "size of result char * exeed MAXLEN: " << MAXLEN << endl;
	return dest;	
}

int String::strcmp(const char * left, const char * right)
	//This function starts comparing the first character of each string. If they are equal to each other, it continues with the following pairs until the characters differ or until a terminating null-character is reached.
{
	int n = 0;
	for (; n <= strlen(left) && n <= strlen(right); n++ ){
		if (left[n] != right[n])
			return left[n] - right[n];

	}
	return left[n-1] - right[n-1];
}

int String::strncmp(const char * left, const char * right, int n)
	//Compares up to num characters of the C string str1 to those of the C string str2.
	//This function starts comparing the first character of each string. If they are equal to each other, it continues with the following pairs until the characters differ, until a terminating null-character is reached, or until num characters match in both strings, whichever happens first.
{
	int m = 0;
	for (; m <= n; m++)
		if (left[m] != right[m])
			return left[m] - right[m];
	return left[m-1] - right[m-1];
}

char * String::strchr(const char * str, int c)
// Returns a pointer to the first occurrence of character in the C string str.
// The terminating null-character is considered part of the C string. Therefore, it can also be located in order to retrieve a pointer to the end of a string.
{

	for (int n = 0; n< MAXLEN; n++ )
		if (str[n] == c){
			const char * ptr;
			ptr = & str[n];
			return (char*)ptr;
		}
	cout << "Can't find character c in char * str"<< endl;
	return (char*)'\0';
}

char * String::strstr(const char * haystack, const char * needle)
//returns a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is not part of str1.
//The matching process does not include the terminating null-characters, but it stops there.
{
	for (int n = 0; n < strlen(haystack); n++){
		if (haystack[n] == needle[0]){
			int k = n, m = 0;
			for (; m <= strlen(needle); m++,k++){
				if (haystack[k] != needle[m])
					break;
			}
			if (haystack[k] == needle[m]) {
				const char *ptr;
				ptr = & haystack[k];
				return (char*)ptr;
			}
		}
	}
	return (char*)'\0';
}

ostream & operator << (ostream & out, String str)
{
	str.print(out);
	return out;
}
istream & operator >> (istream & in, String & str)
{
	str.read(in);
	return in;
}
