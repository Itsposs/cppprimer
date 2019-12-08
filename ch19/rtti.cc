

class Base
{
		friend bool operator==(const Base&, const Base&);
	public:
		// Base的接口成员
	protected:
		virtual bool equal(const Base&) const;
		// Base的数据成员和其他用于实现的成员
};

class Derived : public Base
{
	public:
		// Derived的其他接口成员
	protected:
		bool equal(const Base&) const;
		// Derived的数据成员和其他用于实现的成员
};


bool operator==(const Base &lhs, const Base &rhs)
{
	// 如果typeid不相同,返回false;否则虚调用equal
	return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}


bool Derived::equal(const Base &rhs) const 
{
	// 我们清楚这两个类型是相等的,所以转换过程不会抛出异常
	auto r = dynamic_cast<const Derived&> (rhs);
	// 执行比较两个Derived对象的操作并返回结果
	
}

bool Base::equal(const Base &rhs)
{
	// 执行比较Base对象的操作
}


