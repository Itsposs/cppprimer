

#include <iostream>

union Token
{
	// 默认条件下成员是公有的
	char cval;
	int ival;
	double dval;
};

// anonymous union
union {
	char cval;
	int ival;
	double dval;
};

void test() {
	Token first_token = {'a'};
	std::cout << first_token.cval << std::endl;

	Token last_token;
	Token *pt = new Token;
	last_token.cval = 'z';
	std::cout << last_token.cval << std::endl;

	pt -> ival = 42;
	std::cout << pt -> ival << std::endl;
	delete pt;

	// anonymous union
	cval = 'c';
	ival = 42;
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
