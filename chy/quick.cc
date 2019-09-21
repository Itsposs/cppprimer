
#include <chrono>
#include <vector>
#include <iostream>
#include <algorithm>

struct Ways
{
	int pointer;
	int hole;
};


// pointer exchange
int partition(std::vector<int> &vec, int left, int right)
{
	int pivot = vec[left];   // element of base
	int i = left;
	int j = right;

	while(i != j)
	{
		// right
		while(i < j && vec[j] >= pivot) j--;
		while(i < j && vec[i] <= pivot) i++;
		if(i < j)
			std::swap(vec[i], vec[j]);
	}
	// std::swap(vec[i], pivot);
	vec[left] = vec[i];
	vec[i]    = pivot;

	return i;
}



// v1 
void quick(std::vector<int> &vec, int left, int right)
{
	if(left >= right)
		return;

	int i = partition(vec, left, right);
	quick(vec, left, i - 1);
	quick(vec, i + 1, right);
}

// dig holes
int partition(std::vector<int> &vec, int left, int right)
{
	int i = left;
	int j = right;

	int index = left;
	int pivot = vec[left];

	while(i <= j)
	{
		while(i <= j)
		{
			if(vec[j] < pivot)
			{
				vec[i] = vec[j];
				index = j;
				i++;
				break;
			}
			j--;
		}

		while(i <= j)
		{
			if(vec[i] > pivot)
			{
				vec[j] = vec[i];
				index = i;
				j--;
				break;
			}
			i++;
		}
	}
	vec[index] = pivot;
	return index;
}

void test_quick()
{
	std::vector<int> vec1{8, 2, 4, 9, 21, 24};
	quick(vec1, 0, 5);
	for(const auto val : vec1)
		std::cout << val << " ";
	std::cout << std::endl;
}



int main(int argc, char *argv[])
{
	using namespace std::chrono;
	//auto beg = high_resolution_clock::now();
	auto beg = system_clock::now();
	
	test_quick();


	//auto end = high_resolution_clock::now();
	auto end = system_clock::now();
	std::cout << "time: " << std::chrono::duration_cast<milliseconds> (end - beg).count()
			  << " ms." << std::endl;

	
	return 0;
}
