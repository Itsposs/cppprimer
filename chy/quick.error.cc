
#include <vector>
#include <iostream>
#include <algorithm>

// v1 
void Quick(std::vector<int> &vec, int left, int right)
{
	int base = vec[left];
	right = vec.size() - 1;
	int i = left, j = right;
	while(i != j)
	{
		while(vec[j] >= base && i < j) j--;
		while(vec[i] <= base && i < j) i++;
		if(i < j)
		{
			std::swap(vec[i], vec[j]);
		}
	}
	//std::swap(vec[i], base);
	vec[left] = vec[i];
	vec[i] = base;

	Quick(vec, left, i - 1);
	Quick(vec, i + 1, right);
}


int main(int argc, char *argv[])
{
	std::vector<int> vec1{8, 2, 4, 9, 21, 24};
	Quick(vec1, 0, 6);
	for(const auto val : vec1)
		std::cout << val << " ";
	std::cout << std::endl;

	return 0;
}
