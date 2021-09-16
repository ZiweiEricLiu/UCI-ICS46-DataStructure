#ifndef HASHER_HPP
#define HASHER_HPP

#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

struct Hasher{
	virtual int hash(string s, int N) = 0;
};

struct GeneralStringHasher : Hasher{
	//O(N) N represents the size of the string
	int hash(string s, int N){
		const unsigned shift = 6;
		const unsigned zero = 0;
		unsigned mask = ~zero >> (32-shift);
		unsigned result = 0;
		int ssize = s.size();
		int len = min(ssize, 6);
		for(int i=0; i<len; i++){
			result = (result << shift) | (s[i] & mask);
		}
		return result % N;	
	}
};

struct SumHasher : Hasher{
	int hash(string s, int N){
		int result = 0;
		int ssize = s.size();
		for(int i=0; i<ssize; ++i){
			result += s[i];
		}
		return abs(result) % N;
	}
};

struct ProdHasher : Hasher{
	int hash(string s, int N){
		int result = 1;
		int ssize = s.size();
		for(int i=0; i<ssize; ++i){
			result *= s[i];
		}
		return abs(result) % N;
	}
};

#endif
