
class Foo
{
	public:
		Foo &operator=(const Foo&) &; // 只能向可修改的左值赋值
		// Foo的其它操作
		
	private:
};


Foo &Foo::operator=(const Foo &rhs) &
{
	// 执行将rhs赋予本对象所需的工作
	return *this;
}



