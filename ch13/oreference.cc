#include <iostream>
#include <chrono>
#include <vector>


class Foo
{
	public:
		Foo sorted() &&;
		Foo sorted() const &;

	private:
		std::vector<int> data;
};


Foo Foo::sorted() &&
{
	std::sort(data.begin(), data.end());
	return *this;
}

Foo Foo::sorted() const &
{
	Foo ret(*this);
	std::sort(ret.data.begin(), ret.data.end());
	return ret;
}


int main(int argc,char *argv[])
{
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();

	// TODO

	auto end = high_resolution_clock::now();
	std::cout << "time:" << duration_cast<milliseconds> (end - begin).count()
			  << "ms." << std::endl;
	return 0;
}
