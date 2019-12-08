

#include <memory>
#include <iostream>


struct connection  {};
struct destination {};

connection connect(destination *pd) {
	std::cout << "open connection" << std::endl;
	return connection();
}

void disconnect(connection c) {
	std::cout << "close connection" << std::endl;
}

// unused shared_ptr
void f(destination &d) {
	std::cout << "directly manage connection" << std::endl;
	connection c = connect(&d);
	// forget to close connection
	std::cout << std::endl;
}

void end_connection(connection *p) { disconnect(*p); }

// use shared_ptr
void f1(destination &d) {
	std::cout << "use shared_ptr manage connection" << std::endl;
	connection c = connect(&d);
	
	std::shared_ptr<connection> p(&c, end_connection);

	// forget to close connection
	std::cout << std::endl;
}

void test() {
	destination d;
	f(d);
	f1(d);
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}

