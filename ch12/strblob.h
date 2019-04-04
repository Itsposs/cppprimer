#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include <initializer_list>
#include <string>
#include <memory>
#include <vector>
#include <stdexcept>


class StrBlobPtr;

class StrBlob
{
	public:
		friend class StrBlobPtr;
		typedef std::vector<std::string>::size_type size_type;
		StrBlob();
		StrBlob(std::initializer_list<std::string> il);
		// 指向首元素和尾后元素的StrBlobPtr
		StrBlobPtr begin(); // { return StrBlobPtr(*this); }
		StrBlobPtr end();   // { auto ret = StrBlobPtr(*this, data -> size()); // 弱引用可以
			// return ret; }

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

#endif
