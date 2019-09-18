

// 限制:
// 1.必须为整数
// 2.浪费空间

#include <vector>
#include <iostream>

void Bucket(std::vector<int> &vec)
{
	// 元素最大值,eg：{1, 3, 5, 100}
	// vector<int> ret(101, 0);
	std::vector<int> ret(vec.size(), 0);
	typedef std::vector<int>::size_type size_type;
	
	for(size_type i = 0; i < vec.size(); ++i)  // 尽量++i
	{
		ret[vec[i]]++;
	}

	for(size_type j = ret.size() - 1; j > 0; --j)
	{
		for(size_type k = 1; k <= ret[i]; ++j)
		{
			std::cout << i << " ";
		}
	}
	std::cout <<  std::endl;

}

int main(int argc, char *argv[])
{
	return 0;
}
