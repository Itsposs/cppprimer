#include <iostream>
#include <chrono>
#include <string>

// HasPtr p1("Hiya!");
// HasPtr p2(p1);
// HasPtr p3(p1);



class HasPtr
{
	public:
		friend void print(std::ostream &os, HasPtr &p);
		// 构造函数分配新的string和新的计数器,将计数器置为1
		HasPtr(const std::string &s = std::string()):
			ps(new std::string(s)), i(0), use(new std::size_t(1)) { }
		// 拷贝构造函数拷贝所有三个数据成员,并递增计数器
		HasPtr(const HasPtr &p):ps(p.ps), i(p.i), use(p.use) { ++*use; }
		HasPtr& operator=(const HasPtr &rhs);
		HasPtr& operator=(const std::string &rhs);
		std::string& operator*() { return *ps; }
		~HasPtr();
	private:
		std::string *ps;
		int i;
		std::size_t *use;
};

void print(std::ostream &os, HasPtr &p)
{
	os << *p.ps << " " << p.i << " " << *p.use << std::endl;
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	++*rhs.use;  // 递增右侧运算对象的引用计数
	if(--*use == 0)
	{
		delete ps;
		delete use;
	}
	ps = rhs.ps;     // 将数据从rhs拷贝到本对象 
	i = rhs.i;
	use = rhs.use;
	return *this;    // 返回本对象
}

HasPtr& HasPtr::operator=(const std::string &rhs)
{	
	*ps = rhs;
	//*(this.ps) = rhs;
	return *this;
}

HasPtr::~HasPtr()
{
	if(--*use == 0)  // 如果引用计数变为0
	{
		delete ps;   // 释放string内存
		delete use;  // 释放计数器内存
	}
}

void testHasPtr()
{
	std::string s{"hello world!"};
	HasPtr ptr1(s);
	HasPtr ptr2 = ptr1;
	ptr1 = "hello c++";
	
	print(std::cout, ptr1);
	print(std::cout, ptr2);
	std::cout << *ptr1 << std::endl;
	std::cout << *ptr2 << std::endl;
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
