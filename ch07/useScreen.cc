

#include "Screen.h"
#include "Window_mgr.h"
#include <chrono>
#include <iostream>

void test() {
	
	std::cout << "item1: " << std::endl;
	Screen item1(3, 4, 'c');
	std::cout << item1.get() << std::endl;
	std::cout << item1.get(0, 0) << std::endl;
	item1.set(1, 2, 'x');
	item1.move(2, 3);
	item1.some_member();
	item1.display(std::cout);
	std::cout << std::endl;

	std::cout << "item2: " <<  std::endl;
	Screen item2;
	item2.set(0, 0, 'v');
	item2.set('x');
	item2.move(1, 3);
	item2.some_member();
	item2.display(std::cout);

	// Window_mgr
	Window_mgr mgr;
	mgr.addScreen(item1);
	auto index = mgr.addScreen(item2);
	mgr.clear(index);
	std::cout << "item2: " << std::endl;
	item2.display(std::cout);

}


int main(int argc, char *argv[])
{
	using namespace std::chrono;
	auto beg = system_clock::now();

	test();
	
	auto end = system_clock::now();
	std::cout << "time: " << duration_cast<milliseconds> (end - beg).count() 
		      << " ms. "  << std::endl;
	return 0;
}
