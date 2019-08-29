

#include <array>
#include <iostream>



int main(int argc,char *argv[])
{
	std::array<int,10> arr1 = {1,3,5,7,9,0};
	std::array<int,10> arr2 = arr1;
	/*
	typedef std::array<int,10>::size_type stype;
	for(stype i = 0;i < arr1.size();++i)
	{
		std::cout << arr1[i] << std::endl;
	}
	
	for(const auto &val : arr1)
	{
		std::cout << val << std::endl;
	}
	*/
	typedef std::array<int,10>::const_iterator citerator;
	citerator iter1 = arr2.cbegin();
	citerator iter2 = arr2.cend();
	for( ;iter1 != iter2;++iter1)
	{
		std::cout << *iter1 << std::endl;
	}
	//TODO
	return 0;
}
