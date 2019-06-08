#include <iostream>
#include <stdexcept>

class SmallInt
{
	public:
		SmallInt(int i = 0) : val(i)
		{
			if(i < 0 || i > 256)
				throw std::out_of_range("Bad SmallInt value");
		}
		operator int() const { return val; }
	private:
		std::size_t val;
};



int main(int argc, char *argv[])
{
	SmallInt si;
	si = 4;
	si + 3;

	return 0;
}
