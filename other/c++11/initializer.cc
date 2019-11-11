

class Foo {
	public:
		Foo(int) {}
	private:
		Foo(const Foo&);
};


void test1() {
	Foo a1(123);
	//Foo a2 = 123; // error
	
	Foo a3 = { 123 };
	Foo a4 { 123 };

	int a5 = { 3 };
	int a6 { 3 };
}

void test2() {
	int *a = new int { 123 };
	double b = double { 12.12 };
	int *arry = new int[3] { 1, 2, 3};
}



void test() {
	test1();
	test2();
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
