#ifndef _SPTR_H_
#define _SPTR_H_

template <typename T>
class Sptr
{
	public:
		Sptr() : p(nullptr), use(nullptr) { }
		explicit Sptr(T *pt) : p(pt), use(new size_t(1)) { }
		Sptr(const Sptr &rhs) : p(rhs.p), use(rhs.use)
			{ if (use) ++*use; }   // 拷贝构造函数
		Sptr& operator=(const Sptr&)
		~Sptr();
		T& operator*() { return *p; }
		T& operator*() const { return *p; }
	private:
		T *p;
		size_t *use;
};


#endif // sptr.h
