#include <bits/stdc++.h>
using namespace std ;

const int maxn = 200;
class BigInteger
{
	friend istream& operator>>(istream&, BigInteger&);
	friend ostream& operator<<(ostream&, const BigInteger&);
	friend BigInteger operator+(const BigInteger&, const BigInteger&);
	friend BigInteger operator*(const BigInteger&, const BigInteger&);
	friend BigInteger operator*(const BigInteger&, int);
	friend BigInteger operator-(const BigInteger&, const BigInteger&);
	friend BigInteger operator/(const BigInteger&, const BigInteger&);
	friend BigInteger operator%(const BigInteger&, const BigInteger&);
	friend bool operator<(const BigInteger&, const BigInteger&);
	friend bool operator>(const BigInteger&, const BigInteger&);
	friend bool operator<=(const BigInteger&, const BigInteger&) ;
	friend bool operator>=(const BigInteger&, const BigInteger&);
	friend bool operator==(const BigInteger&, const BigInteger&);
	friend bool operator!=(const BigInteger&, const BigInteger&);
private:
	int len, s[maxn];
public:
	BigInteger() {
		memset(s, 0, sizeof(s));
		len = 1;
	}
	BigInteger operator=(const char* num) {
		int i = 0, ol;
		ol = len = strlen(num);
		while (num[i++] == '0' && len > 1)
			len--;
		memset(s, 0, sizeof(s));
		for (i = 0; i < len; i++)
			s[i] = num[ol - i - 1] - '0';
		return *this;
	}
	BigInteger operator=(int num) {
		char s[maxn];
		sprintf(s, "%d", num);
		*this = s;
		return *this;
	}
	BigInteger(int num) {
		*this = num;
	}
	BigInteger(const char* num) {
		*this = num;
	}
	string str() const {
		int i;
		string res = "";
		for (i = 0; i < len; i++)
			res = char(s[i] + '0') + res;
		if (res == "")
			res = "0";
		return res;
	}
};
bool operator<(const BigInteger& a, const BigInteger& b) {
	int i;
	if (a.len != b.len)
		return a.len < b.len;
	for (i = a.len - 1; i >= 0; i--)
		if (a.s[i] != b.s[i])
			return a.s[i] < b.s[i];
	return false;
}
bool operator>(const BigInteger& a, const BigInteger& b) {
	return b < a;
}
bool operator<=(const BigInteger& a, const BigInteger& b) {
	return !(a > b);
}
bool operator>=(const BigInteger& a, const BigInteger& b) {
	return !(a < b);
}
bool operator!=(const BigInteger& a, const BigInteger& b) {
	return a < b || a > b;
}
bool operator==(const BigInteger& a, const BigInteger& b) {
	return !(a < b || a > b);
}
BigInteger operator+(const BigInteger& a, const BigInteger& b) {
	int i, max = (a.len > b.len ? a.len : b.len), t, c;
	BigInteger sum;
	sum.len = 0;
	for (i = 0, c = 0; c || i < max; i++) {
		t = c;
		if (i < a.len)
			t += a.s[i];
		if (i < b.len)
			t += b.s[i];
		sum.s[sum.len++] = t % 10;
		c = t / 10;
	}
	return sum;
}
BigInteger operator*(const BigInteger& a, const BigInteger& b) {
	int i, j;
	BigInteger res;
	for (i = 0; i < a.len; i++) {
		for (j = 0; j < b.len; j++) {
			res.s[i + j] += (a.s[i] * b.s[j]);
			res.s[i + j + 1] += res.s[i + j] / 10;
			res.s[i + j] %= 10;
		}
	}
	res.len = a.len + b.len;
	while (res.s[res.len - 1] == 0 && res.len > 1)
		res.len--;
	if (res.s[res.len])
		res.len++;
	return res;
}
BigInteger operator*(const BigInteger& a, int b) {
	int i, t, c = 0;
	BigInteger res;
	for (i = 0; i < a.len; i++) {
		t = a.s[i] * b + c;
		res.s[i] = t % 10;
		c = t / 10;
	}
	res.len = a.len;
	while (c != 0) {
		res.s[i++] = c % 10;
		c /= 10;
		res.len++;
	}
	return res;
}
BigInteger operator-(const BigInteger& a, const BigInteger& b) {
	BigInteger res;
	int i, len = (a.len > b.len) ? a.len : b.len;
	for (i = 0; i < len; i++) {
		res.s[i] += a.s[i] - b.s[i];
		if (res.s[i] < 0) {
			res.s[i] += 10;
			res.s[i + 1]--;
		}
	}
	while (res.s[len - 1] == 0 && len > 1)
		len--;
	res.len = len;
	return res;
}
BigInteger operator/(const BigInteger& a, const BigInteger& b) {
	int i, len = a.len;
	BigInteger res, f;
	for (i = len - 1; i >= 0; i--) {
		f = f * 10;
		f.s[0] = a.s[i];
		while (f >= b) {
			f = f - b;
			res.s[i]++;
		}
	}
	while (res.s[len - 1] == 0 && len > 1)
		len--;
	res.len = len;
	return res;
}
BigInteger operator%(const BigInteger& a, const BigInteger& b) {
	int i, len = a.len;
	BigInteger res, f;
	for (i = len - 1; i >= 0; i--) {
		f = f * 10;
		f.s[0] = a.s[i];
		while (f >= b) {
			f = f - b;
			res.s[i]++;
		}
	}
	return f;
}
BigInteger& operator+=(BigInteger& a, const BigInteger& b) {
	a = a + b;
	return a;
}
BigInteger& operator-=(BigInteger& a, const BigInteger& b) {
	a = a - b;
	return a;
}
BigInteger& operator*=(BigInteger& a, const BigInteger& b) {
	a = a * b;
	return a;
}
BigInteger& operator/=(BigInteger& a, const BigInteger& b) {
	a = a / b;
	return a;
} /*可选前缀++/--与后缀++/--(注意:加法必选)*/
BigInteger& operator++(BigInteger& a) {
	a = a + 1;
	return a;
}
BigInteger& operator++(BigInteger& a, int) {
	BigInteger t = a;
	a = a + 1;
	return t;
}
BigInteger& operator--(BigInteger& a) {
	a = a - 1;
	return a;
}
BigInteger& operator--(BigInteger& a, int) {
	BigInteger t = a;
	a = a - 1;
	return t;
}
istream& operator>>(istream &in, BigInteger& x) {
	string s;
	in >> s;
	x = s.c_str();
	return in;
}
ostream& operator<<(ostream &out, const BigInteger& x) {
	out << x.str();
	return out;
}

int main()
{
	return 0 ;
}
