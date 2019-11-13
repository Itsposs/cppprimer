
#include <functional>
#include <type_traits>

#ifndef _LINQ_H_
#define _LINQ_H_

template <typename T>
class Task;

template <typename R, typename...Args>
class Task<R(Args...)> {
	public:
		Task(std::function<R(Args...)> &f) : func(f) {}
		Task(std::function<R(Args...)> &&f) : func(std::move(f)) {}

		template <typename... Args>
		R Run(Args&&... args) { return func(std::forward<Args>(args)...); }

		template <typename F> 
		auto Then(F &f) -> Task<typename std::result_of<F(R)>::type(Args...)> {
			using return_type = typename std::result_of<F(R)>::type;
			auto fn = std::move(func);

			return Task<return_type(Args...)>([fn, f](Args&&... args) {
					return f(fn(std::forward<Args>(args)...)); 
					});
		}
	private:
		std::function<R(Args...)> func;
};

#endif // linq.h
