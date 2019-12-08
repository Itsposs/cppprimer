#ifndef _STRVEC_H_
#define _STRVEC_H_


#include <memory>
#include <string>
#include <utility>


class StrVec
{
	public:
		StrVec() :
			elements(nullptr), first_free(nullptr), cap(nullptr) { }
		StrVec(std::initializer_list<std::string> il);
		StrVec(const StrVec&);
<<<<<<< HEAD
		StrVec(StrVec&&);
		StrVec& operator=(const StrVec&);
		StrVec& operator=(StrVec&&);
=======
		StrVec& operator=(const StrVec&);
>>>>>>> e2763e0a43fdee023e83410a284fa63d0cbb0459
		~StrVec();
		void push_back(const std::string&); // 拷贝元素
		size_t size() const { return first_free - elements; }
		size_t capacity() const { return cap - elements; }
		std::string *begin() const { return elements; }
		std::string *end() const { return first_free; }
	private:
		static std::allocator<std::string> alloc;  // 分配元素

		// 被添加元素的函数所使用
		void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	
		// 工具函数,被拷贝构造函数、赋值运算符和析构函数所使用
		std::pair<std::string*, std::string*> alloc_n_copy
			(const std::string*, const std::string*);
		void free();
		void reallocate(); // 获取更多的内存并拷贝已有元素
		std::string *elements; // 指向数组首元素的指针
		std::string *first_free; // 指向数组第一个空闲元素的指针
		std::string *cap;  // 指向数组尾后位置的指针
};





#endif // strvec.h

