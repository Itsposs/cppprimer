
#include <map>
#include <string>
#include <utility>
#include <iostream>

void  test() {
	std::map<std::string, std::string> m;
	// uses pair's move constructor
	m.emplace(std::make_pair(std::string("a"), std::string("a")));    
	// uses pair's converting move constructor
	m.emplace(std::make_pair("b", "abcd"));          
  // uses pair's template constructor
	m.emplace("d", "ddd");                    
	// uses pair's piecewise constructor
	m.emplace(std::piecewise_construct, std::forward_as_tuple("c"), std::forward_as_tuple(10, 'c'));
  // as of C++17, m.try_emplace("c", 10, 'c'); can be used
		                                                             
	for (const auto &p : m) {
		std::cout << p.first << " => " << p.second << '\n';
	}
}

int main(int argc, char *argv[]) {
	
	test();
	return 0;
}
