

#include <type_traits>

//template <typename T> 
//T* Create() {
//	return new T();
//}


//template <typename T>
//typename std::remove_cv<typename 
//	std::remove_reference<T>::type>::type* Create() {
//	typedef typename std::remove_cv<typename 
//		std::remove_reference<T>::type>::type U;
//	return new U();
//}


template <typename T>
typename std::decay<T>::type* Create() {
	typedef typename std::decay<T>::type U;
	return new U();
}


void test() {
	int *p = Create<const volatile int&>();
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
