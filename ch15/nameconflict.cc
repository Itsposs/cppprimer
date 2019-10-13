
#include <iostream>


struct Base {
	public:
		Base() : mem(0) { }
	private:
	protected:
		int mem;
};

struct Derived : public Base {
	public:
		Derived(int i) : mem(i) { }
		int get_mem() { return mem; }
		int get_base_mem() { return Base::mem; }
	private:
	protected:
		int mem;
};


void test() {
	Derived d(42);
	std::cout << d.get_mem() << std::endl;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
