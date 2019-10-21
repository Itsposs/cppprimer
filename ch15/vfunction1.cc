

class Base {
	public:
		virtual int fcn();
};

class D1 : public Base {
	public:
		int fcn(int);
		virtual void f2();
};


class D2 : public D1 {
	public:
		int fcn(int);
		int fcn();
		void f2();
};


void test() {
	Base bobj;
	D1 d1obj;
	D2 d2obj;

	Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
	bp1 -> fcn();
	bp2 -> fcn();
	bp3 -> fcn();

	D1 *d1p = &d1obj;
	D2 *d2p = &d2obj;
	bp2 -> f2();
	d1p -> f2();
	d2p -> f2();
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
