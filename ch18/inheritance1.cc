

#include <iostream>

class Base {
	public:
		virtual void print() { std::cout << "Base" << std::endl; }
	private:
};

class Derive : public Base {
	public:
		void print() { std::cout << "Derive" << std::endl; }
	private:
};


void test() {
	Base *b1 = new Derive;
	b1 -> print();
	delete b1;
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
