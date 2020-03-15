
#include "observer.h"

void test() {
	Secretary *sc = new Secretary;
	StockObserver *st1 = new StockObserver("Tom", sc);
	StockObserver *st2 = new StockObserver("Jim", sc);

	sc -> Attach(st1);
	sc -> Attach(st2);
	
	std::string s{"Boss come here."};
	sc -> setStatus(s);

	sc -> Notify();

	delete sc;
	delete st1;
	delete st2;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
