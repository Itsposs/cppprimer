

#include <iostream>

int main(int argc, char *argv[])
{
	int j = 1;
	// 被捕获的变量是在lambda创建时拷贝,而不是调用时拷贝
	auto by_val_lambda = [=]{ return j + 1; };
	auto by_ref_lambda = [&]{ return j + 1; };
	auto print = [=] { std::cout << "print by val lambda: " 
		<< by_val_lambda() << ", ";
		std::cout << "by ref lambda: " << by_ref_lambda() <<  std::endl; };

	print();
	j += 10;
	print();

	return 0;
}
