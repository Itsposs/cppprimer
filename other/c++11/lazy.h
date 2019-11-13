
#ifndef _LAZY_H_
#define _LAZY_H_

#include "optional.h"
#include <functional>

template <typename T>
struct Lazy {
	public:
		Lazy() {}

		template <typename Func, typename... Args>
		Lazy(Func &f, Args &&... args) { 
			func = [&f, &args...]{ return f(args...); };
		}

		T& Value() {
			if (!value.isInit()) {
				value = func();
			}
			return *value;
		}

		bool IsValueCreate() const { return value.isInit(); }
	private:
		Optional<T> value;
		std::function<T()> func;
};

template <typename Func, typename... Args>
Lazy<typename std::result_of<Func(Args...)>::type>
	lazy(Func &&func, Args &&... args) {
		return Lazy<typename std::result_of<Func(Args...)>::type>(std::forward<Func>(func), 
				std::forward<Args>(args)...);
}

#endif // lazy.h
