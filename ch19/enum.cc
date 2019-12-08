
#include <iostream>


void test() {
	// unscoped enumeration
	enum color {red, yellow, green};
	color eye = green;
	color hair = color::red;

	std::cout << "color => " << "eye: " << eye << " hair: "
						<< hair << std::endl;
	// scoped enumeration
	enum class peppers {red, yellow, green};
	peppers p = peppers::yellow;
	
	// error
	std::cout << "peppers => " << "p: " << p == peppers::yellow ? "1" : "0" 
						<< std::endl;
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
