

#include "Sales_data.h"
#include <iostream>

void test() {

	Sales_data item1("0-201-78345-X");
	Sales_data item2("0-201-78346-X", 6, 3.60);
	Sales_data item3(std::cin);
	std::cout << "item1: " << item1.isbn() << std::endl;
	std::cout << "item2: ";
	print(std::cout, item2) << std::endl;
	Sales_data item4 = item3;
	item3.combine(item4);
	std::cout << "item3: ";
	print(std::cout, item3) << std::endl;

	Sales_data item5 = add(item3, item4);
	std::cout << "item5: ";
	print(std::cout, item5) << std::endl;

}






int main(int argc, char *argv[]) {
	test();

	return 0;
}
