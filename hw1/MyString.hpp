#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#include <iostream>
#include <fstream>
using namespace std;

class MyString
{

	char* buf; //points to the array holding the characters in this
                   //MyString object.
 	
	//T(N)=1001       
	void error(const char* s){
		cerr<<"Error: "<<s<<endl;
		throw 0;
	}
	
	char* strdup(const char* s) const;
	char* strcpy(char* dest, const  char* src) const;
	int strlen(const char* s) const;
	char* strstr(char* str1, const char* str2) const;
	int strcmp(const char* str1, const char* str2) const;
	char* str2dup(const char* str1, const char* str2) const;
	char* strcat(char* dest, const char* src) const;
	char* strrev(char* dest, const char* src) const;
	
public:
	explicit MyString(const char* s="");
	MyString(const MyString& s);
	MyString& operator=(const MyString& s);
	char& operator[](const int index);
	int length() const;
	int indexOf(char c) const;
	int indexOf(const MyString& pat) const;
	bool operator==(const MyString& s) const;
	MyString operator+(const MyString& s) const;
	MyString& operator+=(const MyString& s);
	MyString reverse() const;
	void print(ostream& out) const;
	void read(istream& in);
	~MyString();
};
#endif
