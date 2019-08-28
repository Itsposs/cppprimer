

#include <memory>
#include <iostream>


int main(int argc, char *argv[])
{
	std::shared_ptr<int> sp1 = std::make_shared<int>(9);
	if(sp1.unique())
		std::cout << sp1.use_count() << std::endl;
	// *sp2 = &sp1 1
	std::shared_ptr<int> *sp2 = &sp1;
	std::cout << (*sp2).use_count() << std::endl;

	// sp3 = sp1 2
	std::shared_ptr<int> sp3 = sp1;
	std::cout << sp1.use_count() << std::endl;
	std::cout << sp3.use_count() << std::endl;
	
	//
	sp3.reset(new int(6));
	std::cout << sp3.use_count() << std::endl;
	return 0;
}
