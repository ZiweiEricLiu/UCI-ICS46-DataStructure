#include "MyString.hpp"

//N represents the first argument, M represents the second argument in the helper functions

//T(N)=6N+1005
char* MyString::strdup(const char* s) const{
	return strcpy(new char[strlen(s)+1],s);
}

//T(N)=3N+2
char* MyString::strcpy(char* dest, const char* src) const{
	char* d = dest;
	while((*d++ = *src++));
	return dest;
}

//T(N)=3N+2
int MyString::strlen(const char* s) const{
	int len = 0;
	for(;s[len] != '\0';len++);
	return len;
}

//T(N,M)=3N*M^2+13N*M+6N-3M^3-10M^2+13M+12
char* MyString::strstr(char* str1, const char* str2) const{
	int str2Len = strlen(str2);
	int strDif = strlen(str1)-str2Len;
	for(int i=0; i<=strDif;i++){
		for(int j=0; j<str2Len;j++){
			if(str1[i+j]!=str2[j]){
				break;
			}
			if(j==strlen(str2)-1){
				return &str1[i];
			}
		}
	}
	return nullptr;
}

//T(N)=4N+4
int MyString::strcmp(const char* str1, const char* str2) const{
	const unsigned char* p1 = (const unsigned char*) str1;
	const unsigned char* p2 = (const unsigned char*) str2;
	while(*p1 && (*p1 == *p2)){
		p1++;
		p2++;
	}
	return (*p1 - *p2);
}

//T(N,M)=7N+10M+1010
char* MyString::str2dup(const char* str1, const char* str2) const{
	return strcat(strcpy(new char[strlen(str1)+strlen(str2)+1],str1),str2);
}

//T(N,M)=N+3M+2
char* MyString::strcat(char* dest, const char* src) const{
	char* d = dest;
	for(;*d;d++);
	while((*d++=*src++));
	return dest;
}

//T(M)=10M+5
char* MyString::strrev(char* dest, const char* src) const{
	int length = strlen(src);
	for(int i=0; i<length; i++){
		dest[i] = src[length-i-1];
	}
	return dest;
}

//The N represents the size of the buf in the method functions

//T(N)=6N+1006
MyString::MyString(const char* s)
	: buf{strdup(s)}
{	
}

//T(N)=6N+1006
MyString::MyString(const MyString& s)
	: buf{strdup(s.buf)}
{
}

//M represents the size of s.buf
//T(M)=6M+2009
MyString& MyString::operator=(const MyString& s){
	if(this != &s){
		char* newbuf = strdup(s.buf);
		delete[] buf;
		buf = newbuf;
	}
	
	return *this;
}

//T(N)=3N+1008
char& MyString::operator[](const int index){
	if(index >=  strlen(buf) || index<0){
		error("Index Out Of Bounds");
	}
	return buf[index];
}

//T(N)=3N+3
int MyString::length() const{
	return strlen(buf);
}

//T(N)=8N+5
int MyString::indexOf(char c) const{
	int index = 0;
	int len=length();
	for(; index<len; index++){
		if(buf[index]==c){
			return index;
		}
	}
	return -1;
}

//M represents the size of pat.buf here, N still represents the size of buf
//T(N,M)=3N*M^2+13N*M+6N+3M^3+10M^2+13M+17
int MyString::indexOf(const MyString& pat) const{
	char* patPtr = strstr(buf, pat.buf);
	if(patPtr != nullptr){
		return patPtr - buf;
	}
	return -1;	
}

//T(N)=4N+6
bool MyString::operator==(const MyString& s) const{
	if(strcmp(buf, s.buf) == 0){
		return true;
	}
	else{
		return false;
	}
}

//M represents the size of pat.buf here, N still represents the size of buf
//T(N,M)=7N+16M+3019
MyString MyString::operator+(const MyString& s) const
{
	char* newString = str2dup(buf, s.buf);
	MyString newStr = MyString(newString);
	delete[] newString;
	return newStr;
}

//T(N)=17N+2013
MyString& MyString::operator+=(const MyString& s){
	char* newbuf = str2dup(buf, s.buf);
	delete[] buf;
	buf = newbuf;
	return *this;
}

//T(N)=22N+3019
MyString MyString::reverse() const{
	char* revString = strdup(buf);
	MyString revStr =  MyString(strrev(revString, buf));
	delete[] revString;
	return revStr;
}

//T(N)=1
void MyString::print(ostream& out) const{
	out << buf;
}

//T(N)=6N+3006
void MyString::read(istream& in){
	char local[1024];
	in.getline(local,1024);
	delete[] buf;
	buf = strdup(local);
} 

//T(N)=1000
MyString::~MyString(){
	delete[] buf;
}

	
