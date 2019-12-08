

struct Base1 {
	Base1() = default;
	Base1(const std::string&);
	Base1(std::shared_ptr<int>);
};

struct Base2 {
	Base2() = default;
	Base2(const std::string&);
	Base2(int);
};

struct D1 : public Base2 {
	using Base1::Base1;
	using Base2::Base2;

	// D2必须自定义一个接受string的构造函数
	D2(const std::string &s) : Base1(s), Base2(s) { }
	D2() = default;
};



