
#include <memory>
#include <iostream>


class DebugDelete
{
	public:
		DebugDelete(std::ostream &s = std::cerr) :
			os(s) { }
		// 与任何函数模板相同,T的类型由编译器推断
		template <typename T>
		void operator() (T *p) const
		{ os << "deleting unique_ptr" << std::endl; delete p; }
	private:
		std::ostream &os;
};


int main(int argc, char *argv[])
{
	double *p1 = new double;
	DebugDelete d;
	d(p1);  // 调用DebugDelete::operator()(double*),释放p

	int *ip = new int;
	// 在一个临时DebugDelete对象上调用operator()(int*)
	DebugDelete()(ip);
	
	// 实例化DebugDelete::operator()<int>(int *)
	std::unique_ptr<int, DebugDelete> p2(new int, DebugDelete());
	// 实例化DebugDelete::operator()<string>(string *)
	std::unique_ptr<std::string, DebugDelete> sp(new std::string, DebugDelete());

	return 0;
}
