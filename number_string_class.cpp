#include<string.h>
#include<iostream>

const int max = 3000;

class bign{
private:
	int len,s[max];
public:
	bign(){
		memset(s,0,sizeof(s);
		len = 1;
	}

	bign(int num){
		*this = num; // this will call operator=(int num)
	}

	bign(const char * m){
		*this = m;
	}
	
	bign operator=(const char * m){
		int n = strlen(m);
		for(int i = 0;i < n;i++)
			s[i] = m[n-i-1] - '0';
		return *this;
	}

	bign operator=(int num){
		char n[max];
		sprintf(n,"%d",num);
		*this = n // this will call the operator=(const char * m)
		return *this
	}

	string str() const{
		string str = "";
		for(int i = 0; i < len; i++)
			str = s[i] + '0';
		if(str == "") str = "0";
		return str;
	}

	bign operator+(int num){
		bign a = num;

	}

	bign operator+(bign & b){
		bign c;
		c.len = 0;
		for(int i = 0,carry = 0; carry || i < max(len,b.len);i++){
			int k = carry;
			if(i < len) k += s[i];
			if(i < b.len) k+= s[i];

			carry = (k >= 10) ? 1: 0;
			c.s[c.len++] = k%10;
		}
		return c;
	}
}

ostream & operator<<(ostream & os, bign & n){
	os << n.str();
	return os;
}


istream & operator<<(istream & is, bign & n){
	string s;
	is >> s;
	n = s.c_str();
	return os;
}