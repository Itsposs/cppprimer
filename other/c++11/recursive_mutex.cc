
#include <mutex>
#include <thread>

struct Complex {
	public:
		Complex() : i(0) {}
		void mul(int x) {
			std::lock_guard<std::recursive_mutex> lock(mutex);
			i *= x;
		}

		void div() {
			std::lock_guard<std::recursive_mutex> lock(mutex);
			i /= x;
		}

		void both(int x, int y) {
			std::lock_guard<std::recursive_mutex> lock(mutex);
			mul(x);
			div(y);
		}
		std::recursive_mutex mutex;
		int i;
};

void test() {
	Complex complex;
	complex.both(32, 23);
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
