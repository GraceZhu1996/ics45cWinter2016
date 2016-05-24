
#include "String.h"

void test_constructor_and_print()
{
	cout << "=========testing constructor======== "<<endl
		 << "------String(const char *s = \"\")--------"<<endl;
	cout << "test 1: \n";

	String s1("Hello World");
	cout  <<  s1 << endl;
	cout << "test 2: ";
	String s2("Hello from the other side");
	cout << s2 << endl;
	String s3;
	cout << "test 3: " << s3<< endl;
	cout << "------String(const String & s)--------\n"
		 << "test 1: \n";
	String s4(s1);
	cout << s4 << endl;
	cout << "test 2: \n";
	String s5(s2);
	cout << s5 <<  endl;
}

void test_operator_equal()
{
	cout << "=========testing test_operator = (const String & s) =========\n"
		 <<"test 1: \n";
	String s1;
	const String & cs1("Hello World");
	cout << "String s1: " << s1 << endl;
	cout <<"const String & cs1 = " << cs1 << endl;
	cout << "s1 = cs1 "<<endl;
	s1 = cs1;
	cout << "s1: " << s1 << endl;
	cout << "test 2: \n";
	String s2("Life is so hard");
	const String & cs2("Hello from the other side");;
	cout << "String s2: " << s2 << endl;
	cout << "const String & cs2: " << cs2 << endl;
	cout << "s2 = cs2" << endl;
	s2 = cs2;
	cout << "s2: " << s2 << endl;
}

void test_index()
{
	cout << "========testing index operator========="<< endl
		 << "test 1: \n";
	String s1("Hello World");
	cout << "s1: " << s1 << endl
		 << "s1[4]: " << s1[4] << endl
		 << "when index bigger than len: \n s1[20]: " << s1[20] << endl;
	cout << "test 2: " << endl;
	String s2("Life is so hard");
	cout << "s2: " << s2 << endl
		 << "s2[3]: " << s2[3] << endl
		 << "when index bigger than len: \n s2[17]: " << s2[17] << endl;

}

void test_length()
{
	cout << "=========testing length() ================" << endl;
	cout << "test 1: \n";
	String s1("Hello World");
	cout << s1 << " length: " << s1.length() << endl;

	cout << "test 2: \n";
	String s2("Hello from the other side");
	cout << s2 << " length: " << s2.length() << endl;
}


void test_indexOf()
{
	cout << "========testing indexOf ================" << endl;
	cout << "------testing int indexOf(const char c)-------" << endl;
	String s1("Hello World");
	cout << "test 1: \n" << s1 << " index of o: " << s1.indexOf('o') << endl;
	String s2("Life is hard");
	cout << "test 2: \n" << s2 << " index of i: " << s2.indexOf('i') << endl;
	cout << "test 3: \n" << s2 << " index of k: " << s2.indexOf('k') << endl;
}

void test_double_equal()
{
	cout << "=========testing operator == ===========" << endl;
	String s1("Hello World");
	String s2("Life is hard");
	String s3("Hello from the other side");

	cout << "test 1: \n" << s1 << " == " << s1 << " is " << (s1==s1) << endl;
	cout << "test 2: \n" << s1 << " == " << s2 << " is " <<  (s1 == s2)  << endl;
	cout << "test 3: \n" << s1 << " == " << s3 << " is " << (s1 == s3) << endl;

}


void test_st()
{
	cout << "=========testing operator < =============" << endl;
	String s1("Hello World");
	String s2("Life is hard");
	String s3("Hello from the other side");

	cout << "test 1: \n" << s1 << " < " << s1 << " is " << (s1<s1) << endl;
	cout << "test 2: \n" << s1 << " < " << s2 << " is " << (s1<s2) << endl;
	cout << "test 3: \n" << s1 << " < " << s3 << " is " << (s1<s3) << endl;
	cout << "test 4: \n" << s3 << " < " << s1 << " is " << (s3<s1) << endl;

}




void test_add()
{
	cout << "=========testing operator + =============" << endl;
	String s1("Hello World");
	String s2("Life is hard");
	String s3("Hello from the other side");

	cout << "test 1: \n" << s1 << "\n + \n" << s1 << "\n is \n" << (s1+s1)
		 << "\ns1 is " << s1 <<  endl;
	cout << "test 2: \n" << s1 << "\n + \n" << s2 << "\n is \n" << (s1+s2)
		 << "\ns1 is " << s1 <<  endl;
	cout << "test 3: \n" << s1 << "\n + \n" << s3 << " \n is \n" << (s1+s3)
		 << "\ns1 is " << s1 <<  endl;
	cout << "test 4: \n" << s3 << "\n + \n" << s1 << "\n is \n" << (s3+s1)
		<< "\ns3 is " << s3 <<  endl;
}

void test_add_equal()
{
	cout << "=========testing operator += =============" << endl;
	String s1("Hello World");
	String s2("Life is hard");
	String s3("Hello from the other side");

	cout << "test 1: \n" << s1 << "\n += \n" << s1 << "\n is \n" << (s1+=s1)
		 << "\ns1 is " << s1 <<  endl;
	cout << "test 2: \n" << s1 << "\n += \n" << s2 << "\n is \n" << (s1+=s2)
		 << "\ns1 is " << s1 << endl;
	cout << "test 3: \n" << s1 << "\n += \n" << s3 << "\n is \n" << (s1+=s3)
		 << "\ns1 is " << s1 << endl;
	cout << "test 4: \n" << s3 << "\n += \n" << s1 << "\n is \n" << (s3+=s1)
		 << "\ns3 is " << s3 << endl;

}

void test_cin()
{

	cout << "=========testing cin ===================" << endl;
	String s1;
	cout << "Test 1: Enter a test string: ";
	cin >> s1;
	cout << s1 << endl;
	String s2;
	cout << "\nTest 2: Enter a test string: ";
	cin >> s2;
	cout << s2 << endl;
}


int main()
{

	test_constructor_and_print();

	cout << "==========end of constructor test==========="<< endl;
	test_operator_equal();
	cout << "==========end of operator = test============"<< endl;
	test_index();
	cout << "==========end of index test=================" << endl;
	test_length();
	cout << "==========end of length test==================" << endl;
	test_indexOf();
	cout << "==========end of indexOf test===============" << endl;
	test_double_equal();
	cout << "==========end of == test====================" << endl;
	test_st();
	cout << "==========end of < test=====================" << endl;
	test_add();
	cout << "==========end of + test=====================" << endl;
	test_add_equal();
	cout << "==========end of += test====================" << endl;
	test_cin();
	cout << "==========end of cin test===================" << endl;
	return 0;
}

//g++ -std=c++0x String.cpp my_main.cpp -o test
//valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./test



