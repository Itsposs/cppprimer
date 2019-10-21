

class Base { };
class D : public Base {
	public:
		D(const D& d) : Base(d) { }
		D(D&& d) : Base(std::move(d)) { }
		D& operator=(const D& rhs);
		~D();
};


