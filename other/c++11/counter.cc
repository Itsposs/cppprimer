
struct Counter {
	public:
		void increment() {
			std::lock_guard<std::mutex> lock(mutex);
			++value;
		}

		void decrement() {
			std::lock_guard<std::mutex> lock(mutex);
			--value;
		}

		int get() const { return value; }

		int value;
		std::mutex mutex;
	private:
};


#include <atomic>

struct AtomicCounter {
	public:
		void increment() { ++value; }
		void decrement() { --value; }
		int get() const  { return value.load(); }
		std::atomic<int> value;
	private:
};


