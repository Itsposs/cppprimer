
#include <new>
#include <iostream>

class Screen
{
	public:
		Screen(int x) : i(x) { }
		int get() { return i; }

		void* operator new(size_t);
		void  operator delete(void*, size_t);
		// ...

	private:
		Screen *next;
		static Screen *freeStore;
		static const int screenChunk;
	private:
		int i;
};

Screen* Screen::freeStore = nullptr;
const int Screen::screenChunk = 24;

void* Screen::operator new(size_t size)
{
	Screen *p;
	if(!freeStore)
	{
		// linked list是空的,所以申请一大块
		size_t chunk = screenChunk * size;
		freeStore = p = reinterpret_cast<Screen*>(new char[chunk]);
		// 将一大块分割片,当做linked list串接起来
		for(; p != &freeStore[screenChunk - 1]; ++p)
			p -> next = p + 1;
		p -> next = nullptr;
	}
	p = freeStore;
	freeStore = freeStore -> next;
	return p;
}

void Screen::operator delete(void *p, size_t)
{
	//将deleted object插回free list前端
	(static_cast<Screen*>(p)) -> next = freeStore;
	freeStore = static_cast<Screen*>(p);
}


int main(int argc, char *argv[])
{
	std::cout << sizeof(Screen) << std::endl;

	size_t const N = 100;
	Screen *p[N];

	for(int i = 0; i < N; ++i)
		p[i] = new Screen(i);

	// 输出前10个pointers,比较其间隔
	for(int i = 0; i < 10; ++i)
		std::cout << p[i] << std::endl;
	
	for(int i = 0; i < N; ++i)
		delete p[i];

	return 0;
}
