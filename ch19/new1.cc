
class Foo
{
	public:
		void* operator new(size_t);
		void  operator delete(void *, size_t);
		// ...
};


int main(int argc, char *argv[])
{
	Foo *p = new Foo; // 1

	// ...


	delete p;   // 2

	return 0;
}


// 1
try
{
	void *mem = operator new(sizeof(Foo));
	p = static_cast<Foo*>(mem);
	p -> Foo::Foo(1, 2);
}

// 2
p -> ~Foo();
operator delete(p);


