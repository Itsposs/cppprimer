

class Foo
{
	public:
		Foo sorted() &&;   // 可用于可改变的右值
		Foo sorted() const &;  // 可用于任何类型的Foo

		// Foo的其他成员定义
	private:
		std::vector<int> data;
};

// 本对象为右值,因此可以原址排序
Foo Foo::sorted() &&
{
	sort(data.begin(), data.end());
	return *this;
}

// 本对象是const或是一个左值,那种情况我们都不能对其原址排序
Foo Foo::sorted() const &
{
	Foo ret(*this);  // 拷贝一个副本
	sort(ret.data.begin(), ret.data.end()); // 排序副本
	return ret; // 返回副本
}


