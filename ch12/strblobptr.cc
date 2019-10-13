#include <iostream>
#include <chrono>
#include "strblob.h"

//auto p = std::make_shared<int>(42);
//std::weak_ptr<int> wp(p);



class StrBlobPtr
{
	public:
		friend bool operator == (const StrBlobPtr &lhs, const StrBlobPtr &rhs);
		friend bool operator != (const StrBlobPtr &lhs, const StrBlobPtr &rhs);
		StrBlobPtr(): curr(0) { }
		StrBlobPtr(StrBlob &a, size_t sz = 0):
			wptr(a.data), curr(sz) { }
		std::string& deref() const;
		StrBlobPtr& incr(); // 前缀递增
	private:
		// 若检查成功,check返回一个指向vector的shared_ptr
		std::shared_ptr<std::vector<std::string>>
			check(std::size_t, const std::string&) const;
		// 保存一个weak_ptr,意味着底层vector可能会被销毁
		std::weak_ptr<std::vector<std::string>> wptr;
		std::size_t curr;  // 在数组中的当前位置
};

// StrBlob 成员函数定义
StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	auto ret = StrBlobPtr(*this, data -> size());
	return ret;
}


std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
	auto ret = wptr.lock();  // vector还存在吗？
	if(!ret)
	{
		throw std::runtime_error("unbound StrBlobPtr");
	}

	if(i >= ret -> size())
	{
		throw std::out_of_range(msg); // 否则,返回指向vector的shared_ptr
	}
	return ret;
}

// deref成员调用check,检查使用vector是否安全以及curr是否在合法范围内
std::string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];  // (*p)是对象所指向的vector
}

// 前缀递增: 返回递增后的对象的引用
StrBlobPtr& StrBlobPtr::incr()
{
	// 如果curr已经指向容器的尾后位置,就不能递增它
	check(curr, "increment past end of StrBlobPtr");
	++curr;  // 推进当前位置
	return *this;
}

bool operator == (const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	auto l = lhs.wptr.lock();
	auto r = rhs.wptr.lock();

	if(l == r)
		return (!r || lhs.curr == rhs.curr);
	else
		return false;
}

bool operator != (const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs == rhs);
}

void testStrBlobPtr() {

	std::initializer_list<std::string> il{"hello", "world", "nice", "to"};
	StrBlob strblob1;
	StrBlob strblob2(il);
	strblob1 = strblob2;
	strblob2.push_back("meet");
	std::cout << strblob2.size() << std::endl;
	
	StrBlob strblob3 = strblob2;
	auto beg = strblob3.begin();
	auto end = strblob3.end();

	for(; beg != end; beg.incr())  // 注意是否定义了!=
	{
		std::cout << beg.deref() << " "; // error
	}
	std::cout << std::endl;
	//StrBlobPtr strblobptr(strblob);
}

int main(int argc,char *argv[]) {

	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	testStrBlobPtr();
		// TODO
	
	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
