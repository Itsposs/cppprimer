#include "sptr.h"

template <typename T>
Sptr<T>::~Sptr()
{
	if (use && --*use == 0)
	{
		// 如果引用计数变为0
		delete p;    // 释放对象内存
		delete use;  // 释放计数器内存
	}
}

template <typename T>
Sptr<T>& Sptr<T>::operator=(const Sptr<T> &rhs)
{
	if (rhs.use)
		++*rhs.use;      // 递增右侧运算对象的引用计数
	
	if (use && --*use == 0)
	{
		// 递减本对象引用计数
		delete p;
		delete use;
	}

	p = rhs.p;
	use = rhs.use;
	return *this;
}

template <typename T, class... Args>
Sptr<T> make_sptr(Args&&... args)
{
	return Sptr<T>(new T(std::forward<Args>(args)...));
}


