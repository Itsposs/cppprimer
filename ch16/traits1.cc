
#include <cstring>
#include <iostream>


/*
template <typename T>

inline T sigma(const T *first, const T *last)
{
	T total = T();
	while(first != last)
	{
		total += *first;
		first++;
	}
	return total;
}

*/

template <typename T> class sigmatraits{ };

template <> class SigmaTraits<char>
{
	public:
		typedef int ReturnType;
};

template <> class SigmaTraits<short>
{
	public:
		typedef int ReturnType;
};

template <> class SigmaTraits<int>
{
	public:
		typedef long ReturnType;
};

template <> class SigmaTraits<unsigned int>
{
	public:
		typedef unsigned long ReturnType;
};

template <> class SigmaTraits<float>
{
	public:
		typedef double ReturnType;
};

template <typename T>
inline typename SigmaTraits<T>::ReturnType sigma(const T *first, const T *last)
{
	//using typename SigmaTraits<T>::ReturnType ReturnType;
	typedef typename SigmaTraits<T>::ReturnType ReturnType;
	ReturnType ret = ReturnType();
	while(first != last)
	{
		ret += *first;
		first++;
	}
	return ret;
}

int main(int argc, char *argv[])
{
	char szname[] = "abc";
	std::size_t nlength = strlen(szname);
	char *p = szname;
	char *q = szname + nlength;

	std::cout << "sigma(p, q):" << static_cast<int> (sigma(p, q)) << std::endl; 
	return 0;
}

