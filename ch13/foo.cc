


class Foo
{
	public:
		Foo& operator=(const Foo &rhs) &;
		Foo sorted() &&;
		Foo sorted() const &;
	private:
		std::vector<int> data;
};


Foo Foo::sorted() &&
{
	std::sort(data.begin(), data.end());
	return *this;
}

Foo Foo::sorted() const &
{
	Foo ret(*this);
	std::sort(ret.data.begin(), ret.data.end());
	return ret;
}
