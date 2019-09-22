

#include "Sales_data.h"


int main(int argc, char *argv[])
{
	Sales_data total;
	if (read(std::cin, total)) {

		Sales_data trans;
		while (read(std::cin, trans)) {

			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
				
			} else {
				
				print(std::cout, total) << std::endl;
				total = trans;
			}
		}
		print(std::cout, total) << std::endl;
	} else {

		std::cerr << "No what?!" << std::endl;
	}

	return 0;
}
