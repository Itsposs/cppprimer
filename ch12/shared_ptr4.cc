

#include <memory>
#include <iostream>


int main(int argc, char *argv[])
{
	std::shared_ptr<int> spa = std::make_shared<int>(10);
	std::weak_ptr<int> spb = spa;
	if(!spb.expired())
		*spb.lock() += 10; // weak_ptr -> shared_ptr
	std::cout << *spa << std::endl;
	return 0;
}
