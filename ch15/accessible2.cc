

#include <iostream>

class Base {
	public:
		void pub_mem();
	protected:
    int prot_mem;
	private:
    char priv_mem;
};

struct Pub_Derv : public Base {
	int f() { return prot_mem; }
  //char g() { return priv_mem; }  // error
};

struct Priv_Derv : private Base {
	int f1() const { return prot_mem; }
};

struct Derived_from_Public : public Pub_Derv {
  int use_base() { return prot_mem; }
};

struct Derived_from_Private : public Priv_Derv {
	// private
	//int use_base() { return prot_mem; }  // error
};

void test() {
    Pub_Derv d1;
    Priv_Derv d2;
    d1.pub_mem();
//    d2.pub_mem();  // error
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
