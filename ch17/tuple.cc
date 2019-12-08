
#include <list>
#include <tuple>
#include <vector>
#include <string>
#include <iostream>



int main(int argc, char *argv[])
{
	std::tuple<std::string, std::vector<double>, int, std::list<int>>
		val("constants", {3.14, 2.718}, 42, {0, 1, 2, 3, 4, 5});
	
	//auto item  = std::make_tuple("0-999-78345-X", 3, 20.00);
	//auto book  = std::get<0>(item);
	//auto cnt   = std::get<1>(item);
	//auto price = std::get<2>(item);

	typedef decltype(item) trans;
	// 返回trans类型对象中成员的数量
	size_t sz = std::tuple_size<trans>::value;
	// cnt的类型与item中第二个成员相同
	std::tuple_element<1, trans>::type cnt = std::get<1>(item);
	return 0;
}
