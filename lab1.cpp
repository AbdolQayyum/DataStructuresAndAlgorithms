#include <iostream>
#include <string>
using namespace std;

int addition (int a, int b)
{
int r;
r=a+b;
return r;
}

int foo [] = {16, 2, 77, 40, 12071};
int n, result=0;

int main(){
	
	//=========== Activity 1 ==============
	
//	cout<<"Hello World!";
	
	//=========== Activity 2 ==============
		
//	float a=5.5; 
//	int b(3); 
//	int c{2}; 
//	float result; 
//
//	a = a + b;
//	result = a - c;
	
	//=========== Activity 3 ==============
	

//	int x,y;
//	int result;
//	cout << "Enter numbers" << endl;
//	cin >> x;
//	cin >> y;
//	result = x * y;
//	cout << "Result =" << result << endl;


	//=========== Activity 4 ==============
	
//	string mystring;
//	mystring = "This is the initial string content";
//	cout << mystring << endl;
//	mystring = "This is a different string content";
//	cout << mystring << endl;

	//=========== Activity 5 ==============
	
//	int a, b=3;
//	a = b;
//	a+=2; 
//	cout << a;

	//=========== Activity 6 ==============


//	int a,b,c;
//
//	a=2;
//	b=7;
//	c = (a>b) ? a : b;
//	cout << c << '\n';

	//=========== Activity 7 ==============
	
//	int x;
//	cin>>x;
//	if (x > 0)
//	cout << "x is positive";
//	else if (x < 0)
//	cout << "x is negative";
//	else
//	cout << "x is 0";

//=========== Activity 8 ==============
	
//	int n = 10;
//
//	while (n>0) {
//	cout << n << ", ";
//	--n;
//	}
//
//	cout << "liftoff!\n";

//=========== Activity 9 ==============
	
//	string str;
//	do {
//	cout << "Enter text: ";
//	getline (cin,str);
//	cout << "You entered: " << str << '\n';
//	} while (str != "goodbye");

//=========== Activity 10 ==============

//int day = 4;
//switch (day) {
//case 1:
//cout << "Monday";
//break;
//case 2:
//cout << "Tuesday";
//break;
//case 3:
//cout << "Wednesday";
//break;
//case 4:
//cout << "Thursday";
//break;
//case 5:
//cout << "Friday";
//break;
//case 6:
//cout << "Saturday";
//break;
//case 7:
//cout << "Sunday";
//break;
//default:
//cout<<"Enter valid day";
//}


//=========== Activity 11 ==============

//	int z;
//	z = addition (5,3);
//	cout << "The result is " << z;
	
//=========== Activity 12 ==============

	for ( n=0 ; n<5 ; ++n )
	{
	result += foo[n];
	}
	cout << result;
	
	
return 0;
}
