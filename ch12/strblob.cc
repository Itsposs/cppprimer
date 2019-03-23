#include <iostream>
#include <chrono>
#include <memory>
#include <vector>
#include <string>
#include <initializer_list>
#include <stdexcept>


class StrBlob
{
	public:
		typedef std::vector<std::string>::size_type size_type;
		StrBlob();
		StrBlob(std::initializer_list<std::string> il);
		size_type size() const { return data -> size(); }
		bool empty() const { return data -> empty(); }
		
		// 添加和删除元素
		void push_back(const std::string &t) { data -> push_back(t); }
		void pop_back();
		
		// 元素访问
		std::string& front();
		std::string& back();
		
	private:
		std::shared_ptr<std::vector<std::string>> data;
		// 如果data[i]不合法,抛出一个异常
		void check(size_type i, const std::string &msg) const;
};

// 无参构造函数
StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }
// 有参函数
StrBlob::StrBlob(std::initializer_list<std::string> il) : 
	data(std::make_shared<std::vector<std::string>>(il)) { }

void StrBlob::check(size_type i, const std::string &msg) const
{
	if(i >= data -> size())
	{
		throw std::out_of_range(msg);
	}
}

std::string& StrBlob::front()
{
	// 如果vector为空,check会抛出一个异常
	check(0, "front on empty StrBlob");
	return data -> front();
}

std::string& StrBlob::back()
{
	check(0,"back on empty StrBlob");
	return data -> back();
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data -> pop_back();
}

void testStrBlob(StrBlob &str)
{
	// ok
	std::initializer_list<std::string> lstr{"hello","world","nice","to","meet","you"};
	StrBlob str1(lstr);
	int size = str1.size();
	

	if(!str1.empty())
	{
		std::cout << "size:" << size << std::endl;
		while(size)
		{
			std::cout << str1.back() << std::endl;
			str1.pop_back();
			size--;
		}
	}
	std::cout << std::endl;
}


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	
	StrBlob str1;
	testStrBlob(str1);

		// TODO
	
	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
