

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, int>::type
foo1(T t) {
	std::cout << t << std::endl;
	//return 0;
}


template <typename T>
typename std::enable_if<!std::is_arithmetic<T>::value, int>::type
foo1(T &t) {
	std::cout << typeid(T).name() << std::endl;
	//return 1;
}



