#include <iostream>
#include <chrono>
#include <string>

class HasPtr
{
	public:
		friend void print(std::ostream &os, HasPtr &s);
		HasPtr(const std::string &s = std::string()):
			ps(new std::string(s)), i(0) { }
		// 对ps指向的string,每个HasPtr对象都有自己的拷贝
		HasPtr(const HasPtr &p):
			ps(new std::string(*p.ps)), i(p.i) { }
		HasPtr& operator=(const HasPtr &);
		~HasPtr() { delete ps; }
		std::string& operator*() { return *ps; }  // 解引用
	private:
		std::string *ps;
		int i;
};

void print(std::ostream &os, HasPtr &s)
{
	os << *s.ps << " " << s.i << std::endl;
}


HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	auto newp = new std::string(*rhs.ps);  // 拷贝底层string
	delete ps;  // 释放旧内存
	ps = newp;
	i = rhs.i;
	return *this;  // 返回本对象
}

void testHasPtr()
{
	std::string s{"hello world!"};
	HasPtr ptr1(s);
	HasPtr ptr2 = ptr1;

	print(std::cout, ptr1);
	print(std::cout, ptr2);
}


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	testHasPtr();

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
