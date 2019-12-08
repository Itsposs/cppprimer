#include <iostream>
#include <type_traits>


template<typename It>
auto fcn(It beg, It end) -> decltype(*beg)
{
	// 处理序列
	return *beg;  // 返回序列中一个元素的引用
}


template<typename It>
auto fcn2(It beg, It end) ->
	typename remove_reference<decltype(*beg)>::type
{
	// 处理序列
	return *beg;
}
