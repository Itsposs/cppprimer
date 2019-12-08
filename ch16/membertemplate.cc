

#include <memory>
#include <string>
#include <iostream>


class DebugDelete {
	public:
		DebugDelete(std::ostream &s = std::cerr) :
			os(s) { }
		// 与任何函数模板相同,T的类型由编译器推断
		template <typename T> void operator()(T *p) const
		{ os << "deleting unique_ptr" << std::endl; delete p; }
	private:
		std::ostream &os;
};

void test() {
	double *dp = new double;
	DebugDelete()(dp);  // 可像delete表达式一样使用对象

	int *ip = new int;
	// 在一个临时DebugDelete对象上调用operator()(int*)
	DebugDelete()(ip);
	{
		std::unique_ptr<int, DebugDelete> p(new int, DebugDelete());
		std::unique_ptr<std::string, DebugDelete> sp(new std::string, DebugDelete());
	}
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
