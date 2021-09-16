#include "MyString.hpp"

//Since there is no input in test function, I will specify the N for every function

//N represents the size of str here
//T(N)=2
inline ostream& operator<<(ostream& out, const MyString& str){
	str.print(out);
	return out;
}

//N represents the size of str here
//T(N)=6N+3007
inline istream& operator>>(istream& in, MyString& str){
	str.read(in);
	return in;
}

//N represents the size of l here
//T(N)=1
MyString copyConstructorTest(MyString l){
	return l;
}

//N represents the size of the input.txt here
//T(N)=31N+9057
void testReverse(){
	cout << "\n--------Testing Reverse and Copy Constructor--------"<<endl;
	cout << "--------This Test Also Test the Print and Read--------"<<endl;
	ifstream in("input.txt");
	MyString l;

	while(in>>l)
	{
		cout << copyConstructorTest(l)
		<<" "<<l.length()<<" "
		<<l.reverse()<<endl;
	}
}

//N represents the size of the string
//T(N)=6N+3006
void constructorTest(){
	cout << "\n--------Testing Constructor--------" << endl; 
	MyString string = MyString("Sucessfully Construct a String");
	cout << string << endl;
}

//N represents the size of str1, M represents the size of str2
//T(N,M)=6N+12M+7021
void assignmentOperatorTest(){
	cout << "\n--------Testing Assignment Operator--------"<<endl;
	MyString str1 = MyString("Old String");
	cout << "Assign the String with Another String..." << endl;
	MyString str2 = MyString("Sucessfully Assign");
	str1 = str2;
	cout << str1 << endl;
}

//N represents the size of string
//T(N)=12N+6022
void bracketOperatorTest(){
	cout<<"\n--------Testing Bracket Operator--------"<<endl;
	MyString string = MyString("abcdef");
	cout << "Expected: a Actual: " << string[0] << endl;
	cout << "Expected: d Actual: " << string[3] << endl;
	//cout << "Expected: Index Out of Bound Actual:" << endl;
	//string[6];
}

//N represents the size of string, M represents the size of s
//T(N,M)=9N+9M+5018
void lengthTest(){
	cout<<"\n--------Testing Length--------"<<endl;
	MyString string = MyString("abcdef");
	cout <<"Expected: 6 Actual: "<<string.length()<<endl;
	MyString s;
	cout <<"Expected: 0 Actual: "<<s.length()<<endl;
}

//N represents the size of string
//T(N)=22N+4016
void indexOfCharTest(){
	cout<<"\n--------Testing IndexOfChar--------"<<endl;
	MyString string = MyString("abcdef");
	cout <<"Expected: 2 Actual: "<<string.indexOf('c')<<endl;
	cout <<"Expected: -1 Actual: "<<string.indexOf('o')<<endl;
}

//N represents the size of string
//T(N)=122N+7340
void indexOfPatTest(){
	cout<<"\n--------Testing IndexOfPat--------"<<endl;
	MyString string = MyString("abcdef");
	cout <<"Expected: 3 Actual: "<<string.indexOf(MyString("def"))<<endl;
	cout <<"Expected: -1 Actual: "<<string.indexOf(MyString("op"))<<endl;
}

//N represents the size of str1, M represents the size of str2, P represents the size of str3
//T(N,M,P)=14N+6M+6P+6032
void doubleEqualOperatorTest(){
	cout<<"\n--------Testing == Operator--------"<<endl;
	MyString str1 = MyString("abc");
	MyString str2 = MyString("abc");
	MyString str3 = MyString("def");
	bool a = (str1==str2);
	bool b = (str1==str3);
	cout<<"Comparing the same string(expected true): "<<boolalpha<<a<<endl;
	cout<<"Comparing different string(expected false): "<<boolalpha<<b<<endl; 
}

//N represents the size of str1, M represents the size of str2
//T(N,M)=19N+28M+11040
void plusOperatorTest(){
	cout<<"\n--------Testing + Operator--------"<<endl;
	MyString str1 = MyString("First Part ");
	cout<<"str1 = "<<str1<<endl;
	MyString str2 = MyString("Second Part");
	cout<<"str2 = "<<str2<<endl;
	MyString str3 = str1+str2;
	cout<<"Adding them together to a third string: "<<str3<<endl;
}

//N represents the size of str1, M represents the size of str2
//T(N,M)=23N+6M+8025
void plusEqualOperatorTest(){
	cout<<"\n--------Testing += Operator--------"<<endl;
	MyString str1 = MyString("First Part ");
	cout<<"str1 = "<<str1<<endl;
	MyString str2 = MyString("Second Part");
	cout<<"str2 = "<<str2<<endl;
	str1+=str2;
	cout<<"Adding them together the first string become: "<<str1<<endl;
}

//N represents the size of str
//T(N)=6N+6006
void readTest(){
	cout<<"\n--------Testing Read--------"<<endl;
	cout<<"Please Type a Line to Construct a String: ";
	MyString str;
	cin >> str;
	cout<<"The String You Construct is: "<<str<<endl;
}

int main(){
	try{
		testReverse();
		constructorTest();
		assignmentOperatorTest();
		bracketOperatorTest();
		lengthTest();
		indexOfCharTest();
		indexOfPatTest();
		doubleEqualOperatorTest();
		plusOperatorTest();
		plusEqualOperatorTest();
		readTest();
	}
	catch(int i){
		cout<<"Got an exception: "<<i<<endl;
	}
	return 0;
}
