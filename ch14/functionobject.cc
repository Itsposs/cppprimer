#include <algorithm>
#include <iostream>
#include <vector>
#include <string>


class PrintString
{
	public:
		PrintString(std::ostream &o = std::cout, char c = ' ') :
			os(o), sep(c) { }
		void operator() (const std::string &s) const { os << s << sep; }
	private:
		std::ostream &os;
		char sep;
};


int main(int argc, char *argv[])
{
	std::vector<std::string> vs = {"hello", "world", "nice", "to", "meet"};
	std::for_each(vs.begin(), vs.end(), PrintString(std::cerr, '\n'));
	return 0;
}
