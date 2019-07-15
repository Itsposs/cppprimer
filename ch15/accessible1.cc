#include <iostream>

class Base
{
	protected:
		int port_mem;
};


class Sneaky : public Base
{
	friend void clobber(Sneaky&);
	friend void clobber(Base&);
};


void clobber(Sneaky &s)
{
	s.j = s.port_mem = 0;
}

void clobber(Base &b)
{
	b.port_mem = 0;
}



int main(int argc, char *argv[])
{
	return 0;
}
