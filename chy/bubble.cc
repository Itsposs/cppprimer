
#include <vector>
#include <iostream>
#include <algorithm>


void Bubble(std::vector<int> &vec)
{
	typedef std::vector<int>::size_type size_type;

	for(size_type i = 0; i < vec.size(); ++i)
	{
		bool sorted = true;
		for(size_type j = 0; j < vec.size() - 1; ++j)
		{
			if(vec[j] > vec[j + 1])
			{
				sorted = false;
				std::swap(vec[j], vec[j + 1]);
			}
		}
		if(sorted)
		{
			break;
		}
	}
}


int main(int argc, char *argv[])
{
	std::vector<int> vec1{8, 2, 4, 9, 12, 1};
	Bubble(vec1);

	std::for_each(vec1.begin(), vec1.end(), [](int val) { std::cout << val << " "; });
	std::cout << std::endl;

	return 0;
}
