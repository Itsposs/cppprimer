#include "string.h"


std::allocator<char> String::a;  // 定义静态allocator 成员

String& String::operator=(const String &rhs)
{
	char *newp = a.allocate(rhs.sz);
	std::uninitialized_copy(rhs.p, rhs.p + rhs.sz, newp);

	if(p)
		a.deallocate(p, sz);
	p = newp;
	sz = rhs.sz;

	return *this;
}

String& String::operator=(const char *cp)
{
	if(p)
		a.deallocate(p, sz);
	p = a.allocate(sz = strlen(cp));
	std::uninitialized_copy(cp, cp + sz, p);
	return *this;
}

String& String::operator=(char c)
{
	if(p)
		a.deallocate(p, sz);
	p = a.allocate(sz = 1);
	*p = c;
	return *this;
}

std::ostream &print(std::ostream &os, const String &s)
{
	const char *p = s.begin();
	while(p != s.end())
		os << *p++;
	return os;
}

String add(const String &lhs, const String &rhs)
{
	String ret;
	ret.sz = rhs.size() + lhs.size();
	ret.p = String::a.allocate(ret.sz);
	std::uninitialized_copy(lhs.begin(), lhs.end(), ret.p);
	std::uninitialized_copy(rhs.begin(), rhs.end(), ret.p + lhs.sz);
	return ret;
}

String make_plural(size_t ctr, const String &word, const String &ending)
{
	return (ctr != 1) ? add(word, ending) : word;
}

std::ostream &operator<<(std::ostream &os, const String &s)
{
	return print(os, s);
}

String operator+(const String &lhs, const String &rhs)
{
	return add(lhs, rhs);
}

void swap(String &s1, String &s2)
{
	s1.swap(s2);
}


