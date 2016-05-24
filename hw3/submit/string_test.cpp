#include "String.h"

void test_constructor_and_print()
{
	cout << "=========testing constructor======== "<<endl
		 << "------String(const char *s = \"\")--------"<<endl;
	cout << "test 1: \n";

	String s1("Hello World");
	cout  <<  s1 << endl;
	cout << "test 2: ";
	String s2("Buffalo Jerky Sweet & Spicy");
	cout << s2 << endl;
	String s3;
	cout << "tset 3 " << s3<< endl;
	cout << "------String(const String & s)--------\n"
		 << "test 1: \n";
	String s4(s1);
	cout << s4 << endl;
	cout << "test 2: \n";
	String s5(s2);
	cout << s4 <<  endl;
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
	String s2("I still have writing assignment due tomorrow");
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

void test_size()
{
	cout << "=========testing size() ================" << endl;
	cout << "test 1: \n";
	String s1("Hello World");
	cout << s1 << " size: " << s1.size() << endl;

	cout << "test 2: \n";
	String s2("Life is so hard");
	cout << s2 << " size: " << s2.size() << endl;
}

void test_reverse()
{
	cout << "=========testing reverse() =============" << endl;
	cout << "test 1: \n";
	String s1("Hello World");
	cout << s1 << "\nReverse: " << s1.reverse() << endl;
	cout << "test 2: \n";
	String s2("Life is so hard");
	cout << s2 << "\nReverse: " << s2.reverse() << endl;
	
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
	cout << "------testing int indexOf(const String pattern)----" << endl;
	const String p1("ll");
	cout << "test 1: \n" << s1 << " index of pattern " << p1 << " is: " << s1.indexOf(p1)<< endl;
	const String p2("hard");
	cout << "test 2: \n" << s2 << " index of pattern " << p2 << " is: " << s2.indexOf(p2) << endl;
	const String p3("short");
	cout << "test 3: \n" << s2 << " index of pattern " << p3 << " is: " << s2.indexOf(p3) << endl;
	
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

void test_not_equal()
{
	cout << "========testing operator != ============" << endl;
	String s1("Hello World");
	String s2("Life is hard");
	String s3("Hello from the other side");

	cout << "test 1: \n" << s1 << " != " << s1 << " is " << (s1!=s1) << endl;
	cout << "test 2: \n" << s1 << " != " << s2 << " is " <<  (s1 != s2)  << endl;
	cout << "test 3: \n" << s1 << " != " << s3 << " is " << (s1 != s3) << endl;}

void test_bt()
{
	cout << "=========testing operator > =============" << endl;
	String s1("Hello World");
	String s2("Life is hard");
	String s3("Hello from the other side");

	cout << "test 1: \n" << s1 << " > " << s1 << " is " << (s1>s1) << endl;
	cout << "test 2: \n" << s1 << " > " << s2 << " is " << (s1>s2) << endl;
	cout << "test 3: \n" << s1 << " > " << s3 << " is " << (s1 >s3) << endl;
	cout << "test 4: \n" << s3 << " > " << s1 << " is " << (s3>s1) << endl;
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

void test_sq()
{
	cout << "=========testing operator <= =============" << endl;
	String s1("Hello World");
	String s2("Life is hard");
	String s3("Hello from the other side");

	cout << "test 1: \n" << s1 << " <= " << s1 << " is " << (s1<=s1) << endl;
	cout << "test 2: \n" << s1 << " <= " << s2 << " is " << (s1<=s2) << endl;
	cout << "test 3: \n" << s1 << " <= " << s3 << " is " << (s1<=s3) << endl;
	cout << "test 4: \n" << s3 << " <= " << s1 << " is " << (s3<=s1) << endl;
}

void test_bq()
{
	cout << "=========testing operator >= =============" << endl;
	String s1("Hello World");
	String s2("Life is hard");
	String s3("Hello from the other side");

	cout << "test 1: \n" << s1 << " >= " << s1 << " is " << (s1>=s1) << endl;
	cout << "test 2: \n" << s1 << " >= " << s2 << " is " << (s1>=s2) << endl;
	cout << "test 3: \n" << s1 << " >= " << s3 << " is " << (s1>=s3) << endl;
	cout << "test 4: \n" << s3 << " >= " << s1 << " is " << (s3>=s1) << endl;
}

void test_add()
{
	cout << "=========testing operator + =============" << endl;
	String s1("Hello World");
	String s2("Life is hard");
	String s3("Hello from the other side");

	cout << "test 1: \n" << s1 << "\n + \n" << s1 << "\n is \n" << (s1+s1)
		 << "s1 is " << s1 <<  endl;
	cout << "test 2: \n" << s1 << "\n + \n" << s2 << "\n is \n" << (s1+s2)
		 << "s1 is " << s1 <<  endl;
	cout << "test 3: \n" << s1 << "\n + \n" << s3 << " \n is \n" << (s1+s3)
		 << "s1 is " << s1 <<  endl;
	cout << "test 4: \n" << s3 << "\n + \n" << s1 << "\n is \n" << (s3+s1)
		<< "s3 is " << s3 <<  endl;
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



int main()
{
	test_constructor_and_print();
	cout << "==========end of constructor test==========="<< endl;
	test_operator_equal();
	cout << "==========end of operator = test============"<< endl;
	test_index();
	cout << "==========end of index test=================" << endl;
	test_size();
	cout << "==========end of size test==================" << endl;
	test_reverse();
	cout << "==========end of reverse test===============" << endl;
	test_indexOf();
	cout << "==========end of indexOf test===============" << endl;
	test_double_equal();
	cout << "==========end of == test====================" << endl;
	test_not_equal();
	cout << "==========end of != test====================" << endl;
	test_bt();
	cout << "==========end of > test=====================" << endl;
	test_st();
	cout << "==========end of < test=====================" << endl;
	test_sq();
	cout << "==========end of <= test=====================" << endl;
	test_bq();
	cout << "==========end of >= test=====================" << endl;
	test_add();
	cout << "==========end of + test=====================" << endl;
	test_add_equal();
	cout << "==========end of += test====================" << endl;
	
	return 0;
}
//g++ String.cpp string_test.cpp -o string_test 