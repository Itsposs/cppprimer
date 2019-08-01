#include <iostream>
#include <new>


class MyInt
{
	public:
		MyInt() = default;
		~MyInt() { std::cout << "idata:" << idata << std::endl; }
		int idata;
	private:
};


class MyChar
{
	public:
		MyChar() = default;
		~MyChar() { std::cout << "cdata:" << cdata << std::endl; }
		char cdata;
	private:
};



int main(int argc, char *argv[])
{
	char *buffer = new char[sizeof(char) * 8];

	MyInt *iarray = new (buffer)MyInt;
	iarray[0].idata = 1;
	iarray[1].idata = 2;
	std::cout << iarray[0].idata << std::endl;

	for(int i = 0; i < 2; ++i)
		iarray[i].~MyInt();
	
	MyChar *carray = new(buffer)MyChar;
	carray[0].cdata = 'a';
	carray[1].cdata = 'b';
	carray[2].cdata = 'c';
	carray[3].cdata = 'd';
	std::cout << carray[3].cdata << std::endl;

	for(int i = 0; i < 4; ++i)
		carray[i].~MyChar();

	delete[] buffer;
	
	return 0;
}
