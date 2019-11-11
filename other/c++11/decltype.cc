

class Foo {
	public:
		static const int Number = 0;
		int x;
	private:
};


void test() {
	int n = 0;
	volatile const int &x = n;

	decltype(n) a = n;
	decltype(x) b = n;

	decltype(Foo::Number) c = 0;
	Foo foo;
	decltype(foo.x) d = 0;
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
