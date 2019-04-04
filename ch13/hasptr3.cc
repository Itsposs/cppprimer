#include <iostream>
#include <chrono>
#include <string>

class HasPtr
{
	public:
		friend void swap(HasPtr&, HasPtr&);
		// 构造函数分配新的string和新的计数器,将计数器置为1
		HasPtr(const std::string &s = std::string()):
			ps(new std::string(s)), i(0), use(new std::size_t(1)) { }
		// 拷贝构造函数拷贝所有三个数据成员,并递增计数器
		HasPtr(const HasPtr &p):ps(p.ps), i(p.i), use(p.use) { ++*use; }
		HasPtr& operator=(const HasPtr&);
		HasPtr& operator=(const std::string&);
		std::string& operator*() { return *ps; }
		~HasPtr();
	private:
		std::string *ps;
		int i;
		std::size_t *use;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);  // 交换指针,而不是string数据
	swap(lhs.i, rhs.i);
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

HasPtr& HasPtr::operator=(const std::string &s)
{
	*ps = s;
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
	HasPtr p1("hi mom!");
	HasPtr p2(p1);
	HasPtr p3 = p1;
	p2 = "hi dad!";
	p3 = "hi mom!";
	swap(p2,p3);
	
	std::cout << "p1:" << *p1 << std::endl;
	std::cout << "p2:" << *p2 << std::endl;
	std::cout << "p3:" << *p3 << std::endl;

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
