#include <iostream>


template<typename T>
typename T::value_type top(const T &c)
{
	if (!c.empty())
		return c.back();
	else
		return typename T::value_type();
}




