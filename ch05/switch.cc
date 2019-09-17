
#include <iostream>


int main(int argc, char *argv[])
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0,
		uCnt = 0;

	char ch;
	while(std::cin >> ch)
	{
		switch(ch)
		{
			case 'a':
				++aCnt;
				break;
			case 'e':
				++eCnt；
				break;
			case 'i':
				++iCnt;
				break;

			case 'o':
				++oCnt;
				break;

			case 'u':
				++uCnt;
				break;
		}
	}


	return 0;
}
