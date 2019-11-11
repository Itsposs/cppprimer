

template <typename R, typename T, typename U>
R add(T t, U u) {
	return t + u;
}

template <typename T, typename U>
decltype(t + u) add(T t, U u) { // error
	return t + u;
}

template <typename T, typename U>
decltype(T() + U()) add(T t, U u) { // constr
	return t + u;
}

template <typename T, typename U>
decltype((*(T*)0) + (*(U*)0)) add(T t, U u) {
	return t + u;
}

template <typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
	return t + u;
}


void test() {
	int a = 1;
	float b = 2.0;
	auto c = add<decltype(a + b)>(a, b);
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}
