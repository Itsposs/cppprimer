

template <typename T>
void f(T&& param);    // universal reference


template <typename T>
class Test {
	//...
	Test(Test &&rhs);    // rvalue reference

};

void f(Test &&param);  // rvalue reference


template <typename T>
void f(std::vector<T> &&param);  // rvalue reference


template <typename T>
void f(const T &&param); // rvalue reference


int w1, w2;
auto &&v1 = w1; // type inference, universal reference
decltype(w1) &&v2 = w2; // error std::move()
