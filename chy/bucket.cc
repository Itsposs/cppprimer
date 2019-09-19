

// 限制:
// 1.必须为整数
// 2.浪费空间

#include <vector>
#include <iostream>
#include <algorithm>

// v1
void Bucket(std::vector<int> &vec)
{
	// 元素最大值,eg：{1, 3, 5, 100}
	// vector<int> ret(101, 0);
	auto size = std::max_element(vec.begin(), vec.end());
	std::vector<int> ret(*size + 1, 0);
	typedef std::vector<int>::size_type size_type;
	
	for(size_type i = 0; i < vec.size(); ++i)  // 尽量++i
	{
		ret[vec[i]]++;
	}
	
	int k = 0;
	for(size_type i = 0; i < ret.size(); ++i)
	{
		for(size_type j = 1; j <= ret[i]; ++j)
		{
			//std::cout << j << " ";
			vec[k++] = i;
		}
	}
	//std::cout << std::endl;
}


int main(int argc, char *argv[])
{
	// test v1
	std::vector<int> vec1{1, 3, 5, 2, 9, 6, 4};
	Bucket(vec1);

	for(const auto v : vec1)
		std::cout << v << " ";
	std::cout << std::endl;

	return 0;
}
