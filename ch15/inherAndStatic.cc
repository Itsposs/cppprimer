#include <iostream>


class Base
{
	public:
		static void statmem();
};

void Base::statmem()
{

}

class Derived : public Base
{
	public:
		void f(const Derived&);
};


void f(const Derived &derived_obj)
{
	Base::statmem();
	Derived::statmem();
	derived_obj.statmem();
	//this -> statmem();
}


int main(int argc, char *argv[])
{
	return 0;
}
