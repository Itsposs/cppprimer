
#include <string>
#include "optional.h"

struct MyStruct {
	public:
		MyStruct() {}
		MyStruct(int a, int b) 
			: m_a(a), m_b(b) {}
		int m_a;
		int m_b;
};

void test() {
	Optional<std::string> a("ok");
	Optional<std::string> b("ok");
	Optional<std::string> c("aa");
	c = a;

	Optional<MyStruct> op;
	op.emplace(1, 2);
	MyStruct t;
	if (op)
		t = *op;
	op.emplace(3, 4);
	t = *op;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
