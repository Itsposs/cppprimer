#include <iostream>
#include <vector>


typedef std::vector<int>::const_iterator citerator;

citerator find(citerator beg,citerator end,int target)
{
	for( ;beg != end;++beg)
	{
		if(*beg == target)
		{
			return beg;
		}
		
	}
	return end;
}


int main(int argc,char *argv[])
{
	std::vector<int> ivec = {1,3,5,7,9,11,5};
	citerator iter1 = ivec.begin();
	citerator iter2 = ivec.end();

	std::cout << *find(iter1,iter2,5) << std::endl;

	//TODO
	return 0;
}
