

class Base {
	friend class Pal;
	public:
	protected:
		int port_mem;
};

class Sneaky : public Base {
	friend void clobber(Sneaky&);
	friend void clobber(Base&);
	int j;
};

class Pal {
	public:
		int f(Base b) { return b.port_mem; }
		//int f2(Sneaky s) { return s.j; }  // error
		//base class subobject
		int f3(Sneaky s) { return s.port_mem; }
	private:
};

class D2 : public Pal {
	public:
		//int mem(Base b) { return b.port_mem; }  // error
};

int main(int argc, char *argv[]) {
	return 0;
}
