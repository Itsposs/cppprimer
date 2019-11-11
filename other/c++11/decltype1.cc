

class Foo {
	public:
		static const int Number = 0;
		int x;
	private:
};

int& func_int_r(void);
int&& func_int_rr(void);
int func_int(void);

const int& func_cint_r(void);
const int&& func_cint_rr(void);
const int func_cint(void);

const Foo func_cfoo(void);


void test() {
	int x = 0;

	decltype(func_int_r()) al = x;
	decltype(func_int_rr()) b1 = 0;
	decltype(func_int()) c1 = 0;

	decltype(func_cint_r()) a2 = x;
	decltype(func_cint_rr()) b2 = 0;
	decltype(func_cint()) c2 = 0;

	decltype(func_cfoo()) ff = Foo();
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
