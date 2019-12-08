

#include <memory>
#include <iostream>


int main(int argc, char *argv[])
{
	std::unique_ptr<int[]> array(new int[10]);
	
	return 0;
}
