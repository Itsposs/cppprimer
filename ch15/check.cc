

struct Base {
	int memfcn();
};

struct Derived : Base {
	int memfcn(int);
};


void test() {
	Base b;
	Derived d;
	b.memfcn();
	d.memfcn(10);
	d.memfcn();
	d.Base::memfcn();
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
