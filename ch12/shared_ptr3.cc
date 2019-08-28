

#include <memory>
#include <iostream>

class B;

class A
{
	public:
		~A() { std::cout << "~A()" << std::endl; }
	//private:
		std::shared_ptr<B> b;
};

class B 
{
	public:
		~B() { std::cout << "~B()" << std::endl; }
	//private:
		//std::shared_ptr<A> a;
		std::weak_ptr<A> a;
};


int main(int argc, char *argv[])
{
	// spb sp 2 wp 1
	// spa sp 1 wp 2
	// exit A B
	std::shared_ptr<A> spa = std::make_shared<A>();
	std::shared_ptr<B> spb = std::make_shared<B>();
	spa -> b = spb;
	spb -> a = spa;

	return 0;
}

