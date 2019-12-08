#include <iostream>

class Base {
	public:
	private:
	protected:
		int port_mem;
};


class Sneaky : public Base {
	friend void clobber(Sneaky&);
	friend void clobber(Base&);
	public:
		// test
		void print() { port_mem = 6; std::cout << port_mem << std::endl;}
	private:
		int j;

};


void clobber(Sneaky &s) {
	s.j = s.port_mem = 0;
}

//void clobber(Base &b)
//{
//	b.port_mem = 0;
//}

void test() {
	Sneaky s1;
	clobber(s1);
	s1.print();		
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
