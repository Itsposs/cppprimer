
#ifndef _ANY_H_
#define _ANY_H_

class Any {
	public:
		Any(void) : index(std::type_index(typeid(void))) {}
		Any(const Any &rhs) : ptr(rhs.Clone(), index(rhs.index)) {}
		Any(Any &&rhs) : ptr(std::move(rhs.ptr), index(rhs.index)) {}

	private:
		struct Base;
		typedef std::unique_ptr<Base> BasePtr;

		struct Base {
			public:
				virtual ~Base() {}
				virtual BasePtr Clone() const = 0;
		};

		template <typename T>
		struct Derived : public Base {
			public:
				template <typename U>
				Derived(U &&rhs) : value(std::forward<U>(value)) {}
				BasePtr Clone() const { return BasePtr(new Derived<T>(value)); }
				T value;
		};
		
		BasePtr Clone() const { 
			if (ptr != nullptr)
				return ptr -> Clone();
			return nullptr; 
		}
		BasePtr ptr;
		std::type_index index;
};

#endif // any.h
