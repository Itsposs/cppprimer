#include <iostream>

enum class intTypes : unsigned long long
{
	charTyp = 8,
	shortTyp = 16,
	intTyp = 16,
	longTyp = 32,
	long_longTyp = 64

};

enum color {red, yellow, green};
enum class peppers {red, yellow, green};

int main(int argc, char *argv[])
{
	
	constexpr intTypes charbits = intTypes::charTyp;
	int i = color::red;
	int j = peppers::red;

	return 0;
}
