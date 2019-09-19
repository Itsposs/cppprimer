
#include <vector>
#include <iostream>


void Insert(std::vector<int> &vec)
{
	typedef std::vector<int>::size_type size_type;

	for(size_type i = 0; i < vec.size(); ++i)
	{
		for(int j = i; j > 0; j--)
		{
			if(vec[j] < vec[j - 1])
			{
				std::swap(vec[j], vec[j - 1]);
			}
		}
	}
}


typedef struct Node
{
	int val;
	struct Node *next;
}LNode;


void Insert(LNode *head)
{
	
}


int main(int argc, char *argv[])
{
	std::vector<int> vec1{6, 3, 1, 5, 12, 7, 4};
	Insert(vec1);

	for(const auto val : vec1)
		std::cout << val << " ";
	std::cout << std::endl;

	return 0;
}
