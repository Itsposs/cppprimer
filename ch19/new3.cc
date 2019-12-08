#include <new>
#include <iostream>

class Airplane
{
	private:
		struct AirplaneRep
		{
			unsigned long miles;
			char type;
		};
	private:
		union{
			AirplaneRep rep;
			AirplaneRep *next;
		};
	public:
		unsigned long getMiles() { return rep.miles; }
		char getType() { return rep.type; }
		void set(unsigned long m, char t){
			rep.miles = m;
			rep.type = t;
		}
	public:
		static void* operator new(size_t size);
		static void  operator delete(void* deadObject, size_t size);
	private:
		static const int BLOCK_SIZE;
		static Airplane *headOfFreeList;
};

Airplane* Airplane::headOfFreeList;
const int Airplane::BLOCK_SIZE = 512;

void* Airplane::operator new(size_t size)
{
	// 怎会有误？当继承发生时
	// 如果大小有误,转交给::operator new()
	if(size != sizeof(Airplane))
		return ::operator new(size);

	Airplane *p = headOfFreeList;
	if(p) // 如果p有效,就把list头部下移一个元素
		headOfFreeList = p -> next;
	else
	{
		// free list已空,申请(分配)一大块
		Airplane *newBlock = static_cast<Airplane*>
			(::operator new(BLOCK_SIZE * sizeof(Airplane)));

		// 将小块串成一个free list
		// 但跳过#0,因它将被传回做为本次成果
		for(int i = 1; i < BLOCK_SIZE - 1; ++i)
			newBlock[i].next = &newBlock[i + 1];
		newBlock[BLOCK_SIZE].next = nullptr;  // 结束list
		p = newBlock;
		headOfFreeList = &newBlock[1];
	}
	return p;
}

// operator delete接受一个内存快
// 如果大小正确,就把它加到free list前端
void Airplane::operator delete(void *deadObject, size_t size)
{
	if(deadObject == nullptr)
		return;
	if(size != sizeof(Airplane))
	{
		::operator delete(deadObject);
		return;
	}

	Airplane *carcass = static_cast<Airplane*>(deadObject);

	carcass -> next = headOfFreeList;
	headOfFreeList = carcass;
}


int main(int argc, char *argv[])
{
	std::cout << sizeof(Airplane) << std::endl;
	size_t const N = 100;
	Airplane *p[N];

	for(int i = 0; i < N; ++i)
		p[i] = new Airplane;
	
	// 随机测试object正常否
	p[1] -> set(1000, 'A');
	p[5] -> set(2000, 'B');
	p[9] -> set(500000, 'C');


	// 随机测试前10个pointers
	// 用以比较其间隔
	for(int i = 0; i < 10; ++i)
		std::cout << p[i] << std::endl;
	
	for(int i = 0; i < N; ++i)
		delete p[i];
	return 0;
}
