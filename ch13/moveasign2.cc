

class HasPtr
{
	public:
		// 添加的移动构造函数
		HasPtr(HasPtr &&p) noexcept : 
			ps(p.ps), i(p.i), { p.ps = 0; }

		// 赋值运算符既是移动赋值运算符,也是拷贝赋值运算符
		HasPtr& operator=(HasPtr rhs)
			{ swap(*this, rhs); return *this; }
	private:
};
