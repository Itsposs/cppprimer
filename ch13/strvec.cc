#include "strvec.h"



std::allocator<std::string> StrVec::alloc;

StrVec::StrVec(std::initializer_list<std::string> il)
{
	// 调用alloc_n_copy分配与列表il中元素数目一样多的空间
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

void StrVec::push_back(const std::string &s)
{
	chk_n_alloc(); // 确保有空间容纳新元素
	
	// 在first_free指向的元素中构造s的副本
	alloc.construct(first_free, s);
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
	// 分配空间保存给定范围中的元素
	auto data = alloc.allocate(e - b);
	
	// 初始化并返回一个pair,该pair由data和uninitialized_copy的返回值构成
	return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
	// 不能传递给deallocate一个空指针,如果elements为0,函数什么也不做
	if (elements)
	{
		// 逆序销毁旧元素
		for (auto p = first_free; p != elements; )
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(const StrVec &s)
{
	// 调用alloc_n_copy分配空间以容纳s中一样多的元素
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec &&s) noexcept
	: elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec::~StrVec() { free(); }

StrVec& StrVec::operator=(const StrVec &rhs)
{
	// 调用alloc_n_copy分配内存,大小与rhs中元素占用空间一样多
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept
{
	if (this != &rhs)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;

		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

void StrVec::reallocate()
{
	// 我们将分配当前大小两倍的内存空间
	auto newcapacity = size() ? 2 * size() : 1;

	// 分配新内存
	auto newdata = alloc.allocate(newcapacity);

	// 将数据从旧内存移动到新内存
	auto dest = newdata;   // 指向新数组中下一个空闲位置
	auto elem = elements;

	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));  // 调用string的移动构造函数
	free();  // 释放旧内存空间

	// 更新我们的数据结构,执行新元素
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}


